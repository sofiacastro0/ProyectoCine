#include "salas.h"
#include "ids.h"
#include <stdio.h>
#include <string.h>

void altaSala() {
    if (cantidadSalas >= MAX_SALAS) {
        printf("No se pueden agregar m�s salas.\n");
        return;
    }

