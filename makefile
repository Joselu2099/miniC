#MAKEFILE MINIC

miniC : main.c sintactico.tab.c lex.yy.c listaSimbolos.c listaCodigo.c
	gcc -g main.c sintactico.tab.c lex.yy.c listaSimbolos.c listaCodigo.c -lfl -o miniC

lex.yy.c : lexico.l
	flex lexico.l

sintactico.tab.h sintactico.tab.c : sintactico.y
	bison -d -v sintactico.y

clean :
	rm -f miniC miniC.s errores.txt sintactico.output lex.yy.c  sintactico.tab.* miniPascal.s

run : mc.sh pruebas/test_sem4.mc.txt
	bash mc.sh pruebas/test_sem1.mc.txt
