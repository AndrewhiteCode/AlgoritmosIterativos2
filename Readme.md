# Proyecto 1 — Algoritmos iterativos

**Universidad de Magallanes - Diseño de Algoritmos - 2026**
**Estudiantes:** [Andres Barbosa](mailto:abarbosa@umag.cl), [Milton Hernández](mailto:mhern@umag.cl), [Iván Gallardo](mailto:ivangall@umag.cl).
**Docente:** [Jacqueline Aldridge ](mailto:jacqueline.aldridge@umag.cl)

El presente repositorio tiene como objetivo la comparación y comprobación de los órdenes de complejidad de distintos algoritmos de ordenamiento y búsqueda, mediante su implementación y evaluación sobre datos artificialmente generados de deportistas.

El sistema se desarrolla en lenguaje C y considera la generación de registros con atributos como ID, nombre, equipo, puntaje y cantidad de competencias, los cuales servirán como base para el análisis teórico y experimental del comportamiento de los algoritmos en distintos tamaños de entrada.

En esta primera etapa, el repositorio está orientado a la construcción de la base del sistema, incluyendo la generación y almacenamiento de datos. La explicación detallada de los algoritmos de ordenamiento, búsqueda y su implementación será incorporada progresivamente a medida que el proyecto avance.

## Objetivo general

Desarrollar un sistema que permita generar, almacenar, ordenar y buscar información de deportistas, con el fin de analizar empíricamente y contrastar teóricamente el rendimiento de distintos algoritmos clásicos de ordenamiento y búsqueda.

> [!NOTE] Nota
> Este README corresponde a una versión inicial del proyecto. La documentación será ampliada conforme se implementen las funcionalidades y algoritmos requeridos.

## Manejo de errores

Dentro del archivo [errors.c](src/errors.c) se encuentra la función `print_error` que se encarga de manejar los errores que puedan ocurrir en el programa. Los códigos de error que se manejan son los siguientes:

| Código de error | Descripción                            |
| --------------- | ---------------------------------------|
| 100             | No se pudo leer el archivo \<target\>  |
| 101             | No se pudo abrir el archivo \<target\> |
