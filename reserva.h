#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include <stdbool.h>
#include "estructuras.h"
#include "fecha.h"
#include "funciones.h"

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
    int cantidad;
    int butaca[MAX_BUTACAS_RESERVA];
    EstadoReserva estado;
    fechaCompleta fechaReserva;
} Reserva;

extern int cantidadReservas;
extern Reserva reservas[MAX_RESERVAS];
extern int asientosDisponibles;
int reservasActivasDeCliente(int idCliente, int idFuncion);

void reservar();
void verMisReservas();
void cancelarReserva();
void mostrarButacasDisponibles();
void asistencia(int idFuncion);

int obtenerDiaSemana(Fecha fecha);
int aplicarDescuento(Funcion funcion, int precioBase);

#endif // RESERVA_H_INCLUDED
