#ifndef ids_h
#define ids_h

//Entidades de lo que queremos que tena ID, con enum, enumeramos las entidades con n umeros enteros
typedef enum {
    ENTIDAD_PELICULA,
    ENTIDAD_SALA,
    ENTIDAD_CLIENTE,
    ENTIDAD_FUNCION,
    ENTIDAD_RESERVA
} TipoEntidad;

int generarId(TipoEntidad tipo);

#endif
