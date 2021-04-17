%{
#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

extern int yylex();
extern int yylineno;

int errores_sintacticos = 0;
int errores_semanticos = 0;
extern int errores_lexicos;
void yyerror(const char *msg);
int ok();
int contadorString = 1;
int contador_etiq = 1;
void imprimirLS();
void imprimirCodigo(ListaC codigo);
char *obtenerReg();
void liberarReg(char *reg);
char *concatena(char *arg1, char *arg2);
char *concatena2(char *arg1, int i);
char *nuevaEtiqueta();
char registros[10] = {0};

//Lista de simbolos
Lista l;

%}

%code requires {
	#include "listaCodigo.h"
}

/*  Definicion de tipos semanticos */

%union {
	char *str;
	ListaC codigo;
}
%type <codigo> expression statement print_item print_list read_list compound_statement optional_statements statements declarations constants program

/*Definicion de tokens */

%token <str> ID	"id"
%token VOID	"void"
%token CONST	"const"
%token VAR	"var"
%token COMMA	","
%token IF	"if"
%token ELSE	"else"
%token WHILE "while"
%token PRINT "print"
%token READ	"read"
%token <str> STRING "string"
%token <str> NUM "num"
%token PLUSOP  "+"
%token MINUSOP "-"
%token POROP  "*"
%token DIVOP   "/"
%token LPAREN  "("
%token RPAREN  ")"
%token SEMICOLON ";"
%token ASSIGNOP  "="
%token LCOR "{"
%token RCOR "}"


/* Flags de funcionamiento de Bison */

%define parse.error verbose //genera mensajes de error extensos
%define parse.trace // Activar trazas con yydebug=1


/* Asociatividad y precedencia de operadores */

%left "+" "-"
%left "*" "/"
%nonassoc UMINUS

/* Hay un conflicto desplaza/reduce en if-else */
%expect 1

%%

 /*Reglas de produccion */

program : { l = creaLS(); } "program" "id" "(" ")" ";" functions declarations compound_statement "." {
	    if(ok()){
		   imprimirLS(l); 	//Volcar .data del programa
		   concatenaLC($8,$9);
		   imprimirCodigo($8);  //Volcar .text del programa
	    }
	    liberaLS(l);
	    liberaLC($8);
	  }
	;

functions : functions function ";"	{}
	  |				{}
	  ;

function : "function" "id" "(" "const" identifiers ":" type ")" ":" type declarations compound_statement { printf("Error: funciones no soportadas\n");
													   errores_semanticos++;
													 }
	 ;

declarations : declarations "var" identifiers ":" type ";" { $$=$1;}
	     | declarations "const" constants ";" { $$=$1;
						    concatenaLC($$,$3);
						    liberaLC($3);
						  }
	     | { $$=creaLC();}
	     ;

identifiers : "id" {
			//Comprobar si $1 esta en la lista
			PosicionLista p = buscaLS(l,$1);
  			if (p != finalLS(l)) {
				//Estoy redeclarando el identificador
				printf("Error en linea %d: %s redeclarado\n", yylineno, $1);
				errores_semanticos++;
			}
			else{
				//Primera declaracion de $1: es correcto
				Simbolo aux;
				aux.nombre = $1;
				aux.tipo = VARIABLE;
				insertaLS(l,finalLS(l),aux);
			}
	    }
	    | identifiers "," "id" { PosicionLista p = buscaLS(l,$3);
		  		     if (p != finalLS(l)) {
						//Estoy redeclarando el identificador
						printf("Error en linea %d: %s redeclarado\n", yylineno, $3);
						errores_semanticos++;
				     }
				     else{
						//Primera declaracion de $3: es correcto
						Simbolo aux;
						aux.nombre = $3;
						aux.tipo = VARIABLE;
						insertaLS(l,finalLS(l),aux);
				     }
				    }
            ;

type : "integer"	{}
     ;

constants :"id" ":=" expression   { PosicionLista p = buscaLS(l,$1);
		  		    if (p != finalLS(l)) {
								//Estoy redeclarando la constante
								printf("Error en linea %d: %s redeclarado\n", yylineno, $1);
								errores_semanticos++;
				    	}else{
								//Primera declaracion de $1: es correcto
								Simbolo aux;
								aux.nombre = $1;
								aux.tipo = CONSTANTE;
								insertaLS(l,finalLS(l),aux);
				    	}
					    $$=$3;
					    Operacion oper;
					    oper.op = "sw";
					    oper.res = recuperaResLC($3);
					    oper.arg1 = concatena("_",$1);
					    oper.arg2 = NULL;
					    insertaLC($$,finalLC($$),oper);
					    liberarReg(oper.res);
				   }
	  | constants "," "id" ":=" expression { PosicionLista p = buscaLS(l,$3);
				  		 if (p != finalLS(l)) {
							//Estoy redeclarando la constante
							printf("Error en linea %d: %s redeclarado\n", yylineno, $3);
							errores_semanticos++;
						 }
						 else{
							//Primera declaracion de $3: es correcto
							Simbolo aux;
							aux.nombre = $3;
							aux.tipo = CONSTANTE;
							insertaLS(l,finalLS(l),aux);
						 }
						 $$=$1;
						 Operacion oper;
						 oper.op = "sw";
						 oper.res = recuperaResLC($5);
						 oper.arg1 = concatena("_",$3);
						 oper.arg2 = NULL;
						 insertaLC($5,finalLC($5),oper);
						 concatenaLC($$,$5);
						 liberarReg(oper.res);
						 liberaLC($5);
						}
	  ;

compound_statement : "begin" optional_statements "end" { $$=$2;}
		   ;

optional_statements : statements { $$=$1;}
		    | { $$=creaLC();}
	   	    ;

statements : statement { $$=$1; }
	   | statements ";" statement { $$=$1;
					concatenaLC($$,$3);
				      }
 	   ;

statement : "id" "=" expression {  // Busqueda del si­mbolo "$1"
				    PosicionLista p = buscaLS(l,$1);
				    if (p != finalLS(l)) {
					    Simbolo aux = recuperaLS(l,p);
					    if (aux.tipo != VARIABLE) {
						printf("Error en linea %d. No se puede asignar a la CONSTANTE %s\n",yylineno,aux.nombre);
						errores_semanticos++;
				    	    }
				    }
				    else {
					    printf("Error en linea %d. No encontrado %s\n",yylineno,$1);
					    errores_semanticos++;
				    }
				    $$=$3;
				    Operacion oper;
				    oper.op = "sw";
				    oper.res = recuperaResLC($3);
				    oper.arg1 = concatena("_",$1);
				    oper.arg2 = NULL;
				    insertaLC($$,finalLC($$),oper);
				    liberarReg(oper.res);
				 }
	  | "if" expression "then" statement {  $$=$2;
						char *etiq = nuevaEtiqueta();
						Operacion oper;
						oper.op = "beqz";
						oper.res = recuperaResLC($2);
						oper.arg1 = etiq;
						oper.arg2 = NULL;
						insertaLC($$,finalLC($$),oper);
						concatenaLC($$,$4);
						liberaLC($4);

						oper.op = "etiq";
						oper.res = etiq;
						oper.arg1 = NULL;
						oper.arg2 = NULL;
						insertaLC($$,finalLC($$),oper);
						}
	  | "if" expression "then" statement "else" statement { $$=$2;
								char *etiq = nuevaEtiqueta();
								char *etiq1 = nuevaEtiqueta();
								Operacion oper;
								oper.op = "beqz";
								oper.res = recuperaResLC($2);
								oper.arg1 = etiq;
								oper.arg2 = NULL;
								insertaLC($$,finalLC($$),oper);
								concatenaLC($$,$4);
								liberaLC($4);

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

								oper.op = "etiq";
								oper.res = etiq1;
								oper.arg1 = NULL;
								oper.arg2 = NULL;
								insertaLC($$,finalLC($$),oper);

							      }
	  | "while" expression "do" statement { $$=creaLC();
						char *etiq = nuevaEtiqueta();
						char *etiq1 = nuevaEtiqueta();
						Operacion oper;
						oper.op = "etiq";
						oper.res = etiq;
						oper.arg1 = NULL;
						oper.arg2 = NULL;
						insertaLC($$,finalLC($$),oper);

						oper.op = "beqz";
						oper.res = recuperaResLC($2);
						oper.arg1 = etiq1;
						oper.arg2 = NULL;
						insertaLC($$,finalLC($$),oper);
						concatenaLC($$,$4);

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
					     }
	  | "for" "id" ":=" expression "to" expression "do" statement { PosicionLista p = buscaLS(l,$2);
									if (p != finalLS(l)) {
									    Simbolo aux = recuperaLS(l,p);
									    if (aux.tipo != VARIABLE) {
										printf("Error en linea %d. No se puede asignar a la CONSTANTE %s\n",yylineno,aux.nombre);
										errores_semanticos++;
								    	    }
									 }
									 else {
										printf("Error en linea %d. No encontrado %s\n",yylineno,$2);
										errores_semanticos++;
									 }
									}
	  | "write" "(" print_list ")" { $$=$3;}
	  | "read" "(" read_list ")" { $$=$3;}
	  | compound_statement { $$=$1;}
	  ;

print_list : print_item { $$=$1;}
	   | print_list "," print_item { $$=$1;
					 concatenaLC($$,$3);
					 liberaLC($3);}
	   ;

print_item : expression { $$=$1;
			  Operacion oper;
			  oper.op = "li";
			  oper.res = "$v0";
			  oper.arg1 = "1";
			  oper.arg2 = NULL;

			  insertaLC($$,finalLC($$),oper);

			  oper.op = "move";
			  oper.res = "$a0";
			  oper.arg1 = recuperaResLC($1);
			  oper.arg2 = NULL;

			  insertaLC($$,finalLC($$),oper);

			  oper.op = "syscall";
			  oper.res = NULL;
			  oper.arg1 = NULL;
			  oper.arg2 = NULL;

			  insertaLC($$,finalLC($$),oper);
			  liberarReg(recuperaResLC($1));

			}
	   | "string" { Simbolo aux;
		        aux.nombre = $1;
			aux.tipo = CADENA;
			aux.valor = contadorString++;
			insertaLS(l,finalLS(l),aux);

			$$ = creaLC();

			Operacion oper;
			oper.op = "li";
			oper.res = "$v0";
			oper.arg1 = "4";
			oper.arg2 = NULL;

			insertaLC($$,finalLC($$),oper);

			oper.op = "la";
			oper.res = "$a0";
			oper.arg1 = concatena2("$str",aux.valor);
			oper.arg2 = NULL;

			insertaLC($$,finalLC($$),oper);

			oper.op = "syscall";
			oper.res = NULL;
			oper.arg1 = NULL;
			oper.arg2 = NULL;

			insertaLC($$,finalLC($$),oper);
		      }
	   ;

read_list : "id" { // Busqueda del si­mbolo "$1"
		   PosicionLista p = buscaLS(l,$1);
		   if (p != finalLS(l)) {
				Simbolo aux = recuperaLS(l,p);
				if (aux.tipo != VARIABLE) {
					printf("Error en linea %d. No se puede asignar a la : %s\n",yylineno,aux.nombre);
					errores_semanticos++;
				}
		    }
	            else {
			printf("Error en linea %d. No encontrado %s\n",yylineno,$1);
			errores_semanticos++;
		    }

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
	  | read_list "," "id" { // Busqueda del si­mbolo "$3"
				 PosicionLista p = buscaLS(l,$3);
				 if (p != finalLS(l)) {
					Simbolo aux = recuperaLS(l,p);
					if (aux.tipo != VARIABLE) {
						printf("Error en linea %d. No se puede asignar a la : %s\n",yylineno,aux.nombre);
						errores_semanticos++;
					}
				  }
				  else {
					printf("Error en linea %d. No encontrado %s\n",yylineno,$3);
					errores_semanticos++;
				  }

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

 /* $1 = valor del primer simbolo del lado derecho (integer) */
 /* $$ = valor del no expressioninal del lado izquierdo (expression) */
expression : expression "+" expression { $$=$1;
					 concatenaLC($$,$3);
					 Operacion oper;
					 oper.op = "add";
					 oper.res = recuperaResLC($1);
					 oper.arg1 = recuperaResLC($1);
					 oper.arg2 = recuperaResLC($3);
					 insertaLC($$,finalLC($$),oper);
					 liberaLC($3);
					 liberarReg(oper.arg2);
				       }
	   | expression "-" expression { $$=$1;
					 concatenaLC($$,$3);
					 Operacion oper;
					 oper.op = "sub";
					 oper.res = recuperaResLC($1);
					 oper.arg1 = recuperaResLC($1);
					 oper.arg2 = recuperaResLC($3);
					 insertaLC($$,finalLC($$),oper);
					 liberaLC($3);
					 liberarReg(oper.arg2);
				       }
	   | expression "*" expression { $$=$1;
					 concatenaLC($$,$3);
					 Operacion oper;
					 oper.op = "mul";
					 oper.res = recuperaResLC($1);
					 oper.arg1 = recuperaResLC($1);
					 oper.arg2 = recuperaResLC($3);
					 insertaLC($$,finalLC($$),oper);
					 liberaLC($3);
					 liberarReg(oper.arg2);
				       }
	   | expression "/" expression { $$=$1;
					 concatenaLC($$,$3);
					 Operacion oper;
					 oper.op = "div";
					 oper.res = recuperaResLC($1);
					 oper.arg1 = recuperaResLC($1);
					 oper.arg2 = recuperaResLC($3);
					 insertaLC($$,finalLC($$),oper);
					 liberaLC($3);
					 liberarReg(oper.arg2);
				       }
	   | "-" expression %prec UMINUS { $$=$2;
					   Operacion oper;
					   oper.op = "neg";
					   oper.res = recuperaResLC($2);
					   oper.arg1 = recuperaResLC($2);
					   oper.arg2 = NULL;
	  				   insertaLC($$,finalLC($$),oper);
					 }
	   | "(" expression ")" { $$=$2;
				}
	   | "id" {  // Busqueda del si­mbolo "$1"
		    PosicionLista p = buscaLS(l,$1);
		    if (p == finalLS(l)) {
			printf("Error en linea %d. No encontrado %s\n",yylineno,$1);
			errores_semanticos++;
		    }
		    $$ = creaLC();
   		    Operacion oper;
		    oper.op = "lw";
		    oper.res = obtenerReg();
		    oper.arg1 = concatena("_",$1);
		    oper.arg2 = NULL;
		    insertaLC($$,finalLC($$),oper);
		    guardaResLC($$,oper.res);
		   }
	   | "num" { $$ = creaLC();
		     Operacion oper;
		     oper.op = "li";
		     oper.res = obtenerReg();
		     oper.arg1 = $1;
		     oper.arg2 = NULL;
		     insertaLC($$,finalLC($$),oper);
		     guardaResLC($$,oper.res);
		   }
	   | "id" "(" arguments ")" { // Busqueda del si­mbolo "$1"
				      PosicionLista p = buscaLS(l,$1);
				      if (p == finalLS(l)) {
					  printf("Error en linea %d. No encontrado %s\n",yylineno,$1);
					  errores_semanticos++;
				      }
					printf("Error: funciones no soportadas\n");
					errores_semanticos++;
				    }
	   | "(" error ")" { }
	   ;

arguments : expressions	{}
	  |		{}
	  ;

expressions : expression			{}
	    | expressions "," expression	{}
	    ;


%%

/*Metodo invocado por Bison si hay errores sintacticos */
void yyerror(const char *msg) {
	printf("Error en linea %d; %s\n",yylineno, msg);
	errores_sintacticos++;
}

int ok() {
	return !(errores_lexicos + errores_sintacticos + errores_semanticos);
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

void liberarReg(char *reg) {
	if (reg[0] =='$' && reg[1] =='t') {
		int aux = reg[2] - '0';
		assert(aux >= 0);
		assert(aux < 9);
		registros[aux] = 0;
	}
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

char *nuevaEtiqueta() {
	char aux[16];
	sprintf(aux,"$l%d",contador_etiq++);
	return strdup(aux);
}

void imprimirLS() {
	//Recorrido y generacion de .data
	PosicionLista q = inicioLS(l);
	printf("######################\n");
	printf("# Cadenas del programa\n");
	printf("	.data\n");
  	while (q != finalLS(l)) {
    		Simbolo aux = recuperaLS(l,q);
		//Volcar informacion de simbolo
		if(aux.tipo == CADENA) {
			printf("$str%d: .asciiz %s\n", aux.valor,aux.nombre);
		}
    		q = siguienteLS(l,q);
  	}
	PosicionLista p = inicioLS(l);
	printf("# Variables y constantes\n");
	while (p != finalLS(l)) {
    		Simbolo aux = recuperaLS(l,p);
		//Volcar informacion de simbolo
		if (aux.tipo == VARIABLE || aux.tipo == CONSTANTE) {
			printf("_%s: .word 0\n", aux.nombre);
		}
    		p = siguienteLS(l,p);
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
