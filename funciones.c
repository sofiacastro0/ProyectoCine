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

Funcion funciones[CANT_MAX_FUNCIONES];
int cantFunciones = 0;

// FALTAN ALGUNAS VALIDACIONES y buscar funciones por disponibilidad

void altaFuncion(){

    if(cantFunciones >= CANT_MAX_FUNCIONES ){
        printf("No se pueden registrar mas funciones.\n");
        return;
    }

    Funcion alta;
    alta.id = generarId(ENTIDAD_FUNCION);
    alta.altaObaja = 1;
    alta.cantidadReservas = 0;
    alta.reservasAsistidas = 0;

    bool errorHoraFuncion=false;
    bool errorPrecio=false;
    bool encontrado=false;
    int dia=0, mes=0, anio=0, hora=0, minuto=0, precio=0;
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
                return;
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

    if(!salaEstaActiva(alta.idSala)) {
        printf("La sala seleccionada no esta activa\n");
        return;
    }

    printf("Fecha actual: ");
    mostrar_fecha(hoy);
    printf("\n");

    do {
    printf("Ingrese la fecha para la funcion (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &dia, &mes, &anio);

        Fecha fechaFuncion = {dia, mes, anio};

    printf("Ingrese la hora para la funcion (hh:mm): ");
    scanf(" %d:%d", &hora, &minuto);

        fechaCompleta horaFuncionCompleta = {dia, mes, anio, hora, minuto};
        Hora horaFuncion = {hora, minuto};

        if (fecha_es_valida(horaFuncionCompleta) && fechaFuncionValida(fechaFuncion, horaFuncion)){
            alta.fecha.dia = dia;
            alta.fecha.mes = mes;
            alta.fecha.anio = anio;
            alta.horaInicio.hora = hora;
            alta.horaInicio.minuto = minuto;
            errorHoraFuncion=false;
        } else {
            errorHoraFuncion=true;
            printf("ERROR: Fecha y Hora invalida\n");
        }

    } while (errorHoraFuncion);

    if(haySolapamiento(-1, alta.idSala, alta.fecha, alta.horaInicio, alta.duracionConLimpieza)) {
        printf("No se puede programar la funcion: se superpone con otra en la misma sala\n");
        return;
    }


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

    if (cantFunciones==0){
        printf("No hay funciones registradas\n");
        return;
    }

    actualizarReservasAsistidas();

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
                    case 1: {
                    printf("ID Sala anterior: %d. Nueva Sala: " ,funciones[i].idSala);
                    scanf("%d", &modificacion.idSala);
                    if(!salaEstaActiva(modificacion.idSala)) {
                        printf("La sala seleccionada no esta activa\n");
                        break;
                    }
                    if(haySolapamiento(i, modificacion.idSala, funciones[i].fecha, funciones[i].horaInicio, funciones[i].duracionConLimpieza)) {
                        printf("Esta sala tiene otra funcion en ese horario\n");
                        break;
                    }
                    funciones[i].idSala = modificacion.idSala;
                    printf("Sala actualizada correctamente\n");
                    break;
                }

                    case 2: do {
                            printf("Fecha y hora anterior: %d/%d/%d - %d:%d Nueva Fecha: ",funciones[i].fecha.dia,funciones[i].fecha.mes,funciones[i].fecha.anio,funciones[i].horaInicio.hora,funciones[i].horaInicio.minuto);
                            scanf(" %d/%d/%d", &modificacion.fecha.dia, &modificacion.fecha.mes, &modificacion.fecha.anio);

                            Fecha fechaFuncion = {modificacion.fecha.dia, modificacion.fecha.mes, modificacion.fecha.anio};

                            printf("Nueva hora: ");
                            scanf(" %d:%d", &modificacion.horaInicio.hora, &modificacion.horaInicio.minuto);

                                fechaCompleta horaFuncion = {modificacion.fecha.dia, modificacion.fecha.mes, modificacion.fecha.anio, modificacion.horaInicio.hora, modificacion.horaInicio.minuto};

                                if (fecha_es_valida(horaFuncion)){
                                    funciones[i].fecha.dia = modificacion.fecha.dia;
                                    funciones[i].fecha.mes = modificacion.fecha.mes;
                                    funciones[i].fecha.anio = modificacion.fecha.anio;
                                    funciones[i].horaInicio.hora = modificacion.horaInicio.hora;
                                    funciones[i].horaInicio.minuto = modificacion.horaInicio.minuto;
                                    errorHoraFuncion=false;
                                } else {
                                    errorHoraFuncion=true;
                                    printf("ERROR: Fecha y Hora invalida\n");
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
                            printf("Precio actualizado correctamente\n");

                            break;




                    case 4: break;
                    default: printf("Opcion invalida\n"); break;
                }
                return;
        }
        i++;
    }

    if (!encontrado) {
        printf("No se encontro una funcion con ese ID.\n");
    }
}

void listarFunciones(){

    printf("\n\n--- Listado de Funciones ---\n");
        if (cantFunciones == 0) {
            printf("No hay funciones registrados.\n");
            return;
        }

        actualizarReservasAsistidas();

    for(int i=0; i<cantFunciones; i++){

        if(funciones[i].altaObaja){
            int disponibles = butacasDisponibles(funciones[i]);
            printf("ID:%d | Pelicula: %d | Sala :%d | Fecha y hora: %d/%d/%d - %02d:%02d | Precio: %d | Reservas activas: %d | Reservas asistidas: %d",
                   funciones[i].id,
                   funciones[i].idPelicula,
                   funciones[i].idSala,
                   funciones[i].fecha.dia,
                   funciones[i].fecha.mes,
                   funciones[i].fecha.anio,
                   funciones[i].horaInicio.hora,
                   funciones[i].horaInicio.minuto,
                   funciones[i].precio,
                   funciones[i].cantidadReservas,
                   funciones[i].reservasAsistidas);

                if(disponibles > 0) {
                printf(" | Butacas disponibles: %d", disponibles);
                }
            printf(" | Estado: ");
        }

        if (funciones[i].altaObaja == 1) {
            printf("Funcion activa\n");
        } else {
            printf("Funcion cancelada\n");
        }
    }
}

bool fechaFuncionValida(Fecha fecha, Hora hora) {     // esta funcion valida que no se pongan fechas antes de la fecha actual
    fechaCompleta inicio = {fecha.dia, fecha.mes, fecha.anio, hora.hora, hora.minuto};
    return comparar_fechas(inicio, fecha_actual());
}


bool precioValido(int precio){
    return (precio > 0);
}

void menuBuscarFunciones(){
    actualizarReservasAsistidas();
    int opcionCliente = -1;
    while(opcionCliente != 6){
        limpiarPantalla();
        printf("\n--- BUSCAR FUNCIONES ---\n");
        printf("1. Buscar funcion por Pelicula\n");
        printf("2. Buscar funcion por Horario\n");
        printf("3. Buscar funcion por Idioma\n");
        printf("4. Buscar funcion por Genero\n");
        printf("5. Buscar funcion por Disponibilidad\n");
        printf("6. Volver al menú anterior\n");
        printf("Ingrese opción: ");
        scanf("%d", &opcionCliente);

        switch(opcionCliente) {
            case 1: buscarFuncionesPorPelicula(); break;
            case 2: buscarFuncionesPorHorario(); break;
            case 3: buscarFuncionesPorIdioma(); break;
            case 4: buscarFuncionesPorGenero(); break;
            case 5: buscarFuncionesPorDisponibilidad(); break;
            case 6: printf("Volviendo al menú anterior...\n"); break;
            default: printf("Opción inválida.\n");
        }

        if(opcionCliente != 6){
            printf("Presione Enter para continuar...");
            getchar(); getchar();
        }
    }
}
void buscarFuncionesPorHorario() {
    actualizarReservasAsistidas();
    int horaBuscada, minutoBuscado;
    printf("Ingrese la hora (hh:mm): ");
    scanf("%d:%d", &horaBuscada, &minutoBuscado);

    bool encontrado = false;

    printf("Funciones a partir de las %d:%d: \n", horaBuscada, minutoBuscado);

    for (int i=0; i<cantFunciones; i++) {
        if (funciones[i].altaObaja) {
            int hora = funciones[i].horaInicio.hora;
            int minuto = funciones[i].horaInicio.minuto;

            if (hora>horaBuscada || (hora==horaBuscada && minuto>=minutoBuscado)) {
                // busca datos de las peliculas con ese horario
                for (int j = 0; j < cantidadPelis; j++) {
                    if (peliculas[j].id == funciones[i].idPelicula && peliculas[j].altaObaja) {
                        printf("Pelicula: %s | Sala: %d | Fecha: %d/%d/%d | Hora: %d:%d | Genero: %s | Idioma: %s\n",
                               peliculas[j].titulo,
                               funciones[i].idSala,
                               funciones[i].fecha.dia,
                               funciones[i].fecha.mes,
                               funciones[i].fecha.anio,
                               funciones[i].horaInicio.hora,
                               funciones[i].horaInicio.minuto,
                               peliculas[j].genero,
                               peliculas[j].idioma);
                        encontrado = true;
                    }
                }
            }
        }
    }

    if (!encontrado) {
        printf("No hay funciones a partir de ese horario.\n");
    }

    printf("\nPresione Enter para continuar...");
    getchar(); getchar();
}
void buscarFuncionesPorPelicula() {
    actualizarReservasAsistidas();
    char nombreBuscado[50];
    printf("Ingrese el título de la película: ");
    scanf(" %50[^\n]", nombreBuscado);

    bool encontrado=false;
    for (int i=0; i<cantidadPelis; i++) {
        if (peliculas[i].altaObaja && strcmp(peliculas[i].titulo, nombreBuscado)==0) {
            encontrado = true;
            printf("Pelicula encontrada: %s\n", peliculas[i].titulo);

            // Buscar funciones de esa película
            for (int j=0; j < cantFunciones; j++) {
                if (funciones[j].altaObaja && funciones[j].idPelicula == peliculas[i].id && !funcionYaEmpezo(funciones[j])) {
                    int disponibles = butacasDisponibles(funciones[j]);
                    printf("Funcion ID: %d | Sala: %d | Fecha: %d/%d/%d | Hora: %02d:%02d | Disponibles: %d\n",
                           funciones[j].id,
                           funciones[j].idSala,
                           funciones[j].fecha.dia,
                           funciones[j].fecha.mes,
                           funciones[j].fecha.anio,
                           funciones[j].horaInicio.hora,
                           funciones[j].horaInicio.minuto,
                           disponibles);
                }
            }
        }
    }

    if (!encontrado)
        printf("No se encontro ninguna pelicula con ese titulo.\n");

    printf("\nPresione Enter para continuar...");
    getchar(); getchar();
}
void buscarFuncionesPorIdioma(){
    actualizarReservasAsistidas();
    char idiomaBuscado[50];
    printf("Ingrese el idioma de la película: ");
    scanf(" %50[^\n]", idiomaBuscado);

    bool encontrado=false;
    for (int i=0; i<cantidadPelis; i++) {
        if (peliculas[i].altaObaja && strcmp(peliculas[i].idioma, idiomaBuscado)==0) {
            encontrado = true;
            printf("Película en idioma: %s\n", peliculas[i].idioma);

            // Buscar funciones de esa película
            for (int j=0; j < cantFunciones; j++) {
                if (funciones[j].altaObaja && funciones[j].idPelicula == peliculas[i].id && !funcionYaEmpezo(funciones[j])) {
                    int disponibles = butacasDisponibles(funciones[j]);
                    printf("Funcion ID: %d | Sala: %d | Fecha: %d/%d/%d | Hora: %02d:%02d | Titulo: %s | Disponibles: %d\n",
                           funciones[j].id,
                           funciones[j].idSala,
                           funciones[j].fecha.dia,
                           funciones[j].fecha.mes,
                           funciones[j].fecha.anio,
                           funciones[j].horaInicio.hora,
                           funciones[j].horaInicio.minuto,
                           peliculas[i].titulo,
                           disponibles);
                }
            }
        }
    }

    if (!encontrado)
        printf("No se encontró ninguna película con ese idioma.\n");

    printf("\nPresione Enter para continuar...");
    getchar(); getchar();
}
void buscarFuncionesPorGenero(){
    actualizarReservasAsistidas();
    char generoBuscado[50];
    printf("Ingrese el genero de la película: ");
    scanf(" %50[^\n]", generoBuscado);

    bool encontrado=false;
    for (int i=0; i<cantidadPelis; i++) {
        if (peliculas[i].altaObaja && strcmp(peliculas[i].genero, generoBuscado)==0) {
            encontrado = true;
            printf("Película del genero: %s\n", peliculas[i].genero);

            // Buscar funciones de esa película
            for (int j=0; j < cantFunciones; j++) {
                if (funciones[j].altaObaja && funciones[j].idPelicula == peliculas[i].id && !funcionYaEmpezo(funciones[j])) {
                int disponibles = butacasDisponibles(funciones[j]);
                printf("Funcion ID: %d | Sala: %d | Fecha: %d/%d/%d | Hora: %02d:%02d | Titulo: %s | Disponibles: %d\n",
                           funciones[j].id,
                           funciones[j].idSala,
                           funciones[j].fecha.dia,
                           funciones[j].fecha.mes,
                           funciones[j].fecha.anio,
                           funciones[j].horaInicio.hora,
                           funciones[j].horaInicio.minuto,
                           peliculas[i].titulo,
                           disponibles);
                }
            }
        }
    }

    if (!encontrado)
        printf("No se encontró ninguna película con ese genero.\n");

    printf("\nPresione Enter para continuar...");
    getchar(); getchar();
}
void buscarFuncionesPorDisponibilidad(){
    actualizarReservasAsistidas();
    bool encontrado = false;

    for(int i = 0; i < cantFunciones; i++) {
        if(funciones[i].altaObaja && !funcionYaEmpezo(funciones[i])) {
            int disponibles = butacasDisponibles(funciones[i]);
            if(disponibles > 0) {
                for(int j = 0; j < cantidadPelis; j++) {
                    if(peliculas[j].id == funciones[i].idPelicula && peliculas[j].altaObaja) {
                        printf("Funcion ID: %d | Pelicula: %s | Sala: %d | Fecha: %d/%d/%d | Hora: %02d:%02d | Disponibles: %d | Precio: %d\n",
                               funciones[i].id,
                               peliculas[j].titulo,
                               funciones[i].idSala,
                               funciones[i].fecha.dia,
                               funciones[i].fecha.mes,
                               funciones[i].fecha.anio,
                               funciones[i].horaInicio.hora,
                               funciones[i].horaInicio.minuto,
                               disponibles,
                               funciones[i].precio);
                        encontrado = true;
                }
            }
        }
    }
}
    if(!encontrado) {
        printf("No hay funciones con butacas disponibles.\n");
    }
    printf("\nPresione Enter para continuar...");
    getchar(); getchar();
}



int fechasIguales(Fecha a, Fecha b) {  //compara 2 fechas para ver si hay solapamiento
    return a.dia == b.dia && a.mes == b.mes && a.anio == b.anio;
}
int horaEnMinutos(Hora hora) {    //pasa las horas a minutos, ej: 12h = 720m
    return hora.hora * 60 + hora.minuto;
}
int haySolapamiento(int ix, int idSala, Fecha fecha, Hora horaInicio, int duracion) {
    int inicioNueva = horaEnMinutos(horaInicio);
    int finNueva = inicioNueva + duracion;

    for(int i = 0; i < cantFunciones; i++) {
        if(funciones[i].altaObaja && funciones[i].idSala == idSala && fechasIguales(funciones[i].fecha, fecha)) {
            int inicioExistente = horaEnMinutos(funciones[i].horaInicio);
            int finExistente = inicioExistente + funciones[i].duracionConLimpieza;
            if(!(finNueva <= inicioExistente || inicioNueva >= finExistente)) {
                return 1;
            }
        }
    }

    return 0;
}
int funcionYaEmpezo(Funcion funcion) {   // usamos la libreria que aportaron los profes
    fechaCompleta inicio = {funcion.fecha.dia, funcion.fecha.mes, funcion.fecha.anio, funcion.horaInicio.hora, funcion.horaInicio.minuto};
    return comparar_fechas(inicio, fecha_actual()) <= 0;
}
void actualizarReservasAsistidas() {
    fechaCompleta ahora = fecha_actual();
    for(int i = 0; i < cantFunciones; i++) {
        if(funciones[i].altaObaja) {
            fechaCompleta inicio = {funciones[i].fecha.dia, funciones[i].fecha.mes, funciones[i].fecha.anio, funciones[i].horaInicio.hora, funciones[i].horaInicio.minuto};
            if(comparar_fechas(inicio, ahora) <= 0 && funciones[i].cantidadReservas > 0) {
                funciones[i].reservasAsistidas += funciones[i].cantidadReservas;
                funciones[i].cantidadReservas = 0;
            }
        }
    }
}

int butacasDisponibles(Funcion funcion) {
    int capacidad = 17*16;
    if(capacidad <= 0) {
        return 0;
    }

    int disponibles = capacidad - funcion.cantidadReservas;
    if(disponibles < 0) {
        return 0;
    }
    return disponibles;
}


