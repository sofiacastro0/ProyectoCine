#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"
#include "peliculas.h"
#include "salas.h"
#include "util.h"
#include "ids.h"
#include "fecha.h"
#include "estructuras.h"

#define CANT_MAX_FUNCIONES 100
Funcion funciones[CANT_MAX_FUNCIONES];
int cantFunciones = 0;

// FALTAN ALGUNAS VALIDACIONES

void altaFuncion(){

    if(cantFunciones >= CANT_MAX_FUNCIONES ){
        printf("No se pueden registrar mas funciones.\n");
        return;
    }

    Funcion alta;
    alta.id = generarId(ENTIDAD_FUNCION);
    alta.altaObaja = 1;

    bool errorFechaFuncion=false;
    bool errorHoraFuncion=false;
    bool errorPrecio=false;
    bool encontrado=false;
    int dia, mes, anio, hora, minuto, precio;
    int i=0, idBuscado;

    fechaCompleta hoy = fecha_actual();

    limpiarPantalla();
    printf("---- Alta Funcion ----\n\n");

    printf("Ingrese ID de pelicula: ");
    scanf("%d", &idBuscado);

    if (cantidadPelis==0){
        printf("No hay peliculas registradas\n");
        return;
    }

    while (i<cantidadPelis && !encontrado) {
        if (peliculas[i].id==idBuscado){
            encontrado = true;
            if (peliculas[i].altaObaja == 0){
                printf("Esta pelicula no esta disponible\n");
            } else {
                alta.idPelicula = peliculas[i].id;
                printf("Se selecciono pelicula correctamente\n");  // falta confirmacion
                alta.duracionConLimpieza = peliculas[i].duracion + 30;
                }
        }
        i++;
    }

    if (!encontrado) {
        printf("No hay una pelicula con ese ID\n");
        return;
    }

    printf("Ingrese ID de sala: ");
    scanf("%d", &alta.idSala);

    printf("Fecha actual: ");
    mostrar_fecha(hoy);
    printf("\n");

    do {
    printf("Ingrese la fecha para la funcion (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &dia, &mes, &anio);

        fechaCompleta fechaFuncion = {dia, mes, anio, -1, -1};

        if (fecha_es_valida(fechaFuncion) && fechaFuncionValida(dia,mes,anio)){
            alta.fecha.dia = dia;
            alta.fecha.mes = mes;
            alta.fecha.anio = anio;
            errorFechaFuncion=false;
        } else {
            errorFechaFuncion=true;
            printf("ERROR: Fecha invalida\n");
        }
    } while (errorFechaFuncion);

    do {
    printf("Ingrese la hora para la funcion (hh:mm): ");
    scanf(" %d:%d", &hora, &minuto);
        fechaCompleta horaFuncion = {dia, mes, anio, hora, minuto};
        if (fecha_es_valida(horaFuncion)){
            alta.horaInicio.hora = hora;
            alta.horaInicio.minuto = minuto;
            errorHoraFuncion=false;
        } else {
            errorHoraFuncion=true;
            printf("ERROR: Hora invalida\n");
        }
    } while (errorHoraFuncion);

        do {
    printf("Ingrese el precio de la entrada:  $");
    scanf("%d", &precio);
        if (precioValido(precio)){
            alta.precio = precio;
            errorPrecio=false;
        } else {
            errorPrecio=true;
            printf("ERROR: Precio invalido\n");
        }
    } while (errorPrecio);

    //Guardar en el array
    funciones[cantFunciones] = alta;
    cantFunciones++;

    printf("Funcion creada correctamente.\n");

        printf("Presione Enter para continuar...");
            getchar(); //limpia buffer
            getchar(); // espera enter
}

void bajaFuncion(){

        if (cantFunciones==0){
        printf("No hay funciones registradas\n");
        return;
    }

    int idBuscado;
    printf("Ingrese el ID de la funcion a dar de baja: ");
    scanf("%d",&idBuscado);

    for (int i=0; i<cantFunciones;i++){
        if (funciones[i].id==idBuscado){
            if (funciones[i].altaObaja == 0){
                printf("Esta funcion ya fue dada de baja\n");
            } else {
                funciones[i].altaObaja = 0;
                printf("La funcion se dio de baja correctamente\n");   // falta confirmacion
            }
            return;
        }
    }

}

void modificarFuncion(){

    Funcion modificacion;
    int opcion=-1, i=0;
    bool encontrado=false;
    bool errorFechaFuncion=false;
    bool errorHoraFuncion=false;
    bool errorPrecio=false;

    if (cantFunciones==0){
        printf("No hay funciones registradas\n");
        return;
    }

    int idBuscado;
    printf("Ingrese el ID de la funcion a modificar: ");
    scanf("%d",&idBuscado);

    while (i<cantFunciones && !encontrado) {
        if (funciones[i].id==idBuscado){
            encontrado=true;
            printf("¿Que dato quiere modificar?\n");
            printf("1. Sala\n");
            printf("2. Fecha y hora\n");
            printf("3. Precio\n");
            printf("4. Volver atras\n");
            scanf("%d",&opcion);

                switch (opcion) {
                    case 1: printf("ID Sala anterior: %d. Nueva Sala: ",funciones[i].idSala);
                            scanf("%d", &modificacion.idSala);
                            funciones[i].idSala = modificacion.idSala;
                            break;

                    case 2: do {
                            printf("Fecha y hora anterior: %d/%d/%d - %d:%d Nueva Fecha: ",funciones[i].fecha.dia,funciones[i].fecha.mes,funciones[i].fecha.anio,funciones[i].horaInicio.hora,funciones[i].horaInicio.minuto);
                            scanf(" %d/%d/%d", &modificacion.fecha.dia, &modificacion.fecha.mes, &modificacion.fecha.anio);

                                fechaCompleta fechaFuncion = {modificacion.fecha.dia, modificacion.fecha.mes, modificacion.fecha.anio, -1, -1};

                                if (fecha_es_valida(fechaFuncion) && fechaFuncionValida(modificacion.fecha.dia, modificacion.fecha.mes, modificacion.fecha.anio)){
                                    funciones[i].fecha.dia = modificacion.fecha.dia;
                                    funciones[i].fecha.mes = modificacion.fecha.mes;
                                    funciones[i].fecha.anio = modificacion.fecha.anio;
                                    errorFechaFuncion=false;
                                } else {
                                    errorFechaFuncion=true;
                                    printf("ERROR: Fecha invalida\n");
                                }
                            } while (errorFechaFuncion);

                            do {
                            printf("Nueva hora: ");
                            scanf(" %d:%d", &modificacion.horaInicio.hora, &modificacion.horaInicio.minuto);

                                fechaCompleta horaFuncion = {modificacion.fecha.dia, modificacion.fecha.mes, modificacion.fecha.anio, modificacion.horaInicio.hora, modificacion.horaInicio.minuto};

                                if (fecha_es_valida(horaFuncion)){
                                    funciones[i].horaInicio.hora = modificacion.horaInicio.hora;
                                    funciones[i].horaInicio.minuto = modificacion.horaInicio.minuto;
                                    errorHoraFuncion=false;
                                } else {
                                    errorHoraFuncion=true;
                                    printf("ERROR: Hora invalida\n");
                                }

                            } while (errorHoraFuncion);
                            break;

                    case 3: do {
                            printf("Precio anterior: $%d. Nuevo Precio: $",funciones[i].precio);
                            scanf(" %d", &modificacion.precio);
                            funciones[i].precio = modificacion.precio;

                                if (precioValido(modificacion.precio)){
                                    funciones[i].precio = modificacion.precio;
                                    errorPrecio=false;
                                } else {
                                    errorPrecio=true;
                                    printf("ERROR: Precio invalido\n");
                                }

                            } while (errorPrecio);

                            break;




                    case 4: break;
                    default: printf("Opcion invalida\n"); break;
                }
                return;
        }
        i++;
    }

    if (!encontrado) {
        printf("No se encontró un cliente con ese DNI.\n");
    }
}

void listarFunciones(){

    printf("\n--- Listado de Funciones ---\n");
        if (cantFunciones == 0) {
            printf("No hay funciones registrados.\n");
            return;
        }

    for(int i=0; i<cantFunciones; i++){

        if(funciones[i].altaObaja){
            printf("ID:%d | Pelicula: %d | Sala :%d | Fecha y hora: %d/%d/%d - %d:%d | Precio: %d | Estado: ",
                   funciones[i].id,
                   funciones[i].idPelicula,
                   funciones[i].idSala,
                   funciones[i].fecha.dia,
                   funciones[i].fecha.mes,
                   funciones[i].fecha.anio,
                   funciones[i].horaInicio.hora,
                   funciones[i].horaInicio.minuto,
                   funciones[i].precio);
        }

        if (funciones[i].altaObaja == 1) {
            printf("Funcion activa\n");
        } else {
            printf("Funcion cancelada\n");
        }
    }
}

bool fechaFuncionValida(int dia, int mes, int anio){

    fechaCompleta hoy = fecha_actual();

    // Si el año es menor al actual, retorna que es invalido
    if (anio < hoy.anio) return false;

    // Si el año es el mismo, revisa si el mes es valido
    if (anio == hoy.anio && mes < hoy.mes) return false;

    // Si el mes también es el mismo, revisa el día
    if (anio == hoy.anio && mes == hoy.mes && dia < hoy.dia) return false;

    return true;
}
bool precioValido(int precio){
    return (precio > 0);
}
