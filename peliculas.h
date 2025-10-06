#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#define cant_max_peliculas 30
#define cant_char 60

typedef struct  {
    int id;
    int altaObaja;
    int duracion;
    char titulo[cant_char];
    char idioma[cant_char];
    char genero[cant_char];
    char clasificacion[15];
    char formato[15];
} Pelicula;

extern Pelicula peliculas[cant_max_peliculas]; // array global
extern int cantidadPelis;

// funciones
void altaPeli();
void listaDePelis();
void bajaPeli();
void modificarPeli();

#endif
