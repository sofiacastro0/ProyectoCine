#include "salas.h"
#include "ids.h"
#include <stdio.h>
#include <string.h>

// Alta de sala hay que indicar que le pongan un nombre a la sala
// Modificacion de sala se puede elegir modificar el nombre

Sala salas[MAX_SALAS];  // Array de salas
int cantidadSalas = 0;  // Contador de salas actuales

    //alta
void altaSala() {

    if (cantidadSalas >= MAX_SALAS) {
        printf("No se pueden agregar más salas.\n");
        return;
    }

    Sala nueva;
    nueva.id = generarId(ENTIDAD_SALA);
    nueva.activo = 1;

    printf("Ingrese nombre de la sala: ");
    scanf(" %[^\n]", nueva.nombre); //%[^\n] sirve para leer todo hasta el salto de linea, si no lo usamos solo queda la primera palabra de todo lo ingresado

    // Inicializamos todas las butacas en 0
    for(int i = 0; i < MAX_FILAS; i++)
        for(int j = 0; j < MAX_COLUMNAS; j++)
            nueva.butacas[i][j] = 0;

    salas[cantidadSalas] = nueva;
    cantidadSalas++;

    printf("Sala agregada. ID: %d\n", nueva.id);
}

void bajaSala() {
    int id;
    printf("Ingrese ID de sala a dar de baja: ");
    scanf("%d", &id);

    for(int i = 0; i < cantidadSalas; i++) {
        if(salas[i].id == id && salas[i].activo) {
            salas[i].activo = 0;
            printf("Sala ID %d dada de baja.\n", id);
            return;
        }
    }
    printf("No se encontro sala activa con ese ID %d\n", id);
}

void modificarSala() {
    int id;
    int opcion;
    printf("Ingrese ID de sala que quiere modificar: ");
    scanf("%d", &id);


    for(int i = 0; i < cantidadSalas; i++) {
        if(salas[i].id == id && salas[i].activo) {

            printf("Ingrese nuevo nombre para sala: ");
            scanf(" %[^\n]", salas[i].nombre);

            //Pregunto si quiere reiniciar butacas por si solo quería cambiar el nombre
            printf("¿Quiere reiniciar todas las butacas? (s/n): ");
            scanf(" %c", &opcion);
            if (opcion=='s') {
                for (int f = 0; f < MAX_FILAS; f++){ //Recorremos y ponemos filas y columnas en 0
                    for (int c = 0; c < MAX_COLUMNAS; c++){
                        salas[i].butacas[f][c] = 0;
                    }
                      }

                  printf("Butacas reiniciadas.\n");
            } else {
                  printf("Ok, butacas no modificadas.\n");
            }

            printf("Sala ID: %d modificada correctamente.\n", id);
            return;
        }
    }
    printf("No se encontro sala activa con ese ID %d\n", id);
}


//Pusimos un max de 16 filas y 17 columnas , por eso da igual a 272 butacas
//lista de salas
void listarSalas() {
    printf("Lista de salas\n");
    for(int i = 0; i < cantidadSalas; i++) {
        if(salas[i].activo) {
            int libres = 0;
            for(int f = 0; f < MAX_FILAS; f++){
                for(int c = 0; c < MAX_COLUMNAS; c++){
                    if(salas[i].butacas[f][c] == 0){
                      libres++;
                      }
                   }
                }
        printf("ID: %d . Nombre sala: %s . Butacas libres: %d/%d\n", salas[i].id, salas[i].nombre,libres, MAX_FILAS * MAX_COLUMNAS);
        }
    }
}


