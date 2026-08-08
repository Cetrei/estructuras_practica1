#ifndef UTILS_H
#define UTILS_H

#include "Bool.h"

/**
 * @brief Utilidades de texto y numero a texto
 */

/**
    * @brief Determina si un caracter es un fin de linea
    * @param caracter Caracter a evaluar
    * @return TRUE si es '\0', '\n' o '\r', FALSE en caso contrario
    *
    * Complejidad: O(1)
*/
Bool finDeLinea(char caracter);

/**
 * @brief Copia origen (incluyendo `NULL`) a destino.
 * @param origen Cadena de origen
 * @param destino Cadena de salida, debe tener espacio suficiente
 * @return void
 *
 * Complejidad: O(longitud de `origen`).
 */
void copiarTexto(char* destino, const char* origen);

/**
 * @brief Compara dos cadenas caracter a caracter.
 * @param texto1 Primera cadena a comparar
 * @param texto2 Segunda cadena a comparar
 * @return TRUE si las cadenas son iguales
 *
 * Complejidad: O(longitud de la cadena mas corta).
 */
Bool sonIguales(const char* texto1, const char* texto2);

/**
 * @brief Cuenta los caracteres antes del '\0'
 * @param cadena Cadena de entrada
 * @return Cantidad de caracteres sin contar el '\0'
 *
 * Complejidad: O(longitud de `cadena`).
 */
int contarCaracteres(const char* cadena);

/**
 * @brief Concatena origen al final de destino.
 * @param origen Cadena a agregar al final de destino
 * @param destino Cadena de salida, debe tener espacio suficiente
 * @return void
 *
 * Complejidad: O(longitud de `destino` + longitud de `origen`).
 */
void agregarTextoAlFinal(char* destino, const char* origen);

/**
 * @brief Convierte un entero a su representacion decimal en texto
 * @param valor Numero entero a convertir, puede ser negativo
 * @param destino Cadena de salida, debe tener espacio suficiente
 * @return void
 *
 * Complejidad: O(cantidad de digitos de `valor`)
 */
void convertirIntACadena(int valor, char* destino);

/**
 * @brief Convierte un flotante a texto con una cantidad fija de decimales, redondeando hacia el decimal mas cercano a texto
 * @param valor Numero flotante a convertir, puede ser negativo
 * @param decimales Cantidad de digitos decimales a incluir
 * @param destino Cadena de salida, debe tener espacio suficiente
 * @return void
 *
 * Complejidad: O(cantidad de digitos de `valor`).
 */
void convertirFloatACadena(float valor, int decimales, char* destino);

#endif
