#include <stdio.h>
#include <stdlib.h>

#include "Registros.h"
#include "Utils.h"

CodigoResultado contarRegistros(const char* nombreArchivo, int* cantidadRegistros) {
    FILE* archivo;
    long tamanoBytes;

    archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) return ARCHIVO_NO_ENCONTRADO;

    fseek(archivo, 0, SEEK_END);
    tamanoBytes = ftell(archivo);
    fclose(archivo);

    *cantidadRegistros = (int)(tamanoBytes / sizeof(Historial));
    return EXITO;
}

CodigoResultado cargarHistorial(const char* nombreArchivo, int cantidadRegistros, Historial** historiales) {
    FILE* archivo;

    archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) return ARCHIVO_NO_ENCONTRADO;

    *historiales = (Historial*)malloc(cantidadRegistros * sizeof(Historial));
    if (*historiales == NULL) {
        fclose(archivo);
        return MEMORIA_INSUFICIENTE;
    }

    fread(*historiales, sizeof(Historial), cantidadRegistros, archivo);
    fclose(archivo);

    return EXITO;
}

CodigoResultado buscarEstudiante(const char* nombreArchivo, const char* carnet, Estudiante* estudianteEncontrado) {
    FILE* archivo;
    Estudiante actual;

    archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) return ARCHIVO_NO_ENCONTRADO;

    while (fread(&actual, sizeof(Estudiante), 1, archivo) == 1) {
        if (sonIguales(actual.carnet, carnet) == TRUE) {
            *estudianteEncontrado = actual;
            fclose(archivo);
            return EXITO;
        }
    }

    fclose(archivo);
    return NO_ENCONTRADO;
}

Estadisticas calcularEstadisticas(const Historial historiales[], int cantidadRegistros) {
    Estadisticas resultado;
    float sumaNotas = 0.0f;
    int indice;

    resultado.notaMenor = historiales[0].nota;
    resultado.notaMayor = historiales[0].nota;
    copiarTexto(resultado.carnetNotaMenor, historiales[0].carnet);
    copiarTexto(resultado.carnetNotaMayor, historiales[0].carnet);

    for (indice = 0; indice < cantidadRegistros; indice++) {
        sumaNotas += historiales[indice].nota;

        if (historiales[indice].nota < resultado.notaMenor) {
            resultado.notaMenor = historiales[indice].nota;
            copiarTexto(resultado.carnetNotaMenor, historiales[indice].carnet);
        }

        if (historiales[indice].nota > resultado.notaMayor) {
            resultado.notaMayor = historiales[indice].nota;
            copiarTexto(resultado.carnetNotaMayor, historiales[indice].carnet);
        }
    }

    resultado.notaPromedio = sumaNotas / cantidadRegistros;
    return resultado;
}
