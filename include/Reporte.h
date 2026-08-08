#ifndef REPORTE_H
#define REPORTE_H

#include "Tipos.h"

/**
 * @brief Tamano maximo para la cadena del reporte completo
 *
 * El reporte tiene una cantidad fija de lineas:
 * - 1 titulo
 * - 6 campos (cantidad, nota menor, estudiante, nota mayor, estudiante, promedio)
 * - 3 separadores (arriba, entre titulo y cuerpo, abajo)
 *
 * @note Calculo manual del peor caso, usando sizeof() de los campos de `Estudiante` (Tipos.h)
 *
 * La linea mas larga posible es la de estudiante, porque usa los arreglos de char mas grandes del struct:
 *   "Estudiante : " (13) + sizeof(Estudiante.nombre) - 1 (39) + " " (1) + sizeof(Estudiante.apellidos) - 1 (39) = 92 caracteres
 * (se resta 1 a cada arreglo porque el '\0' de nombre/apellidos no se copia entre medio, solo al final)
 *
 * Al 92 ser el tam maximo; el spearador usa ese mismo valor: cada separador ocupa 92 caracteres + '\n'.
 *
 * Total en el peor caso, sumando cada linea + su '\n' (usando 92 como ancho de linea para todas)
 *   3 separadores : 3 * (92 + 1) = 279
 *   7 lineas      : 7 * (92 + 1) = 651
 *   TOTAL         : 279 + 651 = 930
 *
 * 2048 deja margen suficiente sobre ese peor caso (930 caracteres).
 */
#define REPORTE_CAPACIDAD_MAX 2048

/**
 * @brief Agrupa todo lo que `construirReporte()` necesita para armar l reporte final, en un solo parametro
 */
typedef struct {
    Estadisticas estadisticas;
    Estudiante estudianteNotaMenor;
    Estudiante estudianteNotaMayor;
} ResultadosReporte;

/**
 * @brief Arma el reporte completo del historial academico como una unica cadena de texto, sin imprimirlo
 * @param destino Buffer de salida de tamano `REPORTE_CAPACIDAD_MAX`
 * @param cantidadRegistros Cantidad total de historiales procesados
 * @param resultados Estadisticas y estudiantes calculados
 * @return void
 *
 * La longitud del separador se asigna a la linea mas larga del repote tras haber armado estas
 */
void construirReporte(char destino[REPORTE_CAPACIDAD_MAX], int cantidadRegistros, ResultadosReporte resultados);

/**
 * @brief Imprime en pantalla el reporte final
 * @param reporte Cadena de texto armada por `construirReporte()`
 * @return void
 *
 * Complejidad: O(1), la cantidad de texto a mostrar es fija
 */
void imprimirReporte(const char* reporte);

#endif
