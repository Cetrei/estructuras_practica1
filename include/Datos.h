#ifndef DATOS_H
#define DATOS_H

/**
 * @brief Genera archivos binarios de prueba
 * - Esto para facilitar tests y ya que no encontre los archivos .dat originales en el aula
 */

#define DIRECTORIO_DATOS "data"
#define ARCHIVO_ESTUDIANTES "data/estudiantes.dat"
#define ARCHIVO_HISTORIAL "data/historial.dat"

/**
 * @brief Crea el directorio "data/" si no existe todavia
 * @return void
 *
 * @note Complejidad: O(1)
 */
void asegurarDirectorioDatos(void);

/**
 * @brief Genera un estudiantes.dat de prueba con 3 registros fijos.
 * @param nombreArchivo Ruta de salida. Si es NULL, se usa un vvalor default como fallback.
 * @warning Sobrescribe el archivo indicado; cualquier contenido previo se pierde.
 * @return void
 */
void generarEstudiantes(const char* nombreArchivo);

/**
 * @brief Genera un historial.dat de prueba con 5 registros fijos.
 * @param nombreArchivo Ruta de salida. Si es NULL, se usa un valor default como fallback.
 * @warning Sobrescribe el archivo indicado; cualquier contenido previo se pierde.
 * @return void
 */
void generarHistoriales(const char* nombreArchivo);

#endif
