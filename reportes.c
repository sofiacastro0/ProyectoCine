#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reportes.h"
#include "peliculas.h"
#include "funciones.h"
#include "reserva.h"
#include "clientes.h"
#include "salas.h"
#include "fecha.h"
#include "util.h"

#define CANT_GENEROS 10

char nombresGeneros[CANT_GENEROS][20] = {"Accion", "Aventura", "Ciencia Ficcion", "Fantasia", "Terror", "Comedia", "Romance", "Drama", "Animacion", "Documental"};

void listarFunciones(){

    printf("\n\n--- Listado de Funciones ---\n");
        if (cantFunciones == 0) {
            printf("No hay funciones registrados.\n");
            return;
        }

        actualizarReservasAsistidas();

    for(int i=0; i<cantFunciones; i++){

        if(funciones[i].altaObaja){
            int disponibles = butacasDisponibles(funciones[i]);
            printf("ID:%d | Pelicula: %d | Sala :%d | Fecha y hora: %d/%d/%d - %02d:%02d | Precio: $%d | Reservas activas: %d | Reservas asistidas: %d",
                   funciones[i].id,
                   funciones[i].idPelicula,
                   funciones[i].idSala,
                   funciones[i].fecha.dia,
                   funciones[i].fecha.mes,
                   funciones[i].fecha.anio,
                   funciones[i].horaInicio.hora,
                   funciones[i].horaInicio.minuto,
                   funciones[i].precio,
                   funciones[i].cantidadReservas,
                   funciones[i].reservasAsistidas);

                if(disponibles > 0) {
                printf(" | Butacas disponibles: %d", disponibles);
                }
            printf(" | Estado: ");
        }

        if (funciones[i].altaObaja == 1) {
            printf("Funcion activa\n");
        } else {
            printf("Funcion cancelada\n");
        }
    }
}
void peliculasMasVistas() {
    printf("\n\n--- Ranking de Peliculas Mas Vistas ---\n");

    if (cantidadPelis == 0) {
        printf("No hay peliculas registradas.\n");
        return;
    }

    int vistasPorPelicula[cant_max_peliculas] = {0}; //pone todo en 0
    int indices[cant_max_peliculas];  // al no saber los titulos compara por indice y reservas asistidas

    for (int i=0; i<cantidadPelis; i++) {
        indices[i] = i;
    }

    for (int i=0; i<cantFunciones; i++) {
        if (funciones[i].altaObaja && funciones[i].reservasAsistidas>0) {
            for (int j=0; j<cantidadPelis; j++) {
                if (peliculas[j].altaObaja && peliculas[j].id == funciones[i].idPelicula) {
                    vistasPorPelicula[j] += funciones[i].reservasAsistidas;
                    break;
                }
            }
        }
    }

    int totalVistas=0;
    for (int i=0; i<cantidadPelis; i++) {
        totalVistas+=vistasPorPelicula[i];
    }

    if (totalVistas==0) {
        printf("No hay funciones vistas todavia.\n");
        return;
    }

    for (int i=0; i<cantidadPelis-1; i++) {
        for (int j=i+1; j<cantidadPelis; j++) {
            if (vistasPorPelicula[indices[j]] > vistasPorPelicula[indices[i]]) {
                int auxIndice = indices[i];
                indices[i] = indices[j];
                indices[j] = auxIndice;
            }
        }
    }

    int posicion=1;
    for (int i=0; i<cantidadPelis; i++) {
        int j = indices[i];
        if (peliculas[j].altaObaja && vistasPorPelicula[j] > 0) {
            printf("%d. %s - %d vistas\n", posicion, peliculas[j].titulo, vistasPorPelicula[j]);
            posicion++;
        }
    }

    printf("\n");
}
void listarReservasActivas() {
    printf("\n\n--- Listado de Reservas Activas por Funcion ---\n");

    int hayReservas = 0;

    for (int i = 0; i < cantFunciones; i++) {
        if (funciones[i].altaObaja) {
            int reservasEnFuncion = 0;

            for (int j = 0; j < cantidadReservas; j++) {
                if (reservas[j].estado.activa && reservas[j].idFuncion == funciones[i].id) {
                    if (reservasEnFuncion == 0) {

                        printf("\nFuncion: %d | Sala: %d | Fecha y Hora: %d/%d/%d - %02d:%02d\n",  //pongo %02d para que muestre 17:00 y no 17:0
                               funciones[i].id,
                               funciones[i].idSala,
                               funciones[i].fecha.dia,
                               funciones[i].fecha.mes,
                               funciones[i].fecha.anio,
                               funciones[i].horaInicio.hora,
                               funciones[i].horaInicio.minuto);

                        reservasEnFuncion = 1;
                    }

                    int clienteEncontrado = 0;
                    char nombreCliente[51];

                    for (int k = 0; k < cantClientes; k++) {
                        if (clientes[k].id == reservas[j].idCliente) {
                            strcpy(nombreCliente, clientes[k].nombre);
                            clienteEncontrado = 1;
                            break;
                        }
                    }

                    if (clienteEncontrado) {
                        printf("Nombre: %s - %d Entradas\n", nombreCliente, reservas[j].cantidad);
                    }

                    hayReservas = 1;
                }
            }
        }
    }

    if (!hayReservas) {
        printf("No hay reservas activas registradas.\n");
    }
}
void historialCliente(int idCliente) {
    int hayReservas=0;  //ponemos la variable "hayReservas?" en 0, para arrancar como si no hubiera ningun tipo de reservas
    char nombre[50];

    //Buscamos al cliente para poder mostrar su nombre e id
    for (int j = 0; j < cantClientes; j++ ) {
        if(clientes[j].id == idCliente){
            strcpy(nombre, clientes[j].nombre); //copiamos el nombre del cliente en una variable nombre
        }
    }

    printf("El historial de reservas del cliente: %s, con ID: %d\n", nombre, idCliente);
    for (int i = 0 ; i < cantidadReservas; i++) {  //Recorremos la cantidad de reservas
        if(reservas[i].idCliente == idCliente){  //Comparamos si el id de la reserva coincide con el id del cliente
            hayReservas = 1;                     //Si encuentra una coincidencia, hay una reserva
            printf("Reserva: %d, funcion %d, cantidad de entradas %d\n", reservas[i].id, reservas[i].idFuncion, reservas[i].cantidad); //Imprimimos los datos de la reserva encontrada

    //Acá evalúa el estado de la reserva (Con la estructura EstadoReserva en reserva.h) y muestra en pantalla el estado dependiendo si tienen un 1 como valor.
            printf ("Estado: ");
            if (reservas[i].estado.activa) {
                printf("Activa\n");
            }
            if (reservas[i].estado.cancelada) {
                printf("Cancelada\n");
            }
            if (reservas[i].estado.asistida) {
                printf("Asistida\n");
            }
        }
    }
    if (!hayReservas) {
        printf("El cliente no tiene reservas\n");
    }
}
//Testear
void reportePromedio() {
    printf("Promedio de ocupacion\n");

    for (int i = 0; i < cantidadSalas; i++) { //recorremos las salas con i
        int totalButacas = MAX_FILAS * MAX_COLUMNAS;
        int totalReservadas = 0; //Inicializo una cumulador de reservas en 0 para la sala actual en i,
        int cantFuncionesSala = 0;//sumamos las butacas reservadas de cada función de la sala (si coincide con el id de la funcion)

        for (int j = 0; j < cantFunciones; j++) { //recorremos la cantidad de funciones con j
            if (funciones[j].idSala == salas[i].id) { //vamos a las funciones y buscamos el id de la sala en la que están (con el for de i), lo igualamos al id de la sala
                totalReservadas += funciones[j].cantidadReservas; //el total de butacas reservadas se suma con las butacas reservadas de cada funcion en cada sala
                cantFuncionesSala++; //incremento en 1 el contador de funciones que pertenecen a la sala
            }
        }

        if (cantFuncionesSala > 0) {
            double promedio = (totalReservadas / (cantFuncionesSala * totalButacas) * 100.0);  //el total de butacas reservadas en esa funcion, dividido las funciones de esa sala * 272 (el total de butacas de esa sala) y todo multiplicado por 100
            printf("Sala ID %d \n  %.2f%% ocupacion promedio (%d funciones)\n", salas[i].id, promedio, cantFuncionesSala);
        }
        else {
            printf("Sala ID %d sin funciones programadas\n", salas[i].id);
        }
    }
}
void generosMasVistos() {
    printf("\n\n--- Ranking de Generos Mas Vistos ---\n");

    int vistasPorGenero[CANT_GENEROS] = {0,0,0,0,0,0,0,0,0,0};

    // Recorre todas las funciones que esten activas
    for (int i=0; i<cantFunciones; i++) {
        if (funciones[i].reservasAsistidas>0) {
            // Busca el genero de la pelicula que sale
            for (int j=0; j<cantidadPelis; j++) {
                if (peliculas[j].id == funciones[i].idPelicula && peliculas[j].altaObaja) {
                    // Sumamos las vistas al género correspondiente
                    if (strcmp(peliculas[j].genero, "Accion") == 0)
                        vistasPorGenero[0] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Aventura") == 0)
                        vistasPorGenero[1] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Ciencia Ficcion") == 0)
                        vistasPorGenero[2] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Fantasia") == 0)
                        vistasPorGenero[3] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Terror") == 0)
                        vistasPorGenero[4] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Comedia") == 0)
                        vistasPorGenero[5] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Romance") == 0)
                        vistasPorGenero[6] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Drama") == 0)
                        vistasPorGenero[7] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Animacion") == 0)
                        vistasPorGenero[8] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Documental") == 0)
                        vistasPorGenero[9] += funciones[i].reservasAsistidas;
                }
            }
        }
    }

    // metodo de ordenamiento descendente
    for (int i=0; i<CANT_GENEROS-1; i++) {
        for (int j=i+1; j<CANT_GENEROS; j++) {
            if (vistasPorGenero[i] < vistasPorGenero[j]) {
                int auxVistas = vistasPorGenero[i];
                vistasPorGenero[i] = vistasPorGenero[j];
                vistasPorGenero[j] = auxVistas;

                // esto cambia en el array el genero que corresponde con su indice
                // ej: si romance(i6) para a ser indice 2, no queda con el nombre del i2 anterior (aventura)
                char auxNombre[20];
                strcpy(auxNombre, nombresGeneros[i]);
                strcpy(nombresGeneros[i], nombresGeneros[j]);
                strcpy(nombresGeneros[j], auxNombre);
            }
        }
    }

    int totalVistas=0;
    for (int i=0; i<CANT_GENEROS; i++) {
        totalVistas += vistasPorGenero[i];
    }

    if (totalVistas == 0) {
        printf("No hay funciones vistas todavia.\n");
        return;
    }

    //muestra el ranking
    int posicion=1;
    for (int i=0; i<CANT_GENEROS; i++) {
        if (vistasPorGenero[i] > 0) {
            printf("%d. %s - %d vistas\n", posicion, nombresGeneros[i], vistasPorGenero[i]);
            posicion++;
        }
    }

    printf("\n");
}
void listadoCancelaciones() {
    limpiarPantalla();
    printf("Reporte de cancelaciones cronologicamente\n");

    for (int i = 0; i < cantidadReservas - 1; i++) {//con este tomamos una reserva del arreglo
        for (int j = i + 1; j < cantidadReservas; j++) { //con este recorremos el resto de reservas canceladas para comparar con cada una
            if (reservas[i].estado.cancelada && reservas[j].estado.cancelada) {
                fechaCompleta fechaEnI = reservas[i].fechaReserva;//cuando encuentra una reserva cancelada en j,
                fechaCompleta fechaEnJ = reservas[j].fechaReserva;//la compara con la de i
                //Digamosle fechas a y b. La a sería la del for I, la b la del j:
                //Las condiciones para comparar fechas serían: (que el año de A sea mayor al año de B), O (Que el año de A,
                // sí sea igual al año de B, (pero entonces deberemos comparar los meses)), O que efectivamente el mes y año de A y B sean iguales
                // y entonces deberemos comparar el día,
                if ((fechaEnI.anio > fechaEnJ.anio) || (fechaEnI.anio == fechaEnJ.anio && fechaEnI.mes > fechaEnJ.mes) ||
                    (fechaEnI.anio == fechaEnJ.anio && fechaEnI.mes == fechaEnJ.mes && fechaEnI.dia >fechaEnJ.dia)) {
                 //En el caso de que haya cambio, usamos un auxiliar para invertir las fechas de cancelacion y que queden ordenadas
                    Reserva temp = reservas[i];
                    reservas[i] = reservas[j];
                    reservas[j] = temp;
                }
            }
        }


      }

  for (int i = 0; i < cantidadReservas; i++) { //recorro reservas para buscar canceladas
    if (reservas[i].estado.cancelada) { //si encuentro
         for (int c = 0; c < cantClientes; c++) { //recorro clientes
            if (clientes[c].id == reservas[i].idCliente) { //y busco quien canceló. Sería que: si el id del cliente coincide con el id del cliente que hizo la reserva, entoncces imprimimos la reserva cancelada
                printf("Cliente:%s \n ID Reserva: %d \n Función: %d \n Entradas: %d\nFecha %d/%d/%d\n",
                clientes[c].nombre,
                reservas[i].id,
                reservas[i].idFuncion,
                reservas[i].cantidad,
                reservas[i].fechaReserva.dia,
                reservas[i].fechaReserva.mes,
                reservas[i].fechaReserva.anio);
            }
        }
    }

  }
          printf("\nPresione Enter para volver al menú de reportes...\n");
getchar(); // espera a que el usuario presione Enter

}
void listadoClientesMayorCantidadReservas(){
    printf("\n\n--- Clientes con Mayor Cantidad de Reservas ---\n");

    if (cantClientes == 0) {
        printf("No hay clientes registrados.\n");
        return;
    }

    if (cantidadReservas == 0) {
        printf("No hay reservas registradas.\n");
        return;
    }

    int reservasPorCliente[cantClientes];
    int indices[cantClientes];

    for (int i = 0; i < cantClientes; i++) {
        reservasPorCliente[i] = 0;
        indices[i] = i;
    }

    for (int i = 0; i < cantidadReservas; i++) {
        if (reservas[i].estado.activa) {
            for (int j = 0; j < cantClientes; j++) {
                if (clientes[j].altaObaja && clientes[j].id == reservas[i].idCliente) {
                    reservasPorCliente[j]++;
                    break;
                }
            }
        }
    }

    int hayReservas = 0;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].altaObaja && reservasPorCliente[i] > 0) {
            hayReservas = 1;
            break;
        }
    }

    if (!hayReservas) {
        printf("No hay reservas activas registradas para los clientes.\n");
        return;
    }

    for (int i = 0; i < cantClientes - 1; i++) {
        for (int j = i + 1; j < cantClientes; j++) {
            if (reservasPorCliente[indices[j]] > reservasPorCliente[indices[i]]) {
                int auxIndice = indices[i];
                indices[i] = indices[j];
                indices[j] = auxIndice;
            }
        }
    }

    int posicion = 1;
    for (int i = 0; i < cantClientes; i++) {
        int idx = indices[i];
        if (clientes[idx].altaObaja && reservasPorCliente[idx] > 0) {
            printf("%d. %s (ID Cliente: %d) - %d reservas activas\n",
                   posicion,
                   clientes[idx].nombre,
                   clientes[idx].id,
                   reservasPorCliente[idx]);
            posicion++;
        }
    }

    printf("\n");

}
