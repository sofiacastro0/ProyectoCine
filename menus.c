#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "peliculas.h"
#include "ids.h"

int menuPrincipal(void) {

    int seleccion;
    system("cls");
    printf("---------------------------------\n");
    printf("   Sistema de Reservas de Cine\n");
    printf("---------------------------------\n");
    printf("1. Operar como Cliente\n");
    printf("2. Operar como Administrador\n");
    printf("0. Salir del sistema\n");
    printf("---------------------------------\n");
    printf("Seleccione una opcion: ");
    scanf("%d",&seleccion);

    return seleccion;
}

//Funcion para menu cliente
void menuCliente(){
    int opcion=1;
    char tecla;

    do {

        system("cls");
        printf("--------- Menu Cliente -----------\n");
        printf("1. Buscar funciones por fecha\n");
        printf("2. Buscar funciones por pelicula\n");
        printf("3. Ver butacas disponibles\n");
        printf("4. Reservar butacas\n");
        printf("5. Cancelar reserva\n");
        printf("6. Ver mis reservas\n");
        printf("7. Volver al menu principal\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                //1. Buscar funciones por fecha
                system("cls");
                break;
            case 2:
                //Buscar funciones por película
                system("cls");
                break;
            case 3:
                //Ver butacas disponibles
                system("cls");
                break;
            case 4:
                //Reservar butacas
                system("cls");
                break;
            case 5:
                //Cancelar reserva
                system("cls");
                break;
            case 6:
                //Ver mis reservas
                system("cls");
                break;
            case 7:
                //Volver al menú principal
                break;
            default:
                system("cls");
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion!=7){  //limpia el buffer
             //Si la opcion elegida NO es 7. (pausa la ejecución hasta que el usuario presione enter y
            //limpiar el buffer de entrada para que no queden caracteres pendientes que arruinen la próxima lectura.)
            printf("Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while(opcion!=7);

}

//menu administrador//
void menuAdmin(){
    int opcion = -1;
    char tecla;

    do {
        system("cls");
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
                    system("cls");
                    printf("---- Gestion de Peliculas ----\n");
                    printf("1. Alta de Pelicula\n");
                    printf("2. Listar Peliculas\n");
                    printf("3. Baja Peliculas\n");
                    printf("4. Modificar Peliculas\n");
                    printf("0. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcionPeli);
//Hice el switch en una sola linea para que sea mas prolijo de leer
                    switch(opcionPeli) {
                        case 1: altaPeli(); break; //Listo
                        case 2: listaDePelis(); break; //Listo
                        case 3: bajaPeli(); break;
                        case 4: modificarPeli(); break;
                        case 0: printf("Volviendo al menú admin...\n"); break;
                        default: printf("Opción inválida\n");
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
                    system("cls");
                    printf("\n--- GESTIÓN DE SALAS ---\n");
                    printf("1. Alta de sala\n");
                    printf("2. Baja de sala\n");
                    printf("3. Modificación de sala\n");
                    printf("4. Listar salas\n");
                    printf("5. Volver al menú anterior\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &opcionSala);

                    switch(opcionSala) {
                        case 1: altaSala(); break;
                        case 2: bajaSala(); break;
                        case 3: modificarSala(); break;
                        case 4: listarSalas(); break;
                        case 5: printf("Volviendo al menú anterior...\n"); break;
                        default: printf("Opción inválida.\n");
                    }

                    if(opcionSala != 6){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    } //termina el if
                } //termina el while
                break;
            } //termina el case 2 del submenu salas
            case 6:
                printf("Volviendo al menu principal...\n");
                break;
            default:
                printf("Opción inválida\n");
        }

    } while(opcion != 6);
}
