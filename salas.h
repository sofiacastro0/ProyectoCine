#ifndef salas_h
#define salas_h

#define MAX_SALAS 15
#define MAX_FILAS 10
#define MAX_COLUMNAS 15

typedef struct {
    int id;             // ID único de la sala
    int butacas[MAX_FILAS][MAX_COLUMNAS];      // Cantidad de butacas
    int activo;         // 1 = activa, 0 = eliminada
} Sala;

extern Sala salas[MAX_SALAS];  // Array de salas
extern int cantidadSalas = 0;  // Contador de salas actuales

int generarIdSala();
void altaSala();
void bajaSala();
void modificarSala();
void listarSalas();
void menuGestionSalas();


