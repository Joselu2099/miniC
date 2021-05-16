#MAKEFILE MINIC

miniC : main.c sintactico.tab.c lex.yy.c listaSimbolos.c listaCodigo.c
	gcc -g main.c sintactico.tab.c lex.yy.c listaSimbolos.c listaCodigo.c -lfl -o miniC

lex.yy.c : lexico.l
	flex lexico.l

sintactico.tab.h sintactico.tab.c : sintactico.y
	bison -d -v sintactico.y

clean :
	rm -f miniC miniC.s errores.txt lex.yy.c  sintactico.tab.*

run : mc.sh testCodigo.mc
<<<<<<< HEAD
=======
	@echo "****** Compilador miniC ******"
>>>>>>> 068b0e894b140f7c37de58039cdbf1d5d76716ec
	bash mc.sh testCodigo.mc
