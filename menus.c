#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "peliculas.h"
#include "ids.h"

int menuPrincipal(void) {

    int seleccion;
    system(clear);
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

        system(clear);
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
                system(clear);
                break;
            case 2:
                //Buscar funciones por pel�cula
                system(clear);
                break;
            case 3:
                //Ver butacas disponibles
                system(clear);
                break;
            case 4:
                //Reservar butacas
                system(clear);
                break;
            case 5:
                //Cancelar reserva
                system(clear);
                break;
            case 6:
                //Ver mis reservas
                system(clear);
                break;
            case 7:
                //Volver al men� principal
                break;
            default:
                system(clear);
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion!=7){  //limpia el buffer
             //Si la opcion elegida NO es 7. (pausa la ejecuci�n hasta que el usuario presione enter y
            //limpiar el buffer de entrada para que no queden caracteres pendientes que arruinen la pr�xima lectura.)
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
        system(clear);
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
            case 1: { // Submen� Peliculas
                int opcionPeli = -1;
                while(opcionPeli != 0){
                    system(clear);
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
                        case 0: printf("Volviendo al men� admin...\n"); break;
                        default: printf("Opci�n inv�lida\n");
                    }

                    if(opcionPeli != 0){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }
            case 2: { // Submen� Salas
                int opcionSala = -1;
                while(opcionSala != 5){
                    system("cls");
                    printf("\n--- GESTI�N DE SALAS ---\n");
                    printf("1. Alta de sala\n");
                    printf("2. Baja de sala\n");
                    printf("3. Modificaci�n de sala\n");
                    printf("4. Listar salas\n");
                    printf("5. Volver al men� anterior\n");
                    printf("Ingrese opci�n: ");
                    scanf("%d", &opcionSala);

                    switch(opcionSala) {
                        case 1: altaSala(); break;
                        case 2: bajaSala(); break;
                        case 3: modificarSala(); break;
                        case 4: listarSalas(); break;
                        case 5: printf("Volviendo al men� anterior...\n"); break;
                        default: printf("Opci�n inv�lida.\n");
                    }

                    if(opcionSala != 5){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                    printf("2. Baja de Pelicula\n");
                    printf("3. Modificion de Pelicula\n");
                    printf("4. Listar Peliculas\n");
                    printf("0. Volver\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcionPeli);

                    switch(opcionPeli){
                        case 1:
                            altaPeli();
                            break;
                        case 2:
                            bajaPeli();
                            break;
                        case 3:
                            modificacionPeli();
                            break;
                        case 4:
                            listaDePelis();
                            break;
                        case 0:
                            printf("Volviendo al menu admin\n");
                            break;
                        default:
                            printf("Opcion invalida\n");
                    }

                    printf("Presione Enter para continuar...");
                    getchar(); //limpia buffer
                    getchar(); //espera enter
                }
                break;
            }
            case 2:
                system(clear);
                break;
            case 3:
                system(clear);
                break;
            case 4:
                system(clear);
                break;
            case 5:
                system(clear);
                break;
            }
            case 6:
                printf("Volviendo al menu principal...\n");
                break;
            default:
                printf("Opci�n inv�lida\n");
                system(clear);
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

    } while(opcion != 6);
}
