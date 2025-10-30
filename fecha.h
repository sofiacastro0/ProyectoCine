#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

// Estructura de fechaCompleta
typedef struct {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
} fechaCompleta;

// Obtiene la fecha actual del sistema
fechaCompleta fecha_actual();

// Compara dos fechas. Retorna: -1 si f1 < f2; 0 si f1 == f2; 1 si f1 > f2
int comparar_fechas(fechaCompleta f1, fechaCompleta f2);

// Devuelve la diferencia en años
int diferencia_anios(fechaCompleta desde, fechaCompleta hasta);

// Valida una fecha. Retorna 1 si es válida, 0 si no lo es
int fecha_es_valida(fechaCompleta f);

// Imprime una fecha
void mostrar_fecha(fechaCompleta f);

#endif // FECHA_H_INCLUDED
