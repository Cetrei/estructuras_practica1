#ifndef DATOS_H
#define DATOS_H

/**
 * @brief Genera archivos binarios de prueba
 * - Esto para facilitar tests y ya que no encontre los archivos .dat originales en el aula
 */

#define ARCHIVO_ESTUDIANTES "estudiantes.dat"
#define ARCHIVO_HISTORIAL "historial.dat"

/**
 * @brief Genera un estudiantes.dat de prueba con 3 registros fijos.
 * @param nombreArchivo Ruta de salida. Si es NULL, se usa un vvalor default como fallback.
 * @return void
 */
void generarEstudiantes(const char* nombreArchivo);

/**
 * @brief Genera un historial.dat de prueba con 5 registros fijos.
 * @param nombreArchivo Ruta de salida. Si es NULL, se usa un valor default como fallback.
 * @return void
 */
void generarHistoriales(const char* nombreArchivo);

#endif
