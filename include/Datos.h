#ifndef DATOS_H
#define DATOS_H

/**
 * @brief Genera archivos binarios de prueba
 * - Esto para facilitar tests y ya que no encontre los archivos .dat originales en el aula
 */

/**
 * @brief Ruta absoluta al directorio "data/" ubicado junto al ejecutable
 * @return Puntero a buffer estatico interno, valido hasta la siguiente llamada
 */
const char* rutaDirectorioDatos(void);

/**
 * @brief Ruta absoluta a "data/estudiantes.dat" junto al ejecutable
 * @return Puntero a buffer estatico interno, valido hasta la siguiente llamada
 */
const char* rutaArchivoEstudiantes(void);

/**
 * @brief Ruta absoluta a "data/historial.dat" junto al ejecutable
 * @return Puntero a buffer estatico interno, valido hasta la siguiente llamada
 */
const char* rutaArchivoHistorial(void);

#define ARCHIVO_ESTUDIANTES rutaArchivoEstudiantes()
#define ARCHIVO_HISTORIAL rutaArchivoHistorial()

/**
 * @brief Crea el directorio "data/" si no existe todavia
 * @return void
 *
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
