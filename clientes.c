#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clientes.h"
#include "ids.h"
#include "util.h"

#define CANT_MAX_CLIENTES 100
Cliente clientes[CANT_MAX_CLIENTES];
int cantClientes = 0;

int iniciarSesion() {
    char email[51];
    char contrasenia[31];

    Cliente alta;
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
void registrar(){
    if(cantClientes>= CANT_MAX_CLIENTES ){
        printf("No se pueden registrar más clientes.\n");
        return;
    }

    Cliente alta;
    alta.id = generarId(ENTIDAD_CLIENTE);
    alta.altaObaja = 1;

    system("cls");
    printf("---- REGISTRO ----\n\n");

    printf("Ingrese su nombre:  ");
    scanf(" %50[^\n]", alta.nombre);

    printf("Email:  ");
    scanf(" %50[^\n]", alta.email);

    printf("Contraseña:  ");
    scanf(" %30[^\n]", alta.contrasenia);

    printf("DNI:  ");
    scanf("%d", &alta.dni);

    printf("Fecha de nacimiento (dd/mm/aaaa): ");  //Arreglar lo de la fecha de nacimiento
    scanf(" %d/%d/%d", &alta.fechaNac.dia, &alta.fechaNac.mes, &alta.fechaNac.anio);

    //Guardar en el array
    clientes[cantClientes] = alta;
    cantClientes++;

    printf("Cliente registrado correctamente.\n");

        printf("Presione Enter para continuar...");
            getchar(); //limpia buffer
            getchar(); // espera enter
}
