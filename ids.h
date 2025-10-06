#ifndef ids_h
#define ids_h

//Entidades de lo que queremos que tena ID, con enum, enumeramos las entidades con numeros enteros de 0 en adelante y se enumera solo si se agregan mas
typedef enum {
    ENTIDAD_PELICULA,
    ENTIDAD_SALA,
    ENTIDAD_CLIENTE,
    ENTIDAD_FUNCION,
    ENTIDAD_RESERVA
} TipoEntidad;

int generarId(TipoEntidad tipo);

#endif
