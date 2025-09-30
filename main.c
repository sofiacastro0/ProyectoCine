#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menus.h"
#include "clientes.h"

//CAMBIAR TODOS LOS "cls" POR "clear"


int main() {
    int seleccion=1;
    char tecla;

        while(seleccion!=0){
            //MENU PRINCIPAL
            menuPrincipal();

            switch(seleccion){
                case 1: //CLIENTE

                    system("cls");
                    printf("------ INICIAR SESION ------\n");
                    printf("1. Ingresar con email y contraseña\n");
                    printf("2. Registrarse\n");
                    printf("0. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d",&seleccion);

                    switch(seleccion){
                        case 1:
                            break;
                        case 2:
                            registrar();
                            break;
                    }

                    menuCliente();
                    break;

                case 2: //ADMIN
                    menuAdmin();
                    break;

                case 0: //SALIR
                    break;

                default:
                    system("cls");
                    printf("La opcion %d no existe en el menu.\n",seleccion);
                    break;
            }

            if(seleccion!=0 && seleccion != 1 && seleccion != 2){  //limpia el buffer
                printf("Presione Enter para continuar.");
                tecla=getchar();

                while ((tecla=getchar()) != '\n' && tecla != EOF) {}
            }

        }

    system("cls");
    printf("Gracias! Vuelva pronto!\n");

    return 0;
}

