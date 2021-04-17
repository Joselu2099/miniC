#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
FILE *fich;
extern int yyparse();
extern int yydebug;
extern int ok();
extern int errores_sintacticos;
extern int errores_semanticos;

int main(int argc, char *argv[])
{

    if (argc != 2) {
	printf("Uso: %s fichero\n", argv[0]);
	exit(1);
    }
    int i;
    if ((fich=fopen(argv[1],"r"))==NULL) {
        printf("***ERROR, no puedo abrir el fichero\n");
        exit(2);
    }
    yyin=fich;
    /*Llamada al sintactico*/
    yydebug = 0;
    yyparse();
    if (errores_sintacticos) {
	printf("Analisis sintactico con errores\n");
    }
    if (errores_semanticos) {
	printf("Analisis semantico con errores\n");
    }

    fclose(fich);
    return 0;
}
