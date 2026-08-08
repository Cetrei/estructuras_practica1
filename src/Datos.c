#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "Datos.h"
#include "Tipos.h"

void asegurarDirectorioDatos(void) {
    mkdir(DIRECTORIO_DATOS, 0755);
}

void generarEstudiantes(const char* nombreArchivo) {
    FILE* archivo;
    const char* rutaFinal = nombreArchivo != NULL ? nombreArchivo : ARCHIVO_ESTUDIANTES;

    Estudiante estudiantes[3] = {
        {"2020123456", "Joanfer", "Hidalgo Chaves", "Ingenieria en Sistemas", 4},
        {"2019987654", "Sebastian", "Rojas Badilla", "Ingenieria en Sistemas", 6},
        {"2021555222", "Santiago", "Chavarria Solis", "Ingenieria en Sistemas", 2}
    };

    asegurarDirectorioDatos();

    archivo = fopen(rutaFinal, "wb");
    fwrite(estudiantes, sizeof(Estudiante), 3, archivo);
    fclose(archivo);
}

void generarHistoriales(const char* nombreArchivo) {
    FILE* archivo;
    const char* rutaFinal = nombreArchivo != NULL ? nombreArchivo : ARCHIVO_HISTORIAL;

    Historial historiales[5] = {
        {"2020123456", "EIF207", "Estructuras de Datos", 2, 2026, 85.5f},
        {"2019987654", "EIF207", "Estructuras de Datos", 2, 2026, 95.0f},
        {"2021555222", "EIF207", "Estructuras de Datos", 2, 2026, 62.0f},
        {"2020123456", "EIF210", "Sistemas Operativos", 1, 2026, 78.0f},
        {"2019987654", "EIF310", "Redes", 2, 2026, 91.5f}
    };

    asegurarDirectorioDatos();

    archivo = fopen(rutaFinal, "wb");
    fwrite(historiales, sizeof(Historial), 5, archivo);
    fclose(archivo);
}
