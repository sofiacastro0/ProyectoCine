#include "peliculas.h"
#include "ids.h"
#include <stdio.h>
#include <string.h>

Pelicula peliculas[cant_max_peliculas];
int cantidadPelis = 0;

void altaPeli() {
    if(cantidadPelis >= cant_max_peliculas) {
        printf("Cantidad maxima de peliculas alcanzada\n");
        return;
    }

    Pelicula alta;
    alta.id = generarId(ENTIDAD_PELICULA);
    alta.altaObaja = 1;

    printf("Ingrese titulo: ");
    scanf(" %[^\n]", alta.titulo);

    printf("Ingrese duracion (minutos): ");
    scanf("%d", &alta.duracion);

    printf("Ingrese clasificacion (ATP, +13, +16, +18): ");
    scanf(" %s", alta.clasificacion);

    printf("Ingrese idioma: ");
    scanf(" %[^\n]", alta.idioma);

    printf("Ingrese genero: ");
    scanf(" %[^\n]", alta.genero);

    printf("Ingrese formato (2D, 3D, 4D): ");
    scanf(" %s", alta.formato);

    peliculas[cantidadPelis] = alta;
    cantidadPelis++;

    printf("Pelicula cargada con ID %d\n", alta.id);
}

void listaDePelis() {
    printf("\n--- Listado de Peliculas ---\n");
    for(int i = 0; i < cantidadPelis; i++){
        if(peliculas[i].altaObaja){
            printf("ID:%d | Titulo:%s | Duracion:%d | Clasificacion:%s | Idioma:%s | Genero:%s | Formato:%s\n",
                   peliculas[i].id,
                   peliculas[i].titulo,
                   peliculas[i].duracion,
                   peliculas[i].clasificacion,
                   peliculas[i].idioma,
                   peliculas[i].genero,
                   peliculas[i].formato);
        }
    }
}

