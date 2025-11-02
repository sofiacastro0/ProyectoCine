#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "clientes.h"
#include "ids.h"
#include "util.h"
#include "fecha.h"
#include "estructuras.h"

#define CANT_MAX_CLIENTES 100
Cliente clientes[CANT_MAX_CLIENTES];
int cantClientes = 0;

int iniciarSesion() {
    char email[51];
    char contrasenia[31];

    limpiarPantalla();
    printf("---- INICIAR SESION ----\n\n");
    printf("Ingrese el Email:  ");
    scanf(" %50[^\n]", email);
    printf("Ingrese la contraseña:  ");
    scanf(" %30[^\n]", contrasenia);

    for (int i=0; i<cantClientes; i++) {
        if (strcmp(clientes[i].email, email) == 0 && strcmp(clientes[i].contrasenia, contrasenia) == 0) {
            printf("Bienvenido, %s!\n", clientes[i].nombre);
            printf("Presione Enter para continuar...");
                    getchar(); //limpia buffer
                    getchar(); // espera enter
            return 1;
        }
    }

    printf("Email o contraseña incorrectos\n");
        printf("Presione Enter para continuar...");
            getchar(); //limpia buffer
            getchar(); // espera enter
    return 0;

}

void altaCliente(){
    if(cantClientes>= CANT_MAX_CLIENTES ){
        printf("No se pueden registrar más clientes.\n");
        return;
    }
    char email[50], contrasenia[30];
    int dni, dia, mes, anio;
    bool errorEmail=false, errorContrasenia=false, errorDni=false, errorFechaNac=false;

    Cliente alta;
    alta.id = generarId(ENTIDAD_CLIENTE);
    alta.altaObaja = 1;

    limpiarPantalla();
    printf("---- Alta Cliente ----\n\n");

    printf("Ingrese su nombre:  ");
    scanf(" %50[^\n]", alta.nombre);

    do {
    printf("Email:  ");
    scanf(" %50[^\n]", email);
        if (formatoEmailValido(email) && emailUnico(email,clientes,cantClientes)){
            strcpy(alta.email, email);
            errorEmail=false;
        } else {
            errorEmail=true;
            printf("ERROR: Email invalido\n");
        }
    } while (errorEmail);

    do {
    printf("Contraseña:  ");
    scanf(" %30[^\n]", contrasenia);
        if (contraseniaValida(contrasenia)){
            strcpy(alta.contrasenia, contrasenia);
            errorContrasenia=false;
        } else {
            errorContrasenia=true;
            printf("ERROR: Contrasenia invalida\n");
        }
    } while (errorContrasenia);

    do {
    printf("DNI:  ");
    scanf("%d", &dni);
        if (dniValido(dni) && dniUnico(dni, clientes, cantClientes)){
            alta.dni = dni;
            errorDni=false;
        } else {
            errorDni=true;
            printf("ERROR: DNI invalido\n");
        }
    } while (errorDni);

    do {
    printf("Fecha de nacimiento (dd/mm/aaaa): ");  //Arreglar lo de la fecha de nacimiento
    scanf(" %d/%d/%d", &dia, &mes, &anio);
        fechaCompleta nacimiento = {dia, mes, anio, -1, -1};
        if (fecha_es_valida(nacimiento)){
            fechaCompleta hoy = fecha_actual();
            if (comparar_fechas(nacimiento, hoy) <= 0) {
                alta.fechaNac.dia = dia;
                alta.fechaNac.mes = mes;
                alta.fechaNac.anio = anio;
                errorFechaNac=false;
            } else {
                errorFechaNac=true;
                printf("ERROR: La fecha de nacimiento no puede ser futura\n");
            }
        } else {
            errorFechaNac=true;
            printf("ERROR: Fecha de nacimiento invalida\n");
        }
    } while (errorFechaNac);

    fechaCompleta nacimiento = {dia, mes, anio, -1, -1};
    fechaCompleta hoy = fecha_actual();
    alta.edad = diferencia_anios(nacimiento, hoy);
    if (alta.edad > 18){
        alta.cantEntradas = 5;
    } else {
        alta.cantEntradas = 1;
    }

    //Guardar en el array
    clientes[cantClientes] = alta;
    cantClientes++;

    printf("Cliente registrado correctamente.\n");
    printf("Tu edad es: %d \n", alta.edad);
    printf("La cantidad de entradas que podes adquirir es de: %d\n", alta.cantEntradas);

        printf("Presione Enter para continuar...");
            getchar(); //limpia buffer
            getchar(); // espera enter
}
void bajaCliente(){
    int i=0;
    bool encontrado=false;

    if (cantClientes==0){
        printf("No hay clientes registrados\n");
        return;
    }

    int buscarDni;
    printf("Ingrese su DNI para dar de baja la cuenta: ");
    scanf("%d",&buscarDni);

   while (i<cantClientes && !encontrado) {
        if (clientes[i].dni==buscarDni){
            if (clientes[i].altaObaja == 0){
                printf("Este cliente ya fue dado de baja\n");
            } else {
                clientes[i].altaObaja = 0;
                printf("Su cuenta se dio de baja correctamente\n");   // falta confirmacion
            }
            return;
        }
        i++;
    }

    if (!encontrado) {
        printf("No se encontró un cliente con ese DNI.\n");
    }

    return;
}
void modificacionCliente(){

    Cliente modificacion;
    int opcion=-1, i=0;
    bool encontrado=false;
    bool errorEmail=false;
    bool errorContrasenia=false;
    bool errorDni=false;
    bool errorFechaNac=false;

    if (cantClientes==0){
        printf("No hay clientes registrados\n");
        return;
    }

    int buscarDni;
    printf("Ingrese su DNI para modificar la cuenta: ");
    scanf("%d",&buscarDni);

    while (i<cantClientes && !encontrado) {
        if (clientes[i].dni==buscarDni){
            encontrado=true;
            printf("¿Que dato quiere modificar?\n");
            printf("1. Nombre\n");
            printf("2. Email\n");
            printf("3. Contrasenia\n");
            printf("4. Dni\n");
            printf("5. Fecha de nacimiento\n");
            printf("6. Volver atras\n");
            scanf("%d",&opcion);

                switch (opcion) {
                    case 1: printf("Nombre anterior: %s. Nuevo Nombre: ",clientes[i].nombre);
                            scanf(" %50[^\n]", modificacion.nombre);
                            strcpy(clientes[i].nombre, modificacion.nombre);
                            break;

                    case 2: do {
                            printf("Email anterior: %s. Nuevo Email: ",clientes[i].email);
                            scanf(" %50[^\n]", modificacion.email);

                                if (formatoEmailValido(modificacion.email) && emailUnico(modificacion.email,clientes,cantClientes)){
                                    strcpy(clientes[i].email, modificacion.email);
                                    errorEmail=false;
                                } else {
                                    errorEmail=true;
                                    printf("ERROR: Email invalido\n");
                                }
                            } while (errorEmail);
                            break;

                    case 3: do {
                            printf("Contrasenia anterior: %s. Nueva Contrasenia: ",clientes[i].contrasenia);
                            scanf(" %30[^\n]", modificacion.contrasenia);

                                if (contraseniaValida(modificacion.contrasenia)){
                                    strcpy(clientes[i].contrasenia, modificacion.contrasenia);
                                    errorContrasenia=false;
                                } else {
                                    errorContrasenia=true;
                                    printf("ERROR: Contrasenia invalida\n");
                                }

                            } while (errorContrasenia);
                            break;

                    case 4: do {
                            printf("DNI anterior: %d. Nuevo DNI: ",clientes[i].dni);
                            scanf("%d", &modificacion.dni);
                                if (dniValido(modificacion.dni) && dniUnico(modificacion.dni, clientes, cantClientes)){
                                    clientes[i].dni = modificacion.dni;
                                    errorDni=false;
                                } else {
                                    errorDni=true;
                                    printf("ERROR: DNI invalido\n");
                                }
                            } while (errorDni);
                            break;

                     case 5: do {
                            printf("Fecha de nacimiento anterior: %d/%d/%d. Nueva Fecha de nacimiento: ",clientes[i].fechaNac.dia, clientes[i].fechaNac.mes, clientes[i].fechaNac.anio);
                            scanf(" %d/%d/%d", &modificacion.fechaNac.dia, &modificacion.fechaNac.mes, &modificacion.fechaNac.anio);
                                fechaCompleta nacimiento = {modificacion.fechaNac.dia, modificacion.fechaNac.mes, modificacion.fechaNac.anio, -1,-1};
                                if (fecha_es_valida(nacimiento)){

                                    fechaCompleta hoy = fecha_actual();

                                    if (comparar_fechas(nacimiento, hoy) <= 0) {
                                        clientes[i].fechaNac.dia = modificacion.fechaNac.dia;
                                        clientes[i].fechaNac.mes = modificacion.fechaNac.mes;
                                        clientes[i].fechaNac.anio = modificacion.fechaNac.anio;

                                        fechaCompleta hoy = fecha_actual();
                                        clientes[i].edad = diferencia_anios(nacimiento, hoy);
                                        if (clientes[i].edad > 18){
                                            clientes[i].cantEntradas = 5;
                                        } else {
                                            clientes[i].cantEntradas = 1;
                                        }

                                        printf("Tu edad es: %d \n", clientes[i].edad);
                                        printf("La cantidad de entradas que podes adquirir es de: %d\n", clientes[i].cantEntradas);

                                        errorFechaNac=false;
                                        } else {
                                        errorFechaNac=true;
                                        printf("ERROR: La fecha de nacimiento no puede ser futura\n");
                                    }
                                } else {
                                    errorFechaNac=true;
                                    printf("ERROR: Fecha de nacimiento invalida\n");
                                }
                            } while (errorFechaNac);
                            break;

                    case 6: break;
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

void listarClientes() {  //esta lista tiene que estar en administrador

    printf("\n--- Listado de Clientes ---\n");
    if (cantClientes == 0) {
        printf("No hay clientes registrados.\n");
        return;
    }

    for(int i=0; i<cantClientes; i++){
        if(clientes[i].altaObaja){
            printf("ID:%d | Nombre: %s | Email :%s | Constrasenia: %s | DNI: %d | Fecha de nacimiento: %d/%d/%d | Edad: %d | Cantidad de entradas: %d \n",
                   clientes[i].id,
                   clientes[i].nombre,
                   clientes[i].email,
                   clientes[i].contrasenia,
                   clientes[i].dni,
                   clientes[i].fechaNac.dia,
                   clientes[i].fechaNac.mes,
                   clientes[i].fechaNac.anio,
                   clientes[i].edad,
                   clientes[i].cantEntradas);
        }
    }
}

bool formatoEmailValido(char email[]){
    bool hayArroba=false;
    bool hayPunto=false;

        for (int i=0; i<strlen(email); i++) {
            if (email[i] == '@'){
                hayArroba=true;
            }
            if (email[i] == '.'){
                hayPunto=true;
            }
        }
        if (hayArroba && hayPunto){
            return true;
        }
    return false;
}
bool emailUnico(char email[], Cliente clientes[], int cant){
    for(int i=0; i<cant; i++) {
        if(strcmp(clientes[i].email, email) == 0 && clientes[i].altaObaja == 1)
            return false;
    }
    return true;
}
bool dniValido(int dni){
    return (dni >= 10000000 && dni <= 99999999);
}
bool dniUnico(int dni, Cliente clientes[], int cant){
    for(int i=0; i<cant; i++) {
        if(clientes[i].dni == dni && clientes[i].altaObaja == 1)
            return false;
    }
    return true;
}
bool contraseniaValida(char contrasenia[]){
    if (strlen(contrasenia) < 8){
        return false;
    }
    return true;
}
bool esBisiesto(int anio){
    if (anio%4 == 0 && ((anio%100 != 0) || (anio%400 == 0))){
        return true;
    }
    return false;
}
