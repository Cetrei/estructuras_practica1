#ifndef CAPTURA_H
#define CAPTURA_H

/**
 * @brief Captura de datos por teclado para crear estudiantes.dat / historial.dat en ejecucion
 */

/**
 * @brief Pide por teclado uno o mas estudiantes y los guarda en el archivo indicado
 * @param nombreArchivo Ruta de salida (tipicamente ARCHIVO_ESTUDIANTES)
 * @warning Sobrescribe el archivo indicado; cualquier contenido previo se pierde
 * @return void
 */
void capturarEstudiantes(const char* nombreArchivo);

/**
 * @brief Pide por teclado uno o mas historiales y los guarda en el archivo indicado
 * @param nombreArchivo Ruta de salida (tipicamente ARCHIVO_HISTORIAL)
 * @warning Sobrescribe el archivo indicado; cualquier contenido previo se pierde
 * @return void
 */
void capturarHistoriales(const char* nombreArchivo);

#endif
