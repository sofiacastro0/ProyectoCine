#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "clientes.h"

// Detecta el sistema operativo (Què lindoooo) y define clear
#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

int main() {
    int seleccion = -1;  //opción elegida en menú principal
    char tecla;

    while (seleccion != 0) {
        // Mostrar menu principal y guardar la opción
        seleccion = menuPrincipal();

        switch (seleccion) {
            case 1: // CLIENTE
                system(clear);
                printf("INICIAR SESION \n");
                printf("1. Ingresar con email y contraseña\n");
                printf("2. Registrarse\n");
                printf("0. Volver al menu principal\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &seleccion);

                switch (seleccion) {
                    case 1:
                        // Aca va la lógica de login
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

                menuCliente(); //maneja su propio submenú
                break;

            case 2: // admin
                system(clear);
                menuAdmin(); //maneja su propio submenú
                break;

            case 0:
                break;

            default: //opción inválida
                system(clear);
                break;
        }
    }

    system(clear);
    printf("Gracias! Vuelva pronto!\n");

    return 0;
}
