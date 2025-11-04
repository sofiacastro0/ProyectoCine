#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "clientes.h"
#include "util.h"
#include "datos_prueba.h"

int main() {
    cargarDatosDePrueba();
    int seleccion = -1;
    char tecla;

    do {
        limpiarPantalla();
        printf("---------------------------------\n");
        printf("          Cine Hoyts \n");
        printf("---------------------------------\n");
        printf("1. Operar como Cliente\n");
        printf("2. Operar como Administrador\n");
        printf("0. Salir del sistema\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&seleccion);

            switch (seleccion) {
                case 1: inicioCliente(); break;
                case 2: menuAdmin(); break; //maneja su propio submenú
                case 0: break;
                default: printf("Opcion invalida\n"); break;
            }

            if(seleccion!=0){  //limpia el buffer

                printf("Presione Enter para continuar.");
                tecla=getchar();

                while ((tecla=getchar()) != '\n' && tecla != EOF) {}
            }
    } while (seleccion != 0);

    limpiarPantalla();
    printf("Gracias! Vuelva pronto!\n");

    return 0;
}
