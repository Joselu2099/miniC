/************************
 * Fichero de prueba nº 1
 ************************/

void prueba() {
    // Declaraciones
    const a=0, b=0;
    var c=5+2-2;
    // Sentencias

    print "Inicio del programa\n";
    if (a) print "a","\n";
    else if (b) print "No a y b\n";
         else while (c) {
             print "c=",c,"\n";
             c = c-2+1;
         }
    print "Final","\n";
}
