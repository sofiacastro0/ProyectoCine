#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "clientes.h"

// Detecta el sistema operativo (Què lindoooo) y define clear
#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

//Borre todo porque teníamos los menus duplicados en main.c y menu.c
