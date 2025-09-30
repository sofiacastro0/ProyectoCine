#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

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
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                //Gestion de Peliculas
                system("cls");
                break;
            case 2:
                //Gestion de Salas
                system("cls");
                break;
            case 3:
                //Gestion de Clientes
                system("cls");
                break;
            case 4:
                //Funciones
                system("cls");
                break;
            case 5:
                //Reportes
                system("cls");
                break;
            case 6:
                //Volver al menu principal
                break;

            default:
                system("cls");
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion!=6){  //limpia el buffer
            printf("Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while (opcion!=6);
}
