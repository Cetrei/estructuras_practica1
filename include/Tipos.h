#ifndef TIPOS_H
#define TIPOS_H

/**
 * @brief Representacion de un registro en `estudiantes.dat`
 */
typedef struct {
    char carnet[15];
    char nombre[40];
    char apellidos[40];
    char carrera[40];
    int nivel;
} Estudiante;

/**
 * @brief Representacion de un registro en `historial.dat`
 */
typedef struct {
    char carnet[15];
    char codigoCurso[10];
    char nombreCurso[50];
    int ciclo;
    int anio;
    float nota;
} Historial;

/**
 * @brief Resultado de recorrer el arreglo de historiales
 *
 * Agrupa nota menor, nota mayor, el carnet de cada estudiante asociado y el promedio general
 */
typedef struct {
    float notaMenor;
    float notaMayor;
    float notaPromedio;
    char carnetNotaMenor[15];
    char carnetNotaMayor[15];
} Estadisticas;

#endif
