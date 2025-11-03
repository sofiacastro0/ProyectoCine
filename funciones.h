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
} Funcion;

void altaFuncion();
void bajaFuncion();
void modificarFuncion();
void listarFunciones();
bool fechaFuncionValida(int dia, int mes, int anio);
bool precioValido(int precio);
bool hayDisponibilidadEnFuncion(int idFuncion);

void menuBuscarFunciones();

void buscarFuncionesPorHorario();
void buscarFuncionesPorPelicula();
void buscarFuncionesPorIdioma();
void buscarFuncionesPorGenero();
void buscarFuncionesPorDisponibilidad();


#endif // FUNCIONES_H_INCLUDED
