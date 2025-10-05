#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "estructuras.h"

typedef struct {  //fecha de nacimiento
    int dia, mes, anio;
} Fecha;

typedef struct {  //cliente
    int id;
    int altaObaja;
    char nombre[51];
    char email[51];         //que no se repita, si ya existe uno que pida ingresar
    char contrasenia[31];   //min de longitud
    int dni;                //numerico y unico
    Fecha fechaNac;         //que sea valida la fecha
} Cliente;

int iniciarSesion();
void registrar();

#endif // CLIENTES_H_INCLUDED
