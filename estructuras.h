#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#define MAX_BUTACAS_RESERVA 10

typedef struct {  //fecha de nacimiento
    int dia, mes, anio;
} Fecha;

typedef struct {
    int hora, minuto;
} Hora;

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
    int butaca[5];                 // numero de asiento reservado
    EstadoReserva estado;         // activa, cancelada o asistida
} Reserva;

#endif // ESTRUCTURAS_H_INCLUDED
