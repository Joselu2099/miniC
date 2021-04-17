#MAKEFILE MINIC

miniC : main.c miniC.tab.c lex.yy.c listaSimbolos.c listaCodigo.c
	gcc -g main.c miniC.tab.c lex.yy.c listaSimbolos.c listaCodigo.c -lfl -o miniC

lex.yy.c : miniC.l miniC.tab.h
	flex miniC.l

miniC.tab.h miniC.tab.c : miniC.y
	bison -d -v miniC.y

clean :
	rm -f miniC miniC.s errores.txt lex.yy.c  miniC.s miniC.tab.*

run : makerun.sh testCodigo.mp
	@echo "****** Compilador miniC ******"
	bash makerun.sh testCodigo.mp
