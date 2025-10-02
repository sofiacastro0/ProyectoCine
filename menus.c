#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "peliculas.h"
#include "ids.h"
#include "clientes.h"
#include "util.h"

void inicioCliente() {
    int opcion=1;
    char tecla;
        limpiarPantalla();
        printf("INICIAR SESION \n");
        printf("1. Ingresar con email y contraseña\n");
        printf("2. Registrarse\n");
        printf("0. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    // Aca va la lógica de login
                    if (iniciarSesion()) {
                        menuCliente();
                    }
                    break;
                case 2:
                    registrar();
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }

            if(opcion != 0){
            printf("Presione Enter para continuar.");
            getchar();
        }
}

void menuCliente(){
    int opcion=1;
    char tecla;

    do {
        limpiarPantalla();
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
                limpiarPantalla();
                break;
            case 2:
                //Buscar funciones por película
                limpiarPantalla();
                break;
            case 3:
                //Ver butacas disponibles
                limpiarPantalla();
                break;
            case 4:
                //Reservar butacas
                limpiarPantalla();
                break;
            case 5:
                //Cancelar reserva
                limpiarPantalla();
                break;
            case 6:
                //Ver mis reservas
                limpiarPantalla();
                break;
            case 7:
                //Volver al menú principal
                break;
            default:
                limpiarPantalla();
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
                char teclaPeli;
                while(opcionPeli != 0){
                    limpiarPantalla();
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
                limpiarPantalla();
                break;
            case 3:
                limpiarPantalla();
                break;
            case 4:
                limpiarPantalla();
                break;
            case 5:
                limpiarPantalla();
                break;
            case 6:
                break;
            default:
                limpiarPantalla();
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion != 6){
            printf("Presione Enter para continuar.");
            getchar();
        }

    } while (opcion!=6);
}

