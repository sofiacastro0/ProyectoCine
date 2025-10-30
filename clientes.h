#include "estructuras.h"

#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdbool.h>

typedef struct {
    int id;
    int altaObaja;
    char nombre[51];
    char email[51];         //que no se repita, si ya existe uno que pida ingresar
    char contrasenia[31];   //min de longitud
    int dni;                //numerico y unico
    Fecha fechaNac;         //que sea valida la fecha
    int edad;
    int cantEntradas;
} Cliente;

extern Cliente clientes[];
extern int cantClientes;

int iniciarSesion();
void altaCliente();
void bajaCliente();
void modificacionCliente();
void listarClientes();

bool formatoEmailValido(char email[]);
bool emailUnico(char email[], Cliente clientes[], int cant);
bool dniValido(int dni);
bool dniUnico(int dni, Cliente clientes[], int cant);
bool contraseniaValida(char contrasenia[]);
bool esBisiesto(int anio);

#endif // CLIENTES_H_INCLUDED
