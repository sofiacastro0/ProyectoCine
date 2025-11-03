#include "fecha.h"
#include <stdio.h>
#include <time.h>

// Días por mes
static const int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int es_bisiesto(int anio) {
    return (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}

fechaCompleta fecha_actual() {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);

    fechaCompleta f;
    f.dia = now->tm_mday;
    f.mes = now->tm_mon + 1;
    f.anio = now->tm_year + 1900;
    f.hora = now->tm_hour;
    f.minuto = now->tm_min;
    return f;
}

int comparar_fechas(fechaCompleta f1, fechaCompleta f2) {
    if (f1.anio != f2.anio) return (f1.anio > f2.anio) ? 1 : -1;
    if (f1.mes != f2.mes) return (f1.mes > f2.mes) ? 1 : -1;
    if (f1.dia != f2.dia) return (f1.dia > f2.dia) ? 1 : -1;
    if (f1.hora != f2.hora) return (f1.hora > f2.hora) ? 1 : -1;
    if (f1.minuto != f2.minuto) return (f1.minuto > f2.minuto) ? 1 : -1;

    return 0;
}

int diferencia_anios(fechaCompleta desde, fechaCompleta hasta) {
    int anios = hasta.anio - desde.anio;
    if (hasta.mes < desde.mes || (hasta.mes == desde.mes && hasta.dia < desde.dia)) {
        anios--;
    }
    return anios;
}

int fecha_es_valida(fechaCompleta f) {
    if (f.anio < 1 || f.mes < 1 || f.mes > 12 || f.dia < 1)
        return 0;

    int dias_mes = dias_por_mes[f.mes - 1];
    if (f.mes == 2 && es_bisiesto(f.anio))
        dias_mes = 29;

    if (f.dia > dias_mes)
        return 0;

    if (f.hora == -1 && f.minuto == -1) // si son -1 los tomamos como datos omitidos
        return 1;

    return (f.hora >= 0 && f.hora <= 23 && f.minuto >= 0 && f.minuto <= 59);
}

void mostrar_fecha(fechaCompleta f) {
    if (f.hora >= 0 && f.minuto >= 0)
        printf("%02d/%02d/%04d %02d:%02d\n", f.dia, f.mes, f.anio, f.hora, f.minuto);
    else
        printf("%02d/%02d/%04d\n", f.dia, f.mes, f.anio);
}
