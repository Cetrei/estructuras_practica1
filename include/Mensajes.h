#ifndef MENSAJES_H
#define MENSAJES_H

/**
 * @brief Todos los mensajes que se usan en el programa para modificarlos facil
 * - Ademas como define es una constante de compilacion es mas eficiente
 */

#define MENSAJE_SIN_REGISTROS "No existen registros"
#define MENSAJE_ERROR_CARGA_HISTORIAL "No se pudo cargar el historial"
#define MENSAJE_ESTUDIANTE_NO_ENCONTRADO "(no encontrado en estudiantes.dat)"

#define MENSAJE_MENU_PREGUNTA "Desea generar datos de prueba o usar los archivos existentes?"
#define MENSAJE_MENU_OPCION_GENERAR "1. Generar/sobrescribir datos de prueba"
#define MENSAJE_MENU_OPCION_EXISTENTES "2. Usar archivos existentes (estudiantes.dat / historial.dat)"
#define MENSAJE_MENU_PROMPT "Opcion: "
#define MENSAJE_MENU_OPCION_INVALIDA "Opcion invalida, intentalo otra vez"
#define MENSAJE_DATOS_GENERADOS "Datos de prueba generados exitosamente"
#define MENSAJE_DATOS_CAPTURADOS "Datos capturados y guardados exitosamente"

#define MENSAJE_SUBMENU_ADVERTENCIA "ADVERTENCIA: cualquiera de estas opciones sobrescribe el contenido actual de estudiantes.dat e historial.dat"
#define MENSAJE_SUBMENU_OPCION_FIJOS "1. Usar datos de prueba fijos"
#define MENSAJE_SUBMENU_OPCION_MANUAL "2. Introducir datos manualmente"
#define MENSAJE_SUBMENU_PROMPT "Opcion: "

#define REPORTE_TITULO                      "REPORTE DEL HISTORIAL ACADEMICO"
#define REPORTE_CHAR_SEPARADOR              '='
#define REPORTE_ETIQUETA_CANTIDAD_REGISTROS "Cantidad de registros : "
#define REPORTE_ETIQUETA_NOTA_MENOR         "Nota menor            : "
#define REPORTE_ETIQUETA_NOTA_MAYOR         "Nota mayor            : "
#define REPORTE_ETIQUETA_NOTA_PROMEDIO      "Nota promedio         : "
#define REPORTE_ETIQUETA_ESTUDIANTE         "Estudiante            : "

#endif
