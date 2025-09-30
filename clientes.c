#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clientes.h"

#define MAX_CLIENTES 100
Cliente clientes[MAX_CLIENTES];
int cantClientes = 0;

void registrar(){
    if(cantClientes >= MAX_CLIENTES){
        printf("No se pueden registrar más clientes.\n");
        return;
    }
    system("cls");
    printf("---- REGISTRO ----\n\n");

    Cliente c;

    printf("Ingrese su nombre:  ");
    scanf(" %50[^\n]", c.nombre);

    printf("Email:  ");
    scanf(" %50[^\n]", c.email);

    printf("Contraseña:  ");
    scanf(" %30[^\n]", c.contrasenia);

    printf("DNI:  ");
    scanf("%d", &c.dni);

    printf("Fecha de nacimiento (dd/mm/aaaa): ");  //Arreglar lo de la fecha de nacimiento
    scanf(" %d/%d/%d", &c.fechaNac.dia, &c.fechaNac.mes, &c.fechaNac.anio);

    //no anda esta parte, saltea las lineas de abajo, revisar

    //Guardar en el array
    clientes[cantClientes] = c;
    cantClientes++;

    printf("Cliente registrado correctamente.\n");
}
