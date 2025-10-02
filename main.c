#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "clientes.h"

// Detecta el sistema operativo (Qu� lindoooo) y define clear
#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

int main() {
    int seleccion = -1;  //opci�n elegida en men� principal
    char tecla;

    while (seleccion != 0) {
        // Mostrar menu principal y guardar la opci�n
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

            switch (seleccion) {
                case 1: // CLIENTE
                    system(clear);
                    inicioCliente();
                    break;

                case 2: // admin
                    system(clear);
                    menuAdmin(); //maneja su propio submen�
                    break;

                case 0:
                    break;

                default: //opci�n inv�lida
                    system(clear);
                    break;
            }
    }

    system(clear);
    printf("Gracias! Vuelva pronto!\n");

    return 0;
}
