# Práctica #1 — EIF207 Estructuras de Datos

Fundamentos de Eficiencia Computacional y TDA · Estructura Lineal: Arreglos Dinámicos
II Ciclo 2026 · Msc. Johnny Villalobos Murillo

Lee `historial.dat` y `estudiantes.dat` (binarios), carga el historial en un
arreglo dinámico y genera un reporte con nota menor, nota mayor (con su
estudiante) y nota promedio.

## Documentación en línea

La documentación completa (Doxygen del código + documento técnico en PDF) se
publica automáticamente en GitHub Pages en cada push a `master`:

**https://TU-USUARIO.github.io/practica1/**

## Dónde está lo que pide el enunciado

| Requisito del enunciado (`enunciado.txt`)                              | Dónde está |
|---|---|
| Estructura `Estudiante` / `Historial`                                  | [`include/Tipos.h`](./include/Tipos.h) |
| Parte 1 — Abrir el binario y contar registros                          | `contarRegistros()` en [`src/Registros.c`](./src/Registros.c) |
| Parte 2 — Reservar memoria dinámica y cargar el arreglo                | `cargarHistorial()` en [`src/Registros.c`](./src/Registros.c) (usa `malloc`/`free`) |
| Parte 3 — Nota menor, nota mayor y promedio (un solo recorrido)        | `calcularEstadisticas()` en [`src/Registros.c`](./src/Registros.c) |
| Parte 3 — Búsqueda secuencial del estudiante por carnet                | `buscarEstudiante()` en [`src/Registros.c`](./src/Registros.c) |
| Parte 4 — Reporte con el formato exacto del enunciado                  | [`src/Reporte.c`](./src/Reporte.c) (`construirReporte()` / `imprimirReporte()`) |
| Orquestación general del programa                                      | [`src/Controlador.c`](./src/Controlador.c) (`ejecutarPractica()`) |
| Entregable — Código fuente documentado                                 | Comentarios estilo Doxygen en todo [`include/`](./include) y [`src/`](./src); ver la versión renderizada en GitHub Pages |
| Entregable — Programa ejecutable                                       | Se genera con `make` (ver más abajo) |
| Entregable — Documento técnico (estructuras, algoritmos, costo computacional) | [`docs/documentoTecnico.tex`](./docs/documentoTecnico.tex) → [`documentoTecnico.pdf`](./documentoTecnico.pdf) |
| Enunciado original                                                     | [`enunciado.txt`](./enunciado.txt) |

> **Nota sobre memoria dinámica:** el enunciado pide `new`/`delete`, que son
> palabras reservadas de C++. Esta solución está escrita en C puro y usa su
> equivalente directo, `malloc()`/`free()` (ver `cargarHistorial()` en
> `Registros.c` y el `free()` en `Controlador.c`). Si el/la docente exige el
> uso literal de `new`/`delete`, esto implicaría reescribir el proyecto en C++.

## Compilar y ejecutar

```bash
make            # compila con gcc -Wall -Wextra, genera ./practica1
./practica1
```

Al ejecutar, el programa pregunta si se desean generar archivos `.dat` de
prueba (`estudiantes.dat` / `historial.dat` con datos fijos) o usar los
archivos ya existentes en el directorio actual.

Para limpiar los binarios generados:

```bash
make clean
```

## Estructura del código

```
main.c                 → punto de entrada, llama ejecutarPractica()
include/Tipos.h         → structs Estudiante, Historial, Estadisticas
include/Bool.h          → booleano propio (TRUE/FALSE)
include/Resultado.h     → enum CodigoResultado (EXITO, ARCHIVO_NO_ENCONTRADO, ...)
include/Mensajes.h      → strings de mensajes y etiquetas del reporte
src/Controlador.c       → orquesta el flujo completo (ejecutarPractica())
src/Registros.c         → contar/cargar historiales, calcular estadísticas, buscar estudiante
src/Reporte.c           → arma e imprime el reporte final
src/Datos.c             → genera .dat de prueba si no se tienen los originales
src/Utils.c             → utilidades de texto y número→texto (sin <string.h>)
```

## Documento técnico

El documento técnico completo (estructuras, algoritmos de cada parte y el
análisis del costo computacional con complejidad real, algorítmica y
espacial de cada función) está en LaTeX en
[`docs/documentoTecnico.tex`](./docs/documentoTecnico.tex) y se compila con
`make doc`, o se puede leer directamente en
[`documentoTecnico.pdf`](./documentoTecnico.pdf).
