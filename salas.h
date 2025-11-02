#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

#define MAX_SALAS 15
#define MAX_FILAS 16 // filas de la A a la P
#define MAX_COLUMNAS 17

typedef struct {
    int id;
    int butacas[MAX_FILAS][MAX_COLUMNAS];
    int activo;
} Sala;

int generarIdSala();
void altaSala();
void bajaSala();
void modificarSala();
void listarSalas();
void menuGestionSalas();

#endif
