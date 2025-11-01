#include <stdbool.h>
#include "estructuras.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    int id;
    int altaObaja;
    int idPelicula;
    int idSala;
    Fecha fecha;
    Hora horaInicio;
    int duracionConLimpieza;
    int precio;
    int cantidadReservas;   // Cada vez que se hace una reserva = cantidadReservas++
    int reservasAsistidas;
} Funcion;

void altaFuncion();
void bajaFuncion();
void modificarFuncion();
void listarFunciones();
bool fechaFuncionValida(Fecha fecha, Hora hora);
bool precioValido(int precio);

void menuBuscarFunciones();

void buscarFuncionesPorHorario();
void buscarFuncionesPorPelicula();
void buscarFuncionesPorIdioma();
void buscarFuncionesPorGenero();
void buscarFuncionesPorDisponibilidad();
void actualizarReservasAsistidas();

int fechasIguales(Fecha a, Fecha b);
int horaEnMinutos(Hora hora);
int haySolapamiento(int ix, int idSala, Fecha fecha, Hora horaInicio, int duracion);
int funcionYaEmpezo(Funcion funcion);
int butacasDisponibles(Funcion funcion);





#endif // FUNCIONES_H_INCLUDED
