#include <stdlib.h>
#include "util.h"

//Detecta el sistema operativo y define clear
#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

void limpiarPantalla() {
    system(clear);
}
