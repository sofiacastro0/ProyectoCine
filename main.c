#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CAMBIAR TOODS LOS "cls" POR "clear"

typedef struct {
    char titulo[51];
    char idioma[51];
    char genero[51];
    char formato[21];
    char clasificacionEdad[21];
    int duracion;
    int codigoInterno;
} Pelicula;

typedef struct {
    char nombre[51];
    char email[51];  //que no se repita, si ya existe uno que pida ingresar
    char contrasenia[31]; //min de longitud
    int DNI;  //numerico y unico
    int fechaNac;  //que sea valida la fecha
} Cliente;

//sala de A-P, 1-17
//reserva, funcion

void menuCliente();
void menuAdmin();

int main() {
    int seleccion=1;
    char tecla;

        while(seleccion!=0){
            //MENU PRINCIPAL
            system("cls");
                printf("---------------------------------\n");
                printf("   Sistema de Reservas de Cine\n");
                printf("---------------------------------\n");
                printf("1. Operar como Cliente\n");
                printf("2. Operar como Administrador\n");
                printf("0. Salir del sistema\n");
                printf("---------------------------------\n");
                printf("Seleccione una opcion: ");
                scanf("%d",&seleccion);

            switch(seleccion){
                case 1: //CLIENTE
                    /*
                    printf("------ INICIAR SESION ------");
                    printf("1. Ingresar con email y contraseña");
                    printf("2. Registrarse");
                    printf("0. Salir");
                    scanf("%d",&seleccion);

                    switch(seleccion){
                        case 1:
                            printf

                    }
                    */
                    menuCliente();
                    break;

                case 2: //ADMIN
                    menuAdmin();
                    break;

                case 0: //SALIR
                    break;

                default:
                    system("cls");
                    printf("La opcion %d no existe en el menu.\n",seleccion);
                    break;
            }

            if(seleccion!=0 && seleccion != 1 && seleccion != 2){  //limpia el buffer
                printf("MENU Presione Enter para continuar.");
                tecla=getchar();

                while ((tecla=getchar()) != '\n' && tecla != EOF) {}
            }

        }

    system("cls");
    printf("Gracias! Vuelva pronto!\n");

    return 0;
}

void menuCliente(){
    int opcion=1;
    char tecla;

    do {

        system("cls");
        printf("--------- Menu Cliente -----------\n");
        printf("1. Buscar funciones por fecha\n");
        printf("2. Buscar funciones por pelicula\n");
        printf("3. Ver butacas disponibles\n");
        printf("4. Reservar butacas\n");
        printf("5. Cancelar reserva\n");
        printf("6. Ver mis reservas\n");
        printf("7. Volver al menu principal\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                //1. Buscar funciones por fecha
                system("cls");
                break;
            case 2:
                //Buscar funciones por película
                system("cls");
                break;
            case 3:
                //Ver butacas disponibles
                system("cls");
                break;
            case 4:
                //Reservar butacas
                system("cls");
                break;
            case 5:
                //Cancelar reserva
                system("cls");
                break;
            case 6:
                //Ver mis reservas
                system("cls");
                break;
            case 7:
                //Volver al menú principal
                break;
            default:
                system("cls");
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion!=7){  //limpia el buffer
            printf("CLIENTE Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while(opcion!=7);

}
void menuAdmin(){
    int opcion=1;
    char tecla;
    do {
        system("cls");
        printf("------- Menu Administrador -------\n");
        printf("1. Gestion de Peliculas\n");
        printf("2. Gestion de Salas\n");
        printf("3. Gestion de Clientes\n");
        printf("4. Funciones\n");
        printf("5. Reportes\n");
        printf("6. Volver al menu principal\n");
        printf("---------------------------------\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                //Gestion de Peliculas
                system("cls");
                break;
            case 2:
                //Gestion de Salas
                system("cls");
                break;
            case 3:
                //Gestion de Clientes
                system("cls");
                break;
            case 4:
                //Funciones
                system("cls");
                break;
            case 5:
                //Reportes
                system("cls");
                break;
            case 6:
                //Volver al menu principal
                break;

            default:
                system("cls");
                printf("La opcion %d no existe en el menu.\n",opcion);
                break;
        }

        if(opcion!=6){  //limpia el buffer
            printf("ADMIN Presione Enter para continuar.");
            tecla=getchar();

            while ((tecla=getchar()) != '\n' && tecla != EOF) {}
        }

    } while (opcion!=6);
}
