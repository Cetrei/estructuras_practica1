#ifndef REPORTE_H
#define REPORTE_H

#include "Tipos.h"

/**
 * @brief Tamano maximo para el buffer del reporte completo
 *
 * El reporte tiene una cantidad fija de lineas:
 * - 1 titulo
 * - 6 campos (cantidad, nota menor, estudiante, nota mayor, estudiante, promedio)
 * - 3 separadores (arriba, entre titulo y cuerpo, abajo)
 *
 * @note Calculo manual del peor caso
 *
 * Cada etiqueta ocupa 24 caracteres
 * El ancho de cada linea, en el peor caso segun el tamano de los campos del struct:
 *   - "Cantidad de registros : " + hasta 10 digitos (int cabe en 2147483647) = 34
 *   - "Nota menor/mayor/promedio : " + hasta 10 digitos (parte entera + '.' + 2 decimales + signo)                                          = 34
 *   - "Estudiante : " + nombre[40] (39 utiles) + " " + apellidos[40] (39 utiles) = 103
 *   - Titulo "REPORTE DEL HISTORIAL ACADEMICO" = 32
 *
 * El ancho maximo entre todas las lineas es 103 (linea de estudiante), y ese es el ancho que usa cada separador (agregarSeparador()).
 *
 * Total en el peor caso, sumando cada linea + su '\n':
 *   3 separadores  : 3 * (103 + 1) =  312
 *   7 lineas       : (32+1) + (34+1) + (34+1) + (103+1) + (34+1) + (103+1) + (34+1) = 380
 *   TOTAL          : 312 + 380 =  692
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
