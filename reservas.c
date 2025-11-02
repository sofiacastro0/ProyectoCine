#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "ids.h"
#include "salas.h"
#include "clientes.h"
#include "peliculas.h"
#include "funciones.h"
#include "reserva.h"
#include "estructuras.h"


extern Funcion funciones[];
extern int cantFunciones;

extern Pelicula peliculas[];
extern int cantidadPelis;

extern Cliente clientes[];
extern int cantClientes;

Reserva reservas[MAX_RESERVAS];
int cantidadReservas = 0;


int clasificacionAInt(const char *clasificacion) {
    if (strcmp(clasificacion, "ATP") == 0) return 0;
    if (clasificacion[0] == '+') return atoi(clasificacion + 1); //atoi pasa de string a num entero
    return atoi(clasificacion);
}

int edadMinima(int edadCliente, int clasificacion) {
    if (clasificacion == 0) return 1; // ATP seria 0
    return edadCliente >= clasificacion;
}
//ver esto pq no sé usar time
void sugerirFuncionesAlt(Funcion funcionAlt) {
    printf("Sugerencias:\n");
    for (int i = 0; i < cantFunciones; i++) {
        if (funciones[i].fecha.dia == funcionAlt.fecha.dia && funciones[i].idPelicula != funcionAlt.idPelicula) {
            printf("Películas en la misma fecha (ID función %d)\n", funciones[i].id);
        } else if (funciones[i].idPelicula == funcionAlt.idPelicula && funciones[i].id != funcionAlt.id) {
            printf("Mismo título, otroo horario (ID función %d)\n", funciones[i].id);
        }
    }
}

void reservar() {
    int dni, idFuncion, entradas;

    printf("Ingrese DNI: ");
    scanf("%d", &dni);

    int posCliente = -1;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].dni == dni && clientes[i].altaObaja) {
            posCliente = i;
            break;
        }
    }

    if (posCliente == -1) {
        printf("DNI no encontrado.\n");
        return;
    }

    printf("Ingrese ID de la función elegida: ");
    scanf("%d", &idFuncion);

    int posFuncion = -1;
    for (int j = 0; j < cantFunciones; j++) {
        if (funciones[j].id == idFuncion && funciones[j].altaObaja) {
            posFuncion = j;
            break;
        }
    }

    if (posFuncion == -1) {
        printf("No se encontró la función con ese ID.\n");
        return;
    }

    int clasificacionNum = clasificacionAInt(
        peliculas[funciones[posFuncion].idPelicula].clasificacion);

    if (!edadMinima(clientes[posCliente].edad, clasificacionNum)) {
        printf("El cliente no cumple con la edad mínima.\n");
        return;
    }


int maxEntradas;

if (clientes[posCliente].edad >= 18) {
    maxEntradas = 5;
} else {
    maxEntradas = 1;
}
printf("¿Cuántas entradas desea reservar? (maximo %d):", maxEntradas);
scanf("%d", &entradas);

if (entradas > maxEntradas) {
    printf("Supera el límite permitido.\n");
    return;
}

    int disponibles = (MAX_FILAS*MAX_COLUMNAS)-funciones[posFuncion].cantidadReservas;
    if (entradas > disponibles) {
        printf("No hay suficientes butacas.\n");
        sugerirFuncionesAlt(funciones[posFuncion]);
        return;
    }

    Reserva nueva;
    nueva.id = generarId(ENTIDAD_RESERVA);
    nueva.idCliente = clientes[posCliente].id;
    nueva.idFuncion = funciones[posFuncion].id;
    nueva.cantidad = entradas;
    nueva.estado.activa = 1;

    reservas[cantidadReservas++] = nueva;
    funciones[posFuncion].cantidadReservas += entradas;

    char peliculaReservada[50];

    for (int i = 0; i < cantidadPelis; i++) {
        if (peliculas[i].id == funciones[posFuncion].idPelicula) {
            strcpy(peliculaReservada, peliculas[i].titulo);
        }
    }

    printf("\nReserva generada con ID: %d\n", nueva.id);
    printf("Datos de la funcion:\n\nID Funcion: %d | Pelicula: %s | Sala: %d | Fecha y hora: %d/%d/%d - %02d:%02d",
           funciones[posFuncion].id,
           peliculaReservada,
           funciones[posFuncion].idSala,
           funciones[posFuncion].fecha.dia,
           funciones[posFuncion].fecha.mes,
           funciones[posFuncion].fecha.anio,
           funciones[posFuncion].horaInicio.hora,
           funciones[posFuncion].horaInicio.minuto);

   printf("\n\nPrecio por entrada: $%d\nCantidad de entradas: %d\n\nTotal a pagar: $%d\n\n",
        funciones[posFuncion].precio,
        nueva.cantidad,
        funciones[posFuncion].precio*nueva.cantidad);
}

void verMisReservas() {
    int dni;
    printf("Ingrese su DNI: ");
    scanf("%d", &dni);
    getchar(); // limpia el '\n' que queda en el buffer

    int idCliente = -1;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].dni == dni) {
            idCliente = clientes[i].id;
            break;
        }
    }

    if (idCliente == -1) {
        printf("Cliente no encontrado.\n");
        printf("Presione Enter para continuar...");
        getchar();
        return;
    }

    printf("\nReservas del cliente \n");
    int tieneReservas = 0;
    for (int i = 0; i < cantidadReservas; i++) {
        if (reservas[i].idCliente == idCliente && reservas[i].estado.activa) {
            tieneReservas = 1;
            printf("ID Reserva: %d | Función: %d | Entradas: %d\n", reservas[i].id, reservas[i].idFuncion, reservas[i].cantidad);

            int posFuncion = reservas[i].idFuncion;
            char peliculaReservada[50];

            for (int i = 0; i < cantidadPelis; i++) {
                if (peliculas[i].id == funciones[posFuncion].idPelicula) {
                    strcpy(peliculaReservada, peliculas[i].titulo);
                }
            }

            printf("Pelicula: %s | Sala: %d | Fecha y hora: %d/%d/%d - %02d:%02d\n\n",
                   peliculaReservada,
                   funciones[posFuncion].idSala,
                   funciones[posFuncion].fecha.dia,
                   funciones[posFuncion].fecha.mes,
                   funciones[posFuncion].fecha.anio,
                   funciones[posFuncion].horaInicio.hora,
                   funciones[posFuncion].horaInicio.minuto);
        }
    }

    if (!tieneReservas)
        printf("No tiene reservas activas.\n");

         printf("Presione Enter para continuar...");
         getchar();
}


void cancelarReserva() {
    int dni;
    printf("Ingrese su DNI: ");
    scanf("%d", &dni);
    getchar(); // limpia el '\n' que queda en el buffer

    int idCliente = -1;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].dni == dni) {
            idCliente = clientes[i].id;
            break;
        }
    }

    if (idCliente == -1) {
        printf("Cliente no encontrado.\n");
        printf("Presione Enter para continuar...");
        getchar();
        return;
    }

    int idReserva;
    printf("Ingrese el ID de la reserva a cancelar: ");
    scanf("%d", &idReserva);

    for (int i = 0; i < cantidadReservas; i++) {
        if (reservas[i].id == idReserva && reservas[i].estado.activa) {
            reservas[i].estado.activa = 0;

            for (int j = 0; j < cantFunciones; j++) {
                if (funciones[j].id == reservas[i].idFuncion) {
                    funciones[j].cantidadReservas -= reservas[i].cantidad;
                    break;
                }
            }
            printf("Reserva cancelada.\n");
            return;
        }
    }
    printf("No se encontró la reserva.\n");
}

void mostrarButacasDisponibles() {
    int idFuncion;
    printf("Ingrese ID de la función: ");
    scanf("%d", &idFuncion);
    getchar();

    for (int i = 0; i < cantFunciones; i++) {
        if (funciones[i].id == idFuncion) {
            int disponibles = (MAX_FILAS*MAX_COLUMNAS)-funciones[i].cantidadReservas;
            printf("Butacas disponibles: %d\n", disponibles);
            printf("Presione Enter para continuar...");
            getchar(); // espera a que el usuario presione Enter
            return;
        }
    }
    printf("No se encontró la función.\n");
    printf("Presione Enter para continuar...");
    getchar();
}

//

void asistencia(int idFuncion) {
    int asistencia = 0;

    for (int i = 0; i < cantidadReservas; i++) {
        if (reservas[i].idFuncion == idFuncion && reservas[i].estado.activa) {
            reservas[i].estado.asistida = 1;
            asistencia = 1;
        }
    }

    if (asistencia) {
        printf("Todas las reservas activas para la función %d han sido marcadas como asistidas (1).\n", idFuncion);
    } else {
        printf("No hay reservas activas para la función con ID: %d.\n", idFuncion);
    }
}

