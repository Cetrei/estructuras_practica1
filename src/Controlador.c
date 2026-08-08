#include <stdio.h>
#include <stdlib.h>

#include "Controlador.h"
#include "Bool.h"
#include "Tipos.h"
#include "Registros.h"
#include "Reporte.h"
#include "Datos.h"
#include "Mensajes.h"
#include "Resultado.h"

#define OPCION_GENERAR_DATOS 1
#define OPCION_USAR_EXISTENTES 2

/**
 * @brief Muestra el menu de inicio y lee la opcion escogida por el usuario
 * @return Opcion ingresada por teclado, sin validar
 */
static int pedirOpcionDelMenu(void) {
    int opcion;

    printf("%s\n", MENSAJE_MENU_PREGUNTA);
    printf("%s\n", MENSAJE_MENU_OPCION_GENERAR);
    printf("%s\n", MENSAJE_MENU_OPCION_EXISTENTES);
    printf("%s", MENSAJE_MENU_PROMPT);
    scanf("%d", &opcion);

    return opcion;
}

/**
 * @brief Pregunta al usuario si desea generar datos de prueba o usar los archivos existentes
 * @return void
 *
 * Repite la pregunta hasta recibir una opcion valida. Si se escoge generar datos, crea
 * estudiantes.dat e historial.dat de prueba mediante generarEstudiantes() y generarHistoriales()
 */
static void prepararArchivos(void) {
    int opcion = pedirOpcionDelMenu();

    while (opcion != OPCION_GENERAR_DATOS && opcion != OPCION_USAR_EXISTENTES) {
        printf("%s\n", MENSAJE_MENU_OPCION_INVALIDA);
        opcion = pedirOpcionDelMenu();
    }

    if (opcion == OPCION_GENERAR_DATOS) {
        generarEstudiantes(NULL);
        generarHistoriales(NULL);
        printf("%s\n", MENSAJE_DATOS_GENERADOS);
    }
}

/**
 * @brief Calcula las estadisticas del historial y busca los estudiantes de nota menor y mayor
 * @param historiales Arreglo de historiales ya cargado en memoria
 * @param cantidadRegistros Cantidad de elementos en historiales
 * @return Estadisticas y los dos estudiantes encontrados, listos para armar el reporte
 */
static ResultadosReporte procesarHistorial(const Historial historiales[], int cantidadRegistros) {
    ResultadosReporte resultados;

    resultados.estadisticas = calcularEstadisticas(historiales, cantidadRegistros);

    buscarEstudiante(ARCHIVO_ESTUDIANTES,  resultados.estadisticas.carnetNotaMenor, &resultados.estudianteNotaMenor);
    buscarEstudiante(ARCHIVO_ESTUDIANTES,  resultados.estadisticas.carnetNotaMayor, &resultados.estudianteNotaMayor);

    return resultados;
}

void ejecutarPractica(void) {
    int cantidadRegistros;
    Historial* historiales;

    ResultadosReporte resultados;
    char reporte[REPORTE_CAPACIDAD_MAX];
    
    CodigoResultado codigo;

    prepararArchivos();

    codigo = contarRegistros(ARCHIVO_HISTORIAL, &cantidadRegistros);
    if (codigo != EXITO || cantidadRegistros == 0) {
        printf("%s\n", MENSAJE_SIN_REGISTROS);
        return;
    }

    codigo = cargarHistorial(ARCHIVO_HISTORIAL, cantidadRegistros, &historiales);
    if (codigo != EXITO) {
        printf("%s\n", MENSAJE_ERROR_CARGA_HISTORIAL);
        return;
    }

    resultados = procesarHistorial(historiales, cantidadRegistros);

    construirReporte(reporte, cantidadRegistros, resultados);
    imprimirReporte(reporte);

    free(historiales);
}
