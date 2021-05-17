
%{
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "listaSimbolos.h"

Lista tablaSimbolos;
Tipo tipo;

int contadorCadenas=1;
int contadorEtiquetas=1;

int errores_sintacticos = 0;
int errores_semanticos = 0;
extern int errores_lexicos;

char registros[10] = {0};

void yyerror();
void nuevaEntrada();
void imprimirTablas();
void imprimirCodigo();
int perteneceTablaS();
int esConstante();
int ok();
void liberarReg();
char *obtenerReg();
char *concatena();
char * concatena2();
char *obtenerEtiqueta();

extern int yylex();
extern int yylineno;
%}

%code requires {
	#include "listaCodigo.h"
}

/*  Definicion de tipos semanticos */

%union{
    char *cadena;
    ListaC codigo;
}

%type <codigo> expression statement_list statement print_list print_item read_list declarations identifier_list asig

/*Definicion de tokens */

%token VOID VAR READ PRINT CONST IF ELSE WHILE LPAREN RPAREN SEMICOLON COMMA ASSIGNOP LCOR RCOR
%token <cadena> STRING ID INTLITERAL

/* Flags de funcionamiento de Bison */

%define parse.error verbose //genera mensajes de error extensos
%define parse.trace // Activar trazas con yydebug=1

/* Asociatividad y precedencia de operadores */

%left PLUSOP MINUSOP
%left POR BARRAOP
%left UMINUS

/* Hay un conflicto desplaza/reduce en if-else */
%expect 1

%%

/*Reglas de produccion */
program : {tablaSimbolos = creaLS();}
 	VOID ID LPAREN RPAREN LCOR declarations statement_list RCOR {
																	if (ok()) {
                                    imprimirTablas();
																		concatenaLC($7,$8);
		  															imprimirCodigo($7);
                                  }
                                	else printf("errores lexicos: %d, errores sintacticos: %d, errores semanticos: %d\n", errores_lexicos, errores_sintacticos, errores_semanticos);
                                  	liberaLS(tablaSimbolos);
																		liberaLC($7);
																	}
	;

declarations : declarations VAR {tipo = VARIABLE;} identifier_list SEMICOLON
																	{$$=$1;
																	concatenaLC($$,$4);
																	liberaLC($4);}
	| declarations CONST {tipo = CONSTANTE;} identifier_list SEMICOLON
																	{$$=$1;
																	concatenaLC($$,$4);
																	liberaLC($4);}

	| 																{$$=creaLC();}
	;

identifier_list : asig												{$$=$1;}

	| identifier_list COMMA asig									{$$=$1;
																	concatenaLC($$,$3);
																	liberaLC($3);}
	;

asig : ID															{if (!perteneceTablaS($1)) nuevaEntrada($1, tipo);
																	else{ printf("Linea %d: Variable %s ya declarada \n", yylineno, $1); errores_semanticos++;}

																	$$=creaLC();}

	| ID ASSIGNOP expression										{if (!perteneceTablaS($1)) nuevaEntrada($1, tipo);
																	else{ printf("Linea %d: Variable %s ya declarada \n", yylineno, $1); errores_semanticos++;}

																	$$=$3;
				    												Operacion oper;
				    												oper.op = "sw";
				    												oper.res = recuperaResLC($3);
				    												oper.arg1 = concatena("_",$1);
				    												oper.arg2 = NULL;
				    												insertaLC($$,finalLC($$),oper);
				    												liberarReg(oper.res);
																	}
	;

statement_list : statement_list statement							{$$=$1;
																	concatenaLC($$,$2);}

	|																{$$=creaLC();}
	;

statement : ID ASSIGNOP expression SEMICOLON						{if (!perteneceTablaS($1)){ printf("Linea %d: Variable %s no declarada \n", yylineno, $1); errores_semanticos++;}
																	else if (esConstante($1)){ printf("Linea %d: Asignacion a constante \n", yylineno); errores_semanticos++;}

																	$$=$3;
				    												Operacion oper;
				    												oper.op = "sw";
				    												oper.res = recuperaResLC($3);
				    												oper.arg1 = concatena("_",$1);
				    												oper.arg2 = NULL;
				    												insertaLC($$,finalLC($$),oper);
				    												liberarReg(oper.res);
																	}

	| LCOR statement_list RCOR										{$$=$2;}

	| IF LPAREN expression RPAREN statement ELSE statement			{$$=$3;
																	char *etiq = obtenerEtiqueta();
																	char *etiq1 = obtenerEtiqueta();
																	Operacion oper;
																	oper.op = "beqz";
																	oper.res = recuperaResLC($3);
																	oper.arg1 = etiq;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	concatenaLC($$,$5);
																	liberaLC($5);

																	oper.op ="b";
																	oper.res = etiq1;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);

																	oper.op = "etiq";
																	oper.res = etiq;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	concatenaLC($$,$7);
																	liberaLC($7);

																	oper.op = "etiq";
																	oper.res = etiq1;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	liberarReg(recuperaResLC($3));
							    									}

	| IF LPAREN expression RPAREN statement							{$$=$3;
																	char *etiq = obtenerEtiqueta();
																	Operacion oper;
																	oper.op = "beqz";
																	oper.res = recuperaResLC($3);
																	oper.arg1 = etiq;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	concatenaLC($$,$5);
																	liberaLC($5);

																	oper.op = "etiq";
																	oper.res = etiq;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	liberarReg(recuperaResLC($3));
																	}

	| WHILE LPAREN expression RPAREN statement						{$$=creaLC();
																	char *etiq = obtenerEtiqueta();
																	char *etiq1 = obtenerEtiqueta();
																	Operacion oper;
																	oper.op = "etiq";
																	oper.res = etiq;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	concatenaLC($$, $3);

																	oper.op = "beqz";
																	oper.res = recuperaResLC($3);
																	oper.arg1 = etiq1;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	concatenaLC($$,$5);

																	oper.op = "b";
																	oper.res = etiq;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);

																	oper.op = "etiq";
																	oper.res = etiq1;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;
																	insertaLC($$,finalLC($$),oper);
																	liberarReg(recuperaResLC($3));
					     											}

	| PRINT print_list SEMICOLON									{$$=$2;}

	| READ read_list SEMICOLON										{$$=$2;}
	;

print_list : print_item												{$$=$1;}

	| print_list COMMA print_item									{$$=$1;
					 												concatenaLC($$,$3);
					 												liberaLC($3);}
	;

print_item : expression												{$$=$1;
																	Operacion oper;
																	oper.op = "move";
																	oper.res = "$a0";
																	oper.arg1 = recuperaResLC($1);
																	oper.arg2 = NULL;

			  														insertaLC($$,finalLC($$),oper);

																	oper.op = "li";
			  														oper.res = "$v0";
			  														oper.arg1 = "1";
			  														oper.arg2 = NULL;

			  														insertaLC($$,finalLC($$),oper);

			  														oper.op = "syscall";
			  														oper.res = NULL;
			  														oper.arg1 = NULL;
			  														oper.arg2 = NULL;

			  														insertaLC($$,finalLC($$),oper);
			  														liberarReg(recuperaResLC($1));
																	}

	| STRING														{nuevaEntrada($1, CADENA);

																	$$ = creaLC();

																	Operacion oper;
																	oper.op = "la";
																	oper.res = "$a0";
																	oper.arg1 = concatena2("$str",contadorCadenas-1);
																	oper.arg2 = NULL;

																	insertaLC($$,finalLC($$),oper);

																	oper.op = "li";
																	oper.res = "$v0";
																	oper.arg1 = "4";
																	oper.arg2 = NULL;

																	insertaLC($$,finalLC($$),oper);

																	oper.op = "syscall";
																	oper.res = NULL;
																	oper.arg1 = NULL;
																	oper.arg2 = NULL;

																	insertaLC($$,finalLC($$),oper);
																	}
	;

read_list : ID 														{if (!perteneceTablaS($1)){ printf("Linea %d: Variable %s no declarada \n", yylineno, $1); errores_semanticos++;}
																	else if (esConstante($1)){ printf("Linea %d: Asignacion a constante \n", yylineno); errores_semanticos++;}

																	$$=creaLC();
		    														Operacion oper;
		    														oper.op = "li";
		    														oper.res = "$v0";
		    														oper.arg1 = "5";
		    														oper.arg2 = NULL;

		    														insertaLC($$,finalLC($$),oper);

		    														oper.op = "syscall";
		    														oper.res = NULL;
		    														oper.arg1 = NULL;
		    														oper.arg2 = NULL;

		    														insertaLC($$,finalLC($$),oper);

		    														oper.op = "sw";
		    														oper.res = "$v0";
		    														oper.arg1 = concatena("_",$1);
		    														oper.arg2 = NULL;

		    														insertaLC($$,finalLC($$),oper);
																	}

	| read_list COMMA ID											{if (!perteneceTablaS($3)){ printf("Linea %d: Variable %s no declarada \n", yylineno, $3); errores_semanticos++;}
																	else if (esConstante($3)){ printf("Linea %d: Asignacion a constante \n", yylineno);errores_semanticos++;}

																	$$=$1;
				  													Operacion oper;
				  													oper.op = "li";
				  													oper.res = "$v0";
				  													oper.arg1 = "5";
				  													oper.arg2 = NULL;

				  													insertaLC($$,finalLC($$),oper);

				  													oper.op = "syscall";
				  													oper.res = NULL;
				  													oper.arg1 = NULL;
				  													oper.arg2 = NULL;

				  													insertaLC($$,finalLC($$),oper);

				  													oper.op = "sw";
				  													oper.res = "$v0";
				  													oper.arg1 = concatena("_",$3);
				  													oper.arg2 = NULL;

				  													insertaLC($$,finalLC($$),oper);
																	}
	;

expression : expression PLUSOP expression                           {$$=$1;
					                                                concatenaLC($$,$3);
					                                                Operacion oper;
					                                                oper.op = "add";
					                                                oper.res = obtenerReg();
					                                                oper.arg1 = recuperaResLC($1);
					                                                oper.arg2 = recuperaResLC($3);
					                                                insertaLC($$,finalLC($$),oper);
					                                                liberaLC($3);
																													guardaResLC($$,oper.res);
																													liberarReg(oper.arg1);
					                                                liberarReg(oper.arg2);}

	| expression MINUSOP expression                                 {$$=$1;
					                                                concatenaLC($$,$3);
					                                                Operacion oper;
					                                                oper.op = "sub";
					                                                oper.res = obtenerReg();
					                                                oper.arg1 = recuperaResLC($1);
					                                                oper.arg2 = recuperaResLC($3);
					                                                insertaLC($$,finalLC($$),oper);
					                                                liberaLC($3);
																													guardaResLC($$,oper.res);
																													liberarReg(oper.arg1);
					                                                liberarReg(oper.arg2);}

	| expression POR expression                                     {$$=$1;
					                                                concatenaLC($$,$3);
					                                                Operacion oper;
					                                                oper.op = "mul";
					                                                oper.res = obtenerReg();
					                                                oper.arg1 = recuperaResLC($1);
					                                                oper.arg2 = recuperaResLC($3);
					                                                insertaLC($$,finalLC($$),oper);
					                                                liberaLC($3);
																	guardaResLC($$,oper.res);
																	liberarReg(oper.arg1);
					                                                liberarReg(oper.arg2);}

	| expression BARRAOP expression                                 {$$=$1;
					                                                concatenaLC($$,$3);
					                                                Operacion oper;
					                                                oper.op = "div";
					                                                oper.res = obtenerReg();
					                                                oper.arg1 = recuperaResLC($1);
                                                                    oper.arg2 = recuperaResLC($3);
					                                                insertaLC($$,finalLC($$),oper);
					                                                liberaLC($3);
																													guardaResLC($$,oper.res);
																													liberarReg(oper.arg1);
					                                                liberarReg(oper.arg2);}

	| MINUSOP expression %prec UMINUS                               {$$=$2;
					                                                Operacion oper;
					                                                oper.op = "neg";
					                                                oper.res = obtenerReg();
					                                                oper.arg1 = recuperaResLC($2);
					                                                oper.arg2 = NULL;
	  				                                                insertaLC($$,finalLC($$),oper);
																	liberarReg(oper.arg1);
																	guardaResLC($$,oper.res);}

	| LPAREN expression RPAREN                                      {$$=$2;}

	| ID															{if (!perteneceTablaS($1)){ printf("Linea %d: Variable %s no declarada \n", yylineno, $1); errores_semanticos++;}
                                                                    $$ = creaLC();
                                                                    Operacion oper;
                                                                    oper.op = "lw";
                                                                    oper.res = obtenerReg();
                                                                    oper.arg1 = concatena("_",$1);
                                                                    oper.arg2 = NULL;
                                                                    insertaLC($$,finalLC($$),oper);
                                                                    guardaResLC($$,oper.res);}

    | INTLITERAL                                                    {$$ = creaLC();
		                                                            Operacion oper;
		                                                            oper.op = "li";
		                                                            oper.res = obtenerReg();
		                                                            oper.arg1 = $1;
		                                                            oper.arg2 = NULL;
		                                                            insertaLC($$,finalLC($$),oper);
		                                                            guardaResLC($$,oper.res);}
	;

%%
int perteneceTablaS(char* c)
{
    if (buscaLS(tablaSimbolos, c) != finalLS(tablaSimbolos))
	    return 1;
    else
        return 0;
}

void nuevaEntrada(char* c, Tipo t)
{
    Simbolo s;
    s.nombre = c;
    s.tipo = t;

    if(t == CADENA){
		s.valor = contadorCadenas;
		contadorCadenas++;
	}


    insertaLS(tablaSimbolos, finalLS(tablaSimbolos), s);
}

int esConstante(char* c)
{
    Simbolo s;
    s = recuperaLS(tablaSimbolos, buscaLS(tablaSimbolos, c));

    if (s.tipo == CONSTANTE)
	    return 1;
    else
        return 0;
}

void imprimirTablas()
{
    PosicionLista aux = inicioLS(tablaSimbolos);

    printf("############################\n.data\n\n");

    printf("# STRINGS ##################\n");
    while(aux != finalLS(tablaSimbolos)){
        Simbolo s = recuperaLS(tablaSimbolos, aux);

        if (s.tipo == CADENA)
            printf("$str%d:\t.asciiz %s \n", s.valor, s.nombre);

        aux = siguienteLS(tablaSimbolos, aux);
    }
    aux =  inicioLS(tablaSimbolos);

    printf("\n# IDENTIFIERS ##############\n");
    while(aux != finalLS(tablaSimbolos)){
        Simbolo s = recuperaLS(tablaSimbolos, aux);

        if (s.tipo == VARIABLE)
            printf("_%s:\t.word 0\n", s.nombre);
        if (s.tipo == CONSTANTE)
            printf("_%s:\t.word 0\n", s.nombre);

        aux = siguienteLS(tablaSimbolos, aux);
    }

}

void imprimirCodigo(ListaC codigo) {
  printf("###################\n");
	printf("# Seccion de codigo\n");
	printf("\t.text\n");
	printf("\t.globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)) {
		Operacion oper;
		oper = recuperaLC(codigo,p);
		if (!strcmp(oper.op,"etiq")) printf("%s:\n",oper.res);
		else {  printf("\t%s",oper.op);
			if (oper.res) printf(" %s",oper.res);
			if (oper.arg1) printf(",%s",oper.arg1);
			if (oper.arg2) printf(",%s",oper.arg2);
			}
		printf("\n");
		p = siguienteLC(codigo,p);
	}
	printf("##################\n");
	printf("# Fin\n");
	printf("\tli $v0, 10\n");
	printf("\tsyscall\n");
}

void liberarReg(char *reg) {
	if (reg[0] =='$' && reg[1] =='t') {
		int aux = reg[2] - '0';
		assert(aux >= 0);
		assert(aux < 9);
		registros[aux] = 0;
	}
}

char *obtenerReg() {
	for (int i = 0; i < 10; i++) {
		if (registros[i] == 0) {
			registros[i] = 1;
			char aux[16];
			sprintf(aux,"$t%d",i);
			return strdup(aux);
		}
	}
	printf("Error: registros agotados\n");
	exit(1);
}

char *concatena(char *arg1, char *arg2) {
	char *aux = (char*)malloc(strlen(arg1)+strlen(arg2)+1);
	sprintf(aux,"%s%s",arg1,arg2);
	return aux;
}

char *concatena2(char *arg1, int i) {
	char *aux = (char*)malloc(strlen(arg1)+11);
	sprintf(aux,"%s%d",arg1,i);
	return aux;
}

char *obtenerEtiqueta(){
	char aux[32];
	sprintf(aux, "$l%d", contadorEtiquetas++);
	return strdup(aux);
}

void yyerror()
{
	printf("Se ha producido un error sintactico en linea %d\n", yylineno);
    errores_sintacticos++;
}

int ok() {
	return !(errores_lexicos + errores_sintacticos + errores_semanticos);
}
