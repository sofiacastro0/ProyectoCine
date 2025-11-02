#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include <stdbool.h>
#include "estructuras.h"

#define MAX_RESERVAS 1088 //272 * 4 (272 butacas * 4 salas)

typedef struct {
    int activa;
    int cancelada;
    int asistida;
} EstadoReserva;

typedef struct {
    int id;
    int idCliente;
    int idFuncion;
    int cantidad;                 // cantidad de entradas
    int butaca[MAX_BUTACAS_RESERVA];  // asientos reservados
    EstadoReserva estado;         // activa, cancelada o asistida
} Reserva;


extern Reserva reservas[MAX_RESERVAS];
extern int cantidadReservas;


void reservar();
void verMisReservas();
void cancelarReserva();
void mostrarButacasDisponibles();

int obtenerDiaSemana(Fecha fecha);
int aplicarDescuento(Funcion funcion, int precioBase);


#endif // RESERVA_H_INCLUDED
