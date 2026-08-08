#ifndef REGISTROS_H
#define REGISTROS_H

#include "Bool.h"
#include "Tipos.h"
#include "Resultado.h"

/**
 * @brief Cuenta cuantos registros de Historial hay en el archivo dado
 * @param nombreArchivo Ruta del archivo binario `historial.dat`
 * @param cantidadRegistros Parametro de salida: cantidad de registros encontrados
 * @return EXITO si se pudo calcular, ARCHIVO_NO_ENCONTRADO si el archivo no existe o no se pudo abrir
 *
 * Se calcula a partir del tamano del archivo en bytes (fseek + ftell), sin leer su contenido
 * 
 * @note Complejidad: O(1).
 */
CodigoResultado contarRegistros(const char* nombreArchivo, int* cantidadRegistros);

/**
 * @brief Carga todos los historiales de un archivo a memoria dinamica
 * @param nombreArchivo Ruta del archivo binario `historial.dat`
 * @param cantidadRegistros Cantidad de registros a reservar y leer
 * @param historiales Parametro de salida: puntero al arreglo reservado con malloc
 * @return EXITO si se cargo correctamente, ARCHIVO_NO_ENCONTRADO si no se pudo abrir el archivo, MEMORIA_INSUFICIENTE si malloc fallo
 *
 * @warning El caller debe liberar `*historiales` con free() si el resultado es EXITO
 *
 * @note Complejidad: O(n), siendo n = cantidadRegistros
 */
CodigoResultado cargarHistorial(const char* nombreArchivo, int cantidadRegistros, Historial** historiales);

/**
 * @brief Busca un estudiante por carnet mediante busqueda secuencial
 * @param nombreArchivo Ruta del archivo binario `estudiantes.dat`
 * @param carnet Carnet a buscar
 * @param estudianteEncontrado Parametro de salida: De encontrarse, copia del registro encontrado
 * @return EXITO si se encontro, ARCHIVO_NO_ENCONTRADO si no se pudo abrir el archivo, NO_ENCONTRADO si se recorrio todo el archivo sin coincidencia
 *
 * @note Complejidad: O(m), siendo m = cantidad de estudiantes del archivo ya que recorre el archivo secuencialmente
 */
CodigoResultado buscarEstudiante(const char* nombreArchivo, const char* carnet, Estudiante* estudianteEncontrado);

/**
 * @brief Recorre un arreglo de historiales para obtener sus estadisticas
 * @param historiales Arreglo de historiales ya cargado en memoria
 * @param cantidadRegistros Cantidad de elementos en historiales
 * @warning `cantidadRegistros` debe ser mayor a 0
 * @return Estadisticas con nota menor, nota mayor, sus carnets asociados y el promedio general
 *
 * @note Complejidad: O(n), siendo n = cantidadRegistros ya que un solo recorrido calcula cada valor 
 */
Estadisticas calcularEstadisticas(const Historial historiales[], int cantidadRegistros);

#endif
