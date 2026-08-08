# Práctica #1 — EIF207 Estructuras de Datos

## Documentación en línea
**https://Cetrei.github.io/practica1/**

## Requisitos

| Requisitos del enunciado                                             | Ruta |
|---|---|
| Estructura `Estudiante` / `Historial`                                | [`include/Tipos.h`](./include/Tipos.h)     |
| Parte 1: Abrir el binario y contar registros                         | [`src/Registros.c`](./src/Registros.c)     |
| Parte 2: Reservar memoria dinámica y cargar el arreglo               | [`src/Registros.c`](./src/Registros.c)     |
| Parte 3: Nota menor, nota mayor y promedio (un solo recorrido)       | [`src/Registros.c`](./src/Registros.c)     |
| Parte 3: Búsqueda secuencial del estudiante por carnet               | [`src/Registros.c`](./src/Registros.c)     |
| Parte 4:  Reporte con el formato exacto del enunciado                | [`src/Reporte.c`](./src/Reporte.c)         |
| Flujo principal del programa                                         | [`src/Controlador.c`](./src/Controlador.c) |
| Entregable: Código fuente documentado                                | Comentarios tipo JSDocs en todo [`include/`](./include) |
| Entregable: Programa ejecutable                                      | Generado con `make` |
| Entregable: Documento técnico                                        | [`documentoTecnico.pdf`](./documentoTecnico.pdf) |

## Compilar y ejecutar
```bash
make
./practica1
```

Para limpiar los binarios generados:

```bash
make clean
```

## Documento técnico
Archivo de edicion LaTeX
[`docs/documentoTecnico.tex`](./docs/documentoTecnico.tex) 
Compilado con`make doc`, o se puede leer directamente en
[`documentoTecnico.pdf`](./documentoTecnico.pdf).
