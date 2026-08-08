# Práctica #1 | EIF207 Estructuras de Datos
![LaTeX](https://img.shields.io/badge/LaTeX-informe-008080?logo=latex&logoColor=white)
![C](https://img.shields.io/badge/C-implementación-A8B9CC?logo=c&logoColor=white)
![Docs: Doxygen](https://img.shields.io/badge/docs-doxygen-2C4AA8?logo=doxygen&logoColor=white)
![Build: Make](https://img.shields.io/badge/build-make-427819?logo=gnu&logoColor=white)
![Pages](https://github.com/Cetrei/estructuras_practica1/actions/workflows/pages.yml/badge.svg)

## Documentación en línea
**https://Cetrei.github.io/estructuras_practica1/**

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
| Captura manual de datos (menu)                                       | [`src/Captura.c`](./src/Captura.c)         |
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
