%{
#include "miniC.tab.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
int inicio_comentario = 0;
int errores_lexicos = 0;
%}
digito              [0-9]
letra               [a-zA-Z$_]
entero              {digito}+
panico		    			[^a-zA-Z0-9_$();,.:=+/-{}* \n\t\r"/]+

 // CONDICION DE CONTEXTO

%x comentario
%option yylineno

%%
[ \n\t\r]+                                  ;
"//"(.*)[\n]                                ;
"/*"				            { yymore(); BEGIN(comentario); inicio_comentario = yylineno; }
<comentario>"*/"			    { printf("Comentario: %s\n", yytext); BEGIN(INITIAL); }
<comentario>(.|\n)			    { yymore(); }
<comentario><<EOF>>			    { printf("Error: comentario no cerrado %d\n", inicio_comentario);
					      errores_lexicos++;
				              return 0;
				            }
void				            return VOID;
var					            return VAR;
const					          return CONST;
if					            return IF;
else					          return ELSE;
while					          return WHILE;
print                   return PRINT;
read					          return READ;
{letra}({letra}|{digito})*		    { if(yyleng > 16){
						                        printf("Error: desbordamiento del identificador en linea %d\n", yylineno );
						                        errores_lexicos++;
					     	                  }
						                             yylval.str = strdup(yytext);
					     	                         return ID;
					                        }
{entero}                         { long long n = atoll(yytext);
              			               if(n>pow(2,31)){
              					                  printf("Error: desbordamiento de entero en linea %d\n", yylineno );
              				                    errores_lexicos++;
				                           }
				                           yylval.str = strdup(yytext);
			                             return NUM;
			                           }
"("                              return LPAREN;
")"                              return RPAREN;
";"                              return SEMICOLON;
","                              return COMMA;
"="                              return ASSIGNOP;
"+"                              return PLUSOP;
"-"                              return MINUSOP;
"*"                              return POROP;
"/"                              return DIVOP;
"{"                              return RCOR;
"}"                              return LCOR;
\"([^"\n]|\\\")*\"		 					 {yylval.str = strdup(yytext);return STRING;}
\"([^"\n]|\\\")*			    			 { printf("Error: cadena sin cerrar en linea %d\n", yylineno );
					      									 errores_lexicos++;
				            						 }
{panico}                  			 { printf("Error lexico en %s en linea %d\n",yytext, yylineno );
																   errores_lexicos++;
															   }
%%
