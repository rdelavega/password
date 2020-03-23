#include "headers.h"

void __HELP() {
    fprintf(stderr, "\n\n\tInstrucciones: \n\n");
    fprintf(stderr, "Para compilar programa:\n");
    fprintf(stderr, "\t$ make\n\n");
    fprintf(stderr, "Para ejecutar programa:\n");
    fprintf(stderr, "\t$ make ARGS=\"su_contraseña_sin_espacios\" run\n\n");
    fprintf(stderr, "Para limpiar:\n");
    fprintf(stderr, "\t$ make clean\n\n");
}
