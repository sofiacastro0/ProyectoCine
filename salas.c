#include "salas.h"
#include "ids.h"
#include <stdio.h>
#include <string.h>

extern Sala salas[MAX_SALAS];  // Array de salas
int cantidadSalas = 0;  // Contador de salas actuales

void altaSala() {
    if (cantidadSalas >= MAX_SALAS) {
        printf("No se pueden agregar más salas.\n");
        return;
    }
}

void bajaSala(){
    printf("---- Baja Sala ----");
}
void modificarSala(){
    printf("---- Modificar Sala ----");
}
void listarSalas(){
    printf("---- Lista Salas ----");
}

int generarIdSala(){

}

void menuGestionSalas(){

}
