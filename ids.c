#include "ids.h"

//con static evitamos que se puedan modificar las variables fuera de ids.c sin querer
static int idPelicula = 0;
static int idSala     = 0;
static int idCliente  = 0;
static int idFuncion  = 0;
static int idReserva  = 0;

//devuelve un id segun la entidad que elijamos
int generarId(TipoEntidad tipo) {
    switch(tipo) {
        case ENTIDAD_PELICULA: return ++idPelicula;
        case ENTIDAD_SALA:     return ++idSala;
        case ENTIDAD_CLIENTE:  return ++idCliente;
        case ENTIDAD_FUNCION:  return ++idFuncion;
        case ENTIDAD_RESERVA:  return ++idReserva;
        default:               return 1; // error, tipo no encontrado
    }
}
