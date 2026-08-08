#include <stdio.h>
#include <ctype.h>

#include "Captura.h"
#include "Tipos.h"
#include "Utils.h"
#include "Datos.h"

/**
 * @brief Lee una linea de texto desde stdin hacia destino, recortando el salto de linea final
 * @param destino Cadena de salida
 * @param tamano Tamano de destino en bytes (incluyendo el caracter nulo)
 * @return void
 *
 * fgets() evita desbordamientos si el usuario escribe mas caracteres de los que caben en el campoo
 */
static void leerLinea(char* destino, int tamano) {
    if (fgets(destino, tamano, stdin) != NULL) {
        int longitud = contarCaracteres(destino);
        if (longitud > 0 && destino[longitud - 1] == '\n') {
            destino[longitud - 1] = '\0';
        }
    } else {
        destino[0] = '\0';
    }
}

/**
 * @brief Descarta el resto de la linea actual del buffer de entrada
 * @return void
 *
 * Uso interno tras un scanf() numerico: scanf() deja el '\n' pendiente y sin limpiarlo la siguiente leerLinea() leeria una linea vacia en vez del texto nuevo
 */
static void limpiarBufferEntrada(void) {
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF) {
        // descartar
    }
}

/**
 * @brief Pregunta si se desea capturar otro registro
 * @param mensaje Texto de la pregunta, mostrado antes de leer la respuesta
 * @return 'S' o 'N' (mayuscula), sin validar
 */
static char preguntarSiDeseaOtro(const char* mensaje) {
    char respuesta;
    printf("%s", mensaje);
    scanf(" %c", &respuesta);
    limpiarBufferEntrada();
    return (char)toupper((unsigned char)respuesta);
}

void capturarEstudiantes(const char* nombreArchivo) {
    FILE* archivo;
    Estudiante estudiante;
    char continuar;

    asegurarDirectorioDatos();

    archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo %s\n", nombreArchivo);
        return;
    }

    do {
        printf("\nCarnet: ");
        leerLinea(estudiante.carnet, sizeof(estudiante.carnet));

        printf("Nombre: ");
        leerLinea(estudiante.nombre, sizeof(estudiante.nombre));

        printf("Apellidos: ");
        leerLinea(estudiante.apellidos, sizeof(estudiante.apellidos));

        printf("Carrera: ");
        leerLinea(estudiante.carrera, sizeof(estudiante.carrera));

        printf("Nivel: ");
        scanf("%d", &estudiante.nivel);
        limpiarBufferEntrada();

        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);

        continuar = preguntarSiDeseaOtro("Desea agregar otro estudiante (S/N): ");
    } while (continuar == 'S');

    fclose(archivo);
}

void capturarHistoriales(const char* nombreArchivo) {
    FILE* archivo;
    Historial historial;
    char continuar;

    asegurarDirectorioDatos();

    archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo %s\n", nombreArchivo);
        return;
    }

    do {
        printf("\nCarnet: ");
        leerLinea(historial.carnet, sizeof(historial.carnet));

        printf("Codigo del curso: ");
        leerLinea(historial.codigoCurso, sizeof(historial.codigoCurso));

        printf("Nombre del curso: ");
        leerLinea(historial.nombreCurso, sizeof(historial.nombreCurso));

        printf("Ciclo: ");
        scanf("%d", &historial.ciclo);
        limpiarBufferEntrada();

        printf("Anio: ");
        scanf("%d", &historial.anio);
        limpiarBufferEntrada();

        printf("Nota: ");
        scanf("%f", &historial.nota);
        limpiarBufferEntrada();

        fwrite(&historial, sizeof(Historial), 1, archivo);

        continuar = preguntarSiDeseaOtro("Desea agregar otro historial (S/N): ");
    } while (continuar == 'S');

    fclose(archivo);
}
