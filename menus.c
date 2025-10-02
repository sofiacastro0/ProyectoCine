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
            printf("Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while(opcion!=7);

}

//menu administrador//
void menuAdmin(){
    int opcion=1;
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
                char teclaPeli;
                while(opcionPeli != 0){
                    system("cls");
                    printf("---- Gestion de Peliculas ----\n");
                    printf("1. Alta de Pelicula\n");
                    printf("2. Listar Peliculas\n");
                    printf("3. Baja de Pelicula\n");
                    printf("0. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcionPeli);

                    switch(opcionPeli){
                        case 1:
                            altaPeli();
                            break;
                        case 2:
                            listaDePelis();
                            break;
                        case 3:
                            bajaPeli();
                            break;
                        case 0:
                            printf("Volviendo al menu admin\n");
                            break;
                        default:
                            printf("Opcion invalida\n");
                    }

                    printf("Presione Enter para continuar...");
                    getchar(); //limpia buffer
                    getchar(); // espera enter
                }
                break;
            }
            case 2:
                system("cls");
                break;
            case 3:
                system("cls");
                break;
            case 4:
                system("cls");
                break;
            case 5:
                system("cls");
                break;
            case 6:
                break;
            default:
                system("cls");
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion != 6){
            printf("Presione Enter para continuar.");
            getchar();
        }

    } while (opcion!=6);
}

