#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reportes.h"
#include "peliculas.h"
#include "funciones.h"

#define CANT_GENEROS 10

char nombresGeneros[CANT_GENEROS][20] = {"Accion", "Aventura", "Ciencia Ficcion", "Fantasia", "Terror", "Comedia", "Romance", "Drama", "Animacion", "Documental"};

void generosMasVistos() {
    printf("\n\n--- Ranking de Generos Mas Vistos ---\n");

    int vistasPorGenero[CANT_GENEROS] = {0,0,0,0,0,0,0,0,0,0};

    // Recorre todas las funciones que esten activas
    for (int i=0; i<cantFunciones; i++) {
        if (funciones[i].reservasAsistidas>0) {
            // Busca el genero de la pelicula que sale
            for (int j=0; j<cantidadPelis; j++) {
                if (peliculas[j].id == funciones[i].idPelicula && peliculas[j].altaObaja) {
                    // Sumamos las vistas al género correspondiente
                    if (strcmp(peliculas[j].genero, "Accion") == 0)
                        vistasPorGenero[0] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Aventura") == 0)
                        vistasPorGenero[1] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Ciencia Ficcion") == 0)
                        vistasPorGenero[2] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Fantasia") == 0)
                        vistasPorGenero[3] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Terror") == 0)
                        vistasPorGenero[4] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Comedia") == 0)
                        vistasPorGenero[5] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Romance") == 0)
                        vistasPorGenero[6] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Drama") == 0)
                        vistasPorGenero[7] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Animacion") == 0)
                        vistasPorGenero[8] += funciones[i].reservasAsistidas;
                    if (strcmp(peliculas[j].genero, "Documental") == 0)
                        vistasPorGenero[9] += funciones[i].reservasAsistidas;
                }
            }
        }
    }

    // metodo de ordenamiento descendente
    for (int i=0; i<CANT_GENEROS-1; i++) {
        for (int j=i+1; j<CANT_GENEROS; j++) {
            if (vistasPorGenero[i] < vistasPorGenero[j]) {
                int auxVistas = vistasPorGenero[i];
                vistasPorGenero[i] = vistasPorGenero[j];
                vistasPorGenero[j] = auxVistas;

                // esto cambia en el array el genero que corresponde con su indice
                // ej: si romance(i6) para a ser indice 2, no queda con el nombre del i2 anterior (aventura)
                char auxNombre[20];
                strcpy(auxNombre, nombresGeneros[i]);
                strcpy(nombresGeneros[i], nombresGeneros[j]);
                strcpy(nombresGeneros[j], auxNombre);
            }
        }
    }

    int totalVistas=0;
    for (int i=0; i<CANT_GENEROS; i++) {
        totalVistas += vistasPorGenero[i];
    }

    if (totalVistas == 0) {
        printf("No hay funciones vistas todavia.\n");
        return;
    }

    //muestra el ranking
    int posicion=1;
    for (int i=0; i<CANT_GENEROS; i++) {
        if (vistasPorGenero[i] > 0) {
            printf("%d. %s - %d vistas\n", posicion, nombresGeneros[i], vistasPorGenero[i]);
            posicion++;
        }
    }

    printf("\n");
}
