#include <stdlib.h>
#include "util.h"

#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

void limpiarPantalla() {
    system(clear);
}
