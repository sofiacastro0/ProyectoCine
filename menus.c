#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "peliculas.h"
#include "ids.h"
#include "clientes.h"
#include "util.h"
#include "salas.h"
#include "funciones.h"
#include "reportes.h"
#include "reservas.h"

void inicioCliente() {
    int opcion=1;
        limpiarPantalla();
        printf("---- Gestion de Clientes ----\n");
        printf("1. Registrarse\n");
        printf("2. Log-in\n");
        printf("0. Volver al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

            switch (opcion) {
                case 1: altaCliente(); break;
                case 2: if (iniciarSesion()){ menuCliente(); } break;
                case 0: break;
                default: printf("Opcion invalida\n"); break;
            }

            if(opcion != 0){
            printf("Presione Enter para continuar.");
            getchar();
            getchar();
        }
}
void menuCliente(){
    int opcion = -1;
    char tecla;

    do {
        limpiarPantalla();
        printf("--------- Menu Cliente -----------\n");
        printf("1. Buscar funciones\n");
        printf("2. Ver butacas disponibles\n");
        printf("3. Reservar butacas\n");
        printf("4. Cancelar reserva\n");
        printf("5. Ver mis reservas\n");
        printf("6. Eliminar cuenta\n");
        printf("7. Editar datos de cuenta\n");
        printf("0. Volver al menu principal\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        while ((tecla = getchar()) != '\n' && tecla != EOF) {}

        switch(opcion) {
            case 1: menuBuscarFunciones(); break;
            case 2: mostrarButacasDisponibles(); break;
            case 3: reservar(); break;
            case 4: cancelarReserva(); break;
            case 5: verMisReservas(); break;
            case 6: bajaCliente(); break;
            case 7: modificacionCliente(); break;
            case 0: break; //Volver al menú principal
            default: printf("La opcion %d no existe en el menu.\n",opcion); break;
        }

        if(opcion!=0){  //limpia el buffer
        //Si la opcion elegida NO es 0. (pausa la ejecución hasta que el usuario presione enter y
        //limpiar el buffer de entrada para que no queden caracteres pendientes que arruinen la próxima lectura.)
            printf("Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while(opcion!=0);

}
//menu administrador//
void menuAdmin(){
    int opcion = -1;
    do {
        limpiarPantalla();
        printf("------- Menu Administrador -------\n");
        printf("1. Gestion de Peliculas\n");
        printf("2. Gestion de Salas\n");
        printf("3. Gestion de Clientes\n");
        printf("4. Funciones\n");
        printf("5. Reportes\n");
        printf("0. Volver al menu principal\n");
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
                while(opcionSala != 0){
                    limpiarPantalla();
                    printf("\n--- GESTIÓN DE SALAS ---\n");
                    printf("1. Alta de sala\n");
                    printf("2. Baja de sala\n");
                    printf("3. Modificacion de sala\n");
                    printf("4. Listar salas\n");
                    printf("0. Volver al menu anterior\n");
                    printf("Ingrese opcion: ");
                    scanf("%d", &opcionSala);

                    switch(opcionSala) {
                        case 1: altaSala(); break;
                        case 2: bajaSala(); break;
                        case 3: modificarSala(); break;
                        case 4: listarSalas(); break;
                        case 0: printf("Volviendo al menú anterior\n"); break;
                        default: printf("Opcion invalida.\n");
                    }

                    if(opcionSala != 0){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 3: {
                    int opcionCliente = -1;
                    while(opcionCliente != 0){
                    limpiarPantalla();
                    printf("\n--- GESTION DE CLIENTES ---\n");
                    printf("1. Listar clientes\n");
                    printf("0. Volver al menu anterior\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &opcionCliente);

                    switch(opcionCliente) {
                        case 1: listarClientes(); break;
                        case 0: printf("Volviendo al menu anterior...\n"); break;
                        default: printf("Opción inválida.\n");
                    }

                    if(opcionCliente != 0){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 4: {
                    int opcionFuncion = -1;
                    while(opcionFuncion != 0){
                    limpiarPantalla();
                    printf("\n--- GESTION DE FUNCIONES ---\n");
                    printf("1. Alta de funcion\n");
                    printf("2. Baja de funcion\n");
                    printf("3. Modificacion de funcion\n");
                    printf("0. Volver al menu anterior\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &opcionFuncion);

                    switch(opcionFuncion) {
                        case 1: altaFuncion(); break;
                        case 2: bajaFuncion(); break;
                        case 3: modificarFuncion(); break;
                        case 0: printf("Volviendo al menú anterior...\n"); break;
                        default: printf("Opción inválida.\n");
                    }

                    if(opcionFuncion != 0){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 5: {
                    int opcionReportes = -1;
                    while(opcionReportes != 0){
                    limpiarPantalla();
                    printf("\n--- REPORTES ---\n");
                    printf("1. Listado de funciones programadas\n");
                    printf("2. Ranking de peliculas mas vistas\n");
                    printf("3. Listado de reservas activas\n");
                    printf("4. Historial de reservas de un cliente\n");
                    printf("5. Reporte de ocupacion promedio por sala\n");
                    printf("6. Ranking de generos mas vistos\n");
                    printf("7. Listado de cancelaciones realizadas\n");
                    printf("8. Listado de clientes con mayor cantidad de reservas en el cine\n");
                    printf("0. Volver al menú anterior\n");
                    printf("Ingrese opción: ");
                    scanf("%d", &opcionReportes);

                    switch(opcionReportes) {
                        case 1: listarFunciones(); break;
                        case 2: peliculasMasVistas(); break;
                        case 3: listarReservasActivas(); break;
                        case 4: historialReservasCliente(); break;
                        case 5: reporteOcupacionSalas(); break;
                        case 6: generosMasVistos(); break;
                        case 7: listadoCancelaciones(); break;
                        case 8: listadoClientesMayorCantidadReservas(); break;
                        case 0: printf("Volviendo al menú anterior...\n"); break;
                        default: printf("Opción inválida.\n");
                    }

                    if(opcionReportes != 0){
                        printf("Presione Enter para continuar...");
                        getchar(); getchar();
                    }
                }
                break;
            }

            case 0: printf("Volviendo al menu principal...\n"); break;
            default:
                printf("Opción inválida\n");
        }

    } while(opcion != 0);
    return;
}
