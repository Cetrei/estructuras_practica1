#include <stdio.h>

#include "Reporte.h"
#include "Utils.h"
#include "Mensajes.h"

#define REPORTE_CANTIDAD_LINEAS 7
#define REPORTE_ANCHO_LINEA 128

static void escribirLineaConEtiqueta(char* linea, const char* etiqueta, const char* valorTexto) {
    copiarTexto(linea, etiqueta);
    agregarTextoAlFinal(linea, valorTexto);
}

static void escribirLineaDeEstudiante(char* linea, Estudiante estudiante) {
    copiarTexto(linea, REPORTE_ETIQUETA_ESTUDIANTE);
    agregarTextoAlFinal(linea, estudiante.nombre);
    agregarTextoAlFinal(linea, " ");
    agregarTextoAlFinal(linea, estudiante.apellidos);
}

static int calcularAnchoMaximo(char lineas[REPORTE_CANTIDAD_LINEAS][REPORTE_ANCHO_LINEA]) {
    int largoMaximo = 0;
    int largoActual;
    int indiceLinea;

    for (indiceLinea = 0; indiceLinea < REPORTE_CANTIDAD_LINEAS; indiceLinea++) {
        largoActual = contarCaracteres(lineas[indiceLinea]);
        if (largoActual > largoMaximo) {
            largoMaximo = largoActual;
        }
    }

    return largoMaximo;
}

/**
 * @brief Cuenta los caracteres de cadena hasta el '\0', sin detenerse en '\n' o '\r'
 * @param cadena Cadena de entrada
 * @return Cantidad de caracteres antes del '\0'
 *
 */
static int longitudReal(const char* cadena) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

/**
 * @brief Agrega origen al final de destino, usando longitudReal() en vez de contarCaracteres()
 * @param destino Cadena del reporte, puede contener '\n' ya escritos
 * @param origen Texto a agregar (una linea ya armada, sin '\n')
 * @return void
 */
static void agregarCadenaAlReporte(char* destino, const char* origen) {
    int indiceDestino = longitudReal(destino);
    int indiceOrigen = 0;

    while (origen[indiceOrigen] != '\0') {
        destino[indiceDestino] = origen[indiceOrigen];
        indiceDestino++;
        indiceOrigen++;
    }
    destino[indiceDestino] = '\0';
}

/**
 * @brief Arma cada linea individual del reporte (titulo y los 6 campos) a partir de los resultados
 * @param lineas Arreglo de salida donde se escribe cada linea ya formada
 * @param cantidadRegistros Cantidad total de historiales procesados
 * @param resultados Estadisticas y estudiantes ya calculados
 * @return El ancho maximo entre las lineas construidas, calculado con calcularAnchoMaximo()
 */
static int construirLineasDelReporte(char lineas[REPORTE_CANTIDAD_LINEAS][REPORTE_ANCHO_LINEA], int cantidadRegistros, ResultadosReporte resultados) {
    char numeroTexto[32];

    copiarTexto(lineas[0], REPORTE_TITULO);

    convertirIntACadena(cantidadRegistros, numeroTexto);
    escribirLineaConEtiqueta(lineas[1], REPORTE_ETIQUETA_CANTIDAD_REGISTROS, numeroTexto);

    convertirFloatACadena(resultados.estadisticas.notaMenor, 2, numeroTexto);
    escribirLineaConEtiqueta(lineas[2], REPORTE_ETIQUETA_NOTA_MENOR, numeroTexto);

    escribirLineaDeEstudiante(lineas[3], resultados.estudianteNotaMenor);

    convertirFloatACadena(resultados.estadisticas.notaMayor, 2, numeroTexto);
    escribirLineaConEtiqueta(lineas[4], REPORTE_ETIQUETA_NOTA_MAYOR, numeroTexto);

    escribirLineaDeEstudiante(lineas[5], resultados.estudianteNotaMayor);

    convertirFloatACadena(resultados.estadisticas.notaPromedio, 2, numeroTexto);
    escribirLineaConEtiqueta(lineas[6], REPORTE_ETIQUETA_NOTA_PROMEDIO, numeroTexto);

    return calcularAnchoMaximo(lineas);
}

static void agregarSeparador(char* destino, int cantidad) {
    int indice;
    int largo = longitudReal(destino);

    for (indice = 0; indice < cantidad; indice++) {
        destino[largo + indice] = REPORTE_CHAR_SEPARADOR;
    }
    destino[largo + cantidad] = '\n';
    destino[largo + cantidad + 1] = '\0';
}

/**
 * @brief Agrega un caracter '\n' al final de destino
 * @param destino Cadena a la que se le agrega el salto de linea
 * @return void
 *
 */
static void agregarSaltoDeLinea(char* destino) {
    int largo = longitudReal(destino);
    destino[largo] = '\n';
    destino[largo + 1] = '\0';
}

void construirReporte(char destino[REPORTE_CAPACIDAD_MAX], int cantidadRegistros, ResultadosReporte resultados) {
    char lineas[REPORTE_CANTIDAD_LINEAS][REPORTE_ANCHO_LINEA];
    int anchoSeparador;
    int indiceLinea;

    anchoSeparador = construirLineasDelReporte(lineas, cantidadRegistros, resultados);

    destino[0] = '\0';
    agregarSeparador(destino, anchoSeparador);
    agregarCadenaAlReporte(destino, lineas[0]);
    agregarSaltoDeLinea(destino);
    agregarSeparador(destino, anchoSeparador);

    for (indiceLinea = 1; indiceLinea < REPORTE_CANTIDAD_LINEAS; indiceLinea++) {
        agregarCadenaAlReporte(destino, lineas[indiceLinea]);
        agregarSaltoDeLinea(destino);
    }

    agregarSeparador(destino, anchoSeparador);
}

void imprimirReporte(const char* reporte) {
    printf("%s", reporte);
}
