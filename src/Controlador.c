#include <stdio.h>
#include <stdlib.h>

#include "Controlador.h"
#include "Bool.h"
#include "Tipos.h"
#include "Registros.h"
#include "Reporte.h"
#include "Datos.h"
#include "Captura.h"
#include "Mensajes.h"
#include "Resultado.h"
#include "Utils.h"

#define OPCION_GENERAR_DATOS 1
#define OPCION_USAR_EXISTENTES 2

#define OPCION_DATOS_PRUEBA_FIJOS 1
#define OPCION_DATOS_MANUALES 2

/**
 * @brief Descarta el resto de la linea actual del buffer de entrada
 * @return void
 *
 * Uso interno tras un scanf("%d", ...) de menu: scanf() deja el '\n' pendiente en el buffer
 */
static void limpiarBufferEntradaMenu(void) {
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF) {
        // descartar
    }
}

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
    limpiarBufferEntradaMenu();

    return opcion;
}

/**
 * @brief Muestra el submenu de origen de los datos de prueba y lee la opcion escogida
 * @return Opcion ingresada por teclado, sin validar
 *
 * Se muestra unicamente cuando ya se decidio sobrescribir los archivos, por lo que
 * siempre va acompanado de MENSAJE_SUBMENU_ADVERTENCIA dejando claro que se borra
 * el contenido actual de estudiantes.dat e historial.dat
 */
static int pedirOpcionSubmenuDatos(void) {
    int opcion;

    printf("%s\n", MENSAJE_SUBMENU_ADVERTENCIA);
    printf("%s\n", MENSAJE_SUBMENU_OPCION_FIJOS);
    printf("%s\n", MENSAJE_SUBMENU_OPCION_MANUAL);
    printf("%s", MENSAJE_SUBMENU_PROMPT);
    scanf("%d", &opcion);
    limpiarBufferEntradaMenu();

    return opcion;
}

/**
 * @brief Resuelve la opcion de "generar/sobrescribir datos de prueba" del menu principal
 * @return void
 *0
 */
static void generarDatosDePrueba(void) {
    int opcion = pedirOpcionSubmenuDatos();

    while (opcion != OPCION_DATOS_PRUEBA_FIJOS && opcion != OPCION_DATOS_MANUALES) {
        printf("%s\n", MENSAJE_MENU_OPCION_INVALIDA);
        opcion = pedirOpcionSubmenuDatos();
    }

    if (opcion == OPCION_DATOS_PRUEBA_FIJOS) {
        generarEstudiantes(NULL);
        generarHistoriales(NULL);
        printf("%s\n", MENSAJE_DATOS_GENERADOS);
    } else {
        capturarEstudiantes(ARCHIVO_ESTUDIANTES);
        capturarHistoriales(ARCHIVO_HISTORIAL);
        printf("%s\n", MENSAJE_DATOS_CAPTURADOS);
    }
}

/**
 * @brief Pregunta al usuario si desea generar/sobrescribir datos de prueba o usar los archivos existentes
 * @return void
 *
 * Repite la pregunta hasta recibir una opcion valida
 */
static void prepararArchivos(void) {
    int opcion = pedirOpcionDelMenu();

    while (opcion != OPCION_GENERAR_DATOS && opcion != OPCION_USAR_EXISTENTES) {
        printf("%s\n", MENSAJE_MENU_OPCION_INVALIDA);
        opcion = pedirOpcionDelMenu();
    }

    if (opcion == OPCION_GENERAR_DATOS) {
        generarDatosDePrueba();
    }
}

/**
 * @brief Inicializa un estudiante con valores que indican "no encontrado"
 * @param estudiante Puntero al estudiante a inicializar
 * @return void
 *
 * Se usa para inicializar los estudiantes de nota menor y mayor antes de buscar en estudiantes.dat, d
 * Asi si no se encuentra el carnet correspondiente se pueda mostrar un mensaje en el reporte.
*/
static void inicializarEstudianteNoEncontrado(Estudiante* estudiante) {
    copiarTexto(estudiante->carnet, "");
    copiarTexto(estudiante->nombre, MENSAJE_ESTUDIANTE_NO_ENCONTRADO);
    copiarTexto(estudiante->apellidos, "");
    copiarTexto(estudiante->carrera, "");
    estudiante->nivel = 0;
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

    inicializarEstudianteNoEncontrado(&resultados.estudianteNotaMenor);
    inicializarEstudianteNoEncontrado(&resultados.estudianteNotaMayor);

    buscarEstudiante(ARCHIVO_ESTUDIANTES, resultados.estadisticas.carnetNotaMenor, &resultados.estudianteNotaMenor);
    buscarEstudiante(ARCHIVO_ESTUDIANTES, resultados.estadisticas.carnetNotaMayor, &resultados.estudianteNotaMayor);

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
