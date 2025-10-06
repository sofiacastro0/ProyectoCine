#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define MAX_BUTACAS_RESERVA 10

typedef struct {
    int hora, minuto;
} Hora;

typedef struct {
    int   id;
    int   idPelicula;
    int   idSala;
    Fecha fecha;
    Hora  horaInicio;
    int   duracionConLimpieza;
    int   precio;
} Funcion;

typedef struct {
    int   id;
    int   idCliente;
    int   idFuncion;
    int   butaca;                 // numero de asiento reservado
    EstadoReserva estado;         // activa, cancelada o asistida
} Reserva;

#endif // ESTRUCTURAS_H_INCLUDED
