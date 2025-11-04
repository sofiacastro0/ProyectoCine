#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "estructuras.h"
#include "ids.h"
#include "clientes.h"
#include "peliculas.h"
#include "salas.h"
#include "funciones.h"

extern Cliente clientes[100];
extern int cantClientes;

extern Pelicula peliculas[cant_max_peliculas];
extern int cantidadPelis;

extern Sala salas[MAX_SALAS];
extern int cantidadSalas;

extern Funcion funciones[100];
extern int cantFunciones;

void cargarClientesDePrueba() {
    const char* nombres[10] = {
        "Abril", "Juan", "Maria", "Carlos", "Ana",
        "Pedro", "Lucia", "Miguel", "Sofia", "Diego"
    };
    const int dnis[10] = {
        12345678, 87654321, 23456789, 34567890, 45678901,
        56789012, 67890123, 78901234, 89012345, 90123456
    };

    for (int i = 0; i < 10; i++) {
        clientes[i].id = generarId(ENTIDAD_CLIENTE);
        clientes[i].dni = dnis[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].altaObaja = 1;
    }
    cantClientes = 10;
}



void cargarPeliculasDePrueba() {
    const char* titulos[10] = {
        "No soy un hombre facil", "Tierra de osos", "Iron Man 3",
        "Interstellar", "Clore", "Infinity War", "Matrix",
        "Toy Story", "Avatar", "Jurassic Park"
    };
    const char* generos[10] = {
        "Comedia", "Animacion", "Accion",
        "Ciencia Ficcion", "Drama", "Accion",
        "Accion", "Animacion", "Ciencia Ficcion", "Aventura"
    };
    const char* idiomas[10] = {
        "Español","Español","Ingles","Ingles","Español",
        "Ingles","Español","Español","Ingles","Ingles"
    };
    const int duraciones[10] = {105, 80, 130, 170, 95, 150, 120, 90, 160, 125};

    for (int i = 0; i < 10; i++) {
        peliculas[i].id = generarId(ENTIDAD_PELICULA);
        strcpy(peliculas[i].titulo, titulos[i]);
        strcpy(peliculas[i].genero, generos[i]);
        strcpy(peliculas[i].idioma, idiomas[i]);
        peliculas[i].duracion = duraciones[i];
        peliculas[i].altaObaja = 1;
    }
    cantidadPelis = 10;
}


void cargarSalasDePrueba() {
    for (int s = 0; s < 10; s++) {
        salas[s].id = generarId(ENTIDAD_SALA);
        salas[s].activo = 1;
        for (int i = 0; i < MAX_FILAS; i++) {
            for (int j = 0; j < MAX_COLUMNAS; j++) {
                salas[s].butacas[i][j] = 0;
            }
        }
    }
    cantidadSalas = 10;
}


void cargarFuncionesDePrueba() {
    for (int f = 0; f < 10; f++) {
        funciones[f].id = generarId(ENTIDAD_FUNCION);
        funciones[f].idPelicula = peliculas[f].id;
        funciones[f].idSala = salas[f].id;
        funciones[f].fecha.dia = 1 + f;
        funciones[f].fecha.mes = 11;
        funciones[f].fecha.anio = 2025;
        funciones[f].horaInicio.hora = 14 + f;
        funciones[f].horaInicio.minuto = 0;
        funciones[f].precio = 300 + f * 50;
        funciones[f].altaObaja = 1;
    }
    cantFunciones = 10;
}

void cargarDatosDePrueba() {
    cargarClientesDePrueba();
    cargarPeliculasDePrueba();
    cargarSalasDePrueba();
    cargarFuncionesDePrueba();
}
