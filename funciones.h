#include <stdbool.h>
#include "estructuras.h"

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define CANT_MAX_FUNCIONES 100

typedef struct {
    int id;
    int altaObaja;
    int idPelicula;
    int idSala;
    Fecha fecha;
    Hora horaInicio;
    int duracionConLimpieza;
    int precio;
    int cantidadReservas;
    int reservasAsistidas;
} Funcion;

extern Funcion funciones[CANT_MAX_FUNCIONES];
extern int cantFunciones;

void altaFuncion();
void bajaFuncion();
void modificarFuncion();

void listarFunciones();

int fechaFuncionValida(Fecha fecha, Hora hora);
bool precioValido(int precio);
bool hayDisponibilidadEnFuncion(int idFuncion);
void actualizarReservasAsistidas();

void menuBuscarFunciones();

void buscarFuncionesPorHorario();
void buscarFuncionesPorPelicula();
void buscarFuncionesPorIdioma();
void buscarFuncionesPorGenero();
void buscarFuncionesPorDisponibilidad();

int fechasIguales(Fecha a, Fecha b);
int horaEnMinutos(Hora hora);
int haySolapamiento(int ix, int idSala, Fecha fecha, Hora horaInicio, int duracion);
int funcionYaEmpezo(Funcion funcion);
int butacasDisponibles(Funcion funcion);

#endif // FUNCIONES_H_INCLUDED
