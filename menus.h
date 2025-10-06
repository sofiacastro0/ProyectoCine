#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

// Detecta el sistema operativo (Què lindoooo) y define clear
#ifdef _WIN32
    #define clear "cls"
#else
    #define clear "clear"
#endif

int menuPrincipal(void);
void menuCliente();
void menuAdmin();

#endif // MENUS_H_INCLUDED
