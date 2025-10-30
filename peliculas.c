#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "peliculas.h"
#include "ids.h"

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

    // [^\n] Lee una línea completa (con espacios incluidos) hasta que el usuario aprieta Enter. Sino nos lee solo la primera palabra del titulo de las peliculas

    limpiarPantalla();
    printf("---- Alta de pelicula ----\n\n");
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

void bajaPeli() {
    if (cantidadPelis==0){
        printf("No hay peliculas registradas\n");
        return;
    }

    int idBuscado;
    printf("Ingrese el ID de la pelicula a dar de baja: ");
    scanf("%d",&idBuscado);

    for (int i=0; i<cantidadPelis;i++){
        if (peliculas[i].id==idBuscado){
            if (peliculas[i].altaObaja == 0){
                printf("Esta pelicula ya fue dada de baja\n");
            } else {
                peliculas[i].altaObaja = 0;
                printf("La pelicula se dio de baja correctamente\n");  // falta confirmacion
            }
            return;
        }
    }
}

void modificacionPeli() {
    int encontrado=0;
    int i=0;
    int idBuscado;
    Pelicula modificacion;

    if (cantidadPelis==0){
        printf("No hay peliculas registradas\n");
        return;
    }

    printf("Ingrese el ID de la pelicula a modificar: ");
    scanf("%i",&idBuscado);

    while (encontrado != 1 && i < cantidadPelis){
        if (peliculas[i].id == idBuscado){
            encontrado = 1;
            //Agrego la info de la peli a modificar a la variable, para poder mantener ID y "AltaOBaja"
            modificacion = peliculas[i];

            if (peliculas[i].altaObaja == 0) {
                printf("La pelicula esta dada de baja.\n");
                return;
            }

            printf("Reingrese titulo: ");
            scanf(" %[^\n]", modificacion.titulo);

            printf("Reingrese duracion (minutos): ");
            scanf("%d", &modificacion.duracion);

            printf("Reingrese clasificacion (ATP, +13, +16, +18): ");
            scanf(" %s", modificacion.clasificacion);

            printf("Reingrese idioma: ");
            scanf(" %[^\n]", modificacion.idioma);

            printf("Reingrese genero: ");
            scanf(" %[^\n]", modificacion.genero);

            printf("Reingrese formato (2D, 3D, 4D): ");
            scanf(" %s", modificacion.formato);

            peliculas[i] = modificacion;
            printf("Pelicula ID %d modificada correctamente.\n", peliculas[i].id);
            return;
        }
        i++;
    }
    printf("No se ha encontrado ese ID.\n");
}


