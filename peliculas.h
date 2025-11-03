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
    int cantGeneros[10];
    char clasificacion[5];
    char formato[15];
} Pelicula;

extern Pelicula peliculas[cant_max_peliculas];
extern int cantidadPelis;

void altaPeli();
void bajaPeli();
void modificacionPeli();
void listaDePelis();

#endif
