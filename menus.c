#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "peliculas.h"
#include "ids.h"
#include "clientes.h"
#include "util.h"
#include "salas.h"
#include "funciones.h"

void inicioCliente() {
    int opcion=1;
    char tecla;
        limpiarPantalla();
        printf("---- Gestion de Clientes ----\n");
        printf("1. Alta\n");
        printf("2. Baja\n");
        printf("3. Modificacion\n");
        printf("4. Menu cliente\n");
        printf("0. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

            switch (opcion) {
                case 1: altaCliente(); break;
                case 2: bajaCliente(); break;
                case 3: modificacionCliente(); break;
                case 4: if (iniciarSesion()){
                            menuCliente();
                        }
                case 0: break;
                default: printf("Opcion invalida\n"); break;
            }

            if(opcion != 0){
            printf("Presione Enter para continuar.");
            getchar();
        }
}

void menuCliente(){
    int opcion=-1;
    char tecla;

    do {
        limpiarPantalla();
        printf("--------- Menu Cliente -----------\n");
        printf("1. Buscar funciones\n");
        printf("2. Ver butacas disponibles\n");
        printf("3. Reservar butacas\n");
        printf("4. Cancelar reserva\n");
        printf("5. Ver mis reservas\n");
        printf("6. Volver al menu principal\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1: menuBuscarFunciones(); break;
            case 2:
                //Ver butacas disponibles
                limpiarPantalla();
                break;
            case 3:
                //Reservar butacas
                limpiarPantalla();
                break;
            case 4:
                //Cancelar reserva
                limpiarPantalla();
                break;
            case 5:
                //Ver mis reservas
                limpiarPantalla();
                break;
            case 6:
                //Volver al menú principal
                break;
            default:
                limpiarPantalla();
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion!=6){  //limpia el buffer
        //Si la opcion elegida NO es 7. (pausa la ejecución hasta que el usuario presione enter y
        //limpiar el buffer de entrada para que no queden caracteres pendientes que arruinen la próxima lectura.)
            printf("Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while(opcion!=6);

}

//menu administrador//
void menuAdmin(){
    int opcion = -1;
    char tecla;
    do {
        limpiarPantalla();
        printf("------- Menu Administrador -------\n");
        printf("1. Gestion de Peliculas\n");
        printf("2. Gestion de Salas\n");
        printf("3. Gestion de Clientes\n");
        printf("4. Funciones\n");
        printf("5. Reportes\n");
        printf("6. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1: { // Submenú Peliculas
                int opcionPeli = -1;
                while(opcionPeli != 0){
                    limpiarPantalla();
                    printf("---- Gestion de Peliculas ----\n");
                    printf("1. Alta de Pelicula\n");
                    printf("2. Baja de Pelicula\n");
                    printf("3. Modificacion de Pelicula\n");
                    printf("4. Listar Peliculas\n");
                    printf("0. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcionPeli);

//Switch en una sola linea para que sea mas prolijo de leer
                    switch(opcionPeli) {
                        case 1: altaPeli(); break; //Listo
                        case 2: bajaPeli(); break; //Listo
                        case 3: modificacionPeli(); break; //Listo
                        case 4: listaDePelis(); break; //Listo
                        case 0: printf("Volviendo al menú admin...\n"); break;
                        default: printf("Opción inválida\n"); break;
                    }

                    if(opcionPeli != 0){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }
            case 2: { // Submenú Salas
                int opcionSala = -1;
                while(opcionSala != 5){
                    limpiarPantalla();
                    printf("\n--- GESTIÓN DE SALAS ---\n");
                    printf("1. Alta de sala\n");
                    printf("2. Baja de sala\n");
                    printf("3. Modificacion de sala\n");
                    printf("4. Listar salas\n");
                    printf("5. Volver al menu anterior\n");
                    printf("Ingrese opcion: ");
                    scanf("%d", &opcionSala);

                    switch(opcionSala) {
                        case 1: altaSala(); break;
                        case 2: bajaSala(); break;
                        case 3: modificarSala(); break;
                        case 4: listarSalas(); break;
                        case 5: printf("Volviendo al menú anterior\n"); break;
                        default: printf("Opcion invalida.\n");
                    }

                    if(opcionSala != 5){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 3: {
                    int opcionCliente = -1;
                    while(opcionCliente != 2){
                    limpiarPantalla();
                    printf("\n--- GESTION DE CLIENTES ---\n");
                    printf("1. Listar clientes\n");
                    printf("2. Volver al menú anterior\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &opcionCliente);

                    switch(opcionCliente) {
                        case 1: listarClientes(); break;
                        case 2: printf("Volviendo al menú anterior...\n"); break;
                        default: printf("Opción inválida.\n");
                    }

                    if(opcionCliente != 2){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 4: {
                    int opcionFuncion = -1;
                    while(opcionFuncion != 5){
                    limpiarPantalla();
                    printf("\n--- GESTION DE FUNCIONES ---\n");
                    printf("1. Alta de funcion\n");
                    printf("2. Baja de funcion\n");
                    printf("3. Modificación de funcion\n");
                    printf("4. Listar funciones\n");
                    printf("5. Volver al menú anterior\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &opcionFuncion);

                    switch(opcionFuncion) {
                        case 1: altaFuncion(); break;
                        case 2: bajaFuncion(); break;
                        case 3: modificarFuncion(); break;
                        case 4: listarFunciones(); break;
                        case 5: printf("Volviendo al menú anterior...\n"); break;
                        default: printf("Opción inválida.\n");
                    }

                    if(opcionFuncion != 5){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 5: limpiarPantalla(); break;  // ACA VAN LOS REPORTES
            case 6: printf("Volviendo al menu principal...\n"); break;
            default:
                printf("Opción inválida\n");
        }

    } while(opcion != 6);
    return;
}


