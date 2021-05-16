#!/bin/bash -u

test $# -ne 1 && echo "USO: $0 <fichero>" >&2 && exit 1

if test ! -f "$1" -o ! -r "$1"
then
	echo "Imposible acceder al fichero $1" >&2
	exit 2
fi

echo "****** Compilador miniPascal ******"
make 2>&1 > errores.txt

./miniC $1 > miniC.s

echo "Salida:"
(spim -file miniPascal.s | tail -n +6) | while read linea
do
  echo " $linea"
done
