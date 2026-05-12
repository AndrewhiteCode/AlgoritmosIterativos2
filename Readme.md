# PALYER: RETURN - Algoritmos de Divide y Vencerás

**Universidad de Magallanes - Diseño de Algoritmos - 2026**

**Proyecto:** Proyecto 2: Divide y Vencerás  
**Estudiantes:** [Andres Barbosa](mailto:abarbosa@umag.cl), [Emmanuel Velásquez](mailto:emvelasq@umag.cl), [Diego Oyarzo](mailto:diegoyaque@umag.cl).

**Docente:** [Jacqueline Aldridge](mailto:jacqueline.aldridge@umag.cl)

**Fechas importantes:**
- Entrega: Viernes 15 de mayo 2026, 12:00 (medio día)
- Presentación: Lunes 18 de mayo

**Proyecto anterior:** [PALYER - Proyecto 1](https://github.com/AndrewhiteCode/AlgoritmosIterativos2) (Algoritmos Iterativos)

El presente repositorio es una continuación del Proyecto 1, enfocándose en la implementación y evaluación de algoritmos basados en la estrategia de **Divide y Vencerás**. Los estudiantes analizarán el comportamiento de estos algoritmos desde una perspectiva teórica y experimental, evaluando su rendimiento frente a distintos tamaños de entrada y estrategias de optimización.

El sistema se desarrolla en lenguaje C e integra los algoritmos recursivos de ordenamiento, búsqueda y selección con el sistema de deportistas desarrollado en el proyecto anterior, permitiendo una comparación empírica entre las estrategias iterativa y divide-y-vencerás.

## Objetivo general

Implementar correctamente algoritmos de ordenamiento, búsqueda y selección utilizando la estrategia de Divide y Vencerás, analizando empíricamente su complejidad y rendimiento, evaluando además el impacto de sus distintas optimizaciones y variantes sobre un sistema de gestión de datos de deportistas.

## Algoritmos Implementados

### Ordenamiento - Divide y Vencerás

#### Merge Sort
- **Versión Clásica**: Implementación estándar con complejidad O(n log n)
- **Versiones Optimizadas**: Incorporan Insertion Sort para subarreglos de tamaño menor que un umbral
  - Merge Sort con umbral 10
  - Merge Sort con umbral 50

#### Quick Sort
- **Estrategias de pivote**:
  - Pivote último elemento (análisis peor caso)
  - Pivote aleatorio (comportamiento promedio)
  - Pivote mediana de tres (mejora del peor caso)
- Implementación con esquema de partición de Lomuto

### Búsqueda Recursiva

- **Búsqueda Binaria Recursiva**: O(log n)
- **Búsqueda Exponencial**: Híbrida con crecimiento exponencial + búsqueda binaria
- **Búsqueda por Interpolación**: Estimación de posición mediante interpolación lineal
- **Búsqueda por Rangos**: Determinación de límites inferior y superior de un valor

### Selección

- **Quick Select**: Búsqueda del k-ésimo elemento usando particionamiento, O(n) promedio

## Instalación y uso de la aplicación.
Una vez clonado el repositorio se espera el siguiente flujo de comandos:
1. `make folders`: Creará la estructura de carpetas necesarias para el funcionamiento del programa.
2. `make`: Compilará el programa.
3. `make run`: Ejecutará el programa.

Una vez ejecutado el programa el usuario se enfrentará a un menú de 6 opciones; finalizada la ejecución del programa, deberá de ejecutar nuevamente `make run` para volver al menú.

A continuación se detallan las funcionalidades del programa:
1. **Generate CSV**: Permite generar un archivo CSV con los datos de entrada del programa, que será utilizado para la ejecución del experimento. El archivo queda almacenado en la carpeta `build/db/`.
2. **Read CSV**: Permite leer el archivo CSV generado en el paso anterior.
3. **Sort CSV**: Permite ordenar el archivo CSV utilizando algoritmos de Divide y Vencerás (Merge Sort con optimizaciones y Quick Sort con distintas estrategias de pivote). La ordenación se realiza en memoria y puede realizarse por cualquiera de los campos que componen un deportista (ID, nombre, equipo, puntaje, competencias).
4. **Search CSV**: Permite buscar un jugador en el archivo CSV bajo distintos algoritmos recursivos de búsqueda (Búsqueda Binaria, Búsqueda Exponencial, Búsqueda por Interpolación y Búsqueda por Rangos) conocido su ID.
5. **Select k-ésimo**: Permite obtener el k-ésimo mejor deportista utilizando Quick Select.
6. **Ranking de mejores N deportistas**: Permite generar un ranking de los mejores N deportistas por puntaje utilizando algoritmos de selección.
7. **Rango de puntajes**: Permite mostrar los deportistas cuyo puntaje se encuentre dentro de un rango determinado.
8. **Run experiment**: Permite ejecutar el experimento de ordenamiento y búsqueda recursiva. El resultado del experimento se almacena en la carpeta `build/db/` y se puede graficar con `make plot` (como se detalla en la sección siguiente).
    - El experimento evalúa 10 algoritmos de ordenamiento (Merge Sort clásico, Merge Sort optimizado con Insertion Sort en umbrales 10 y 50, Quick Sort con 3 estrategias de pivote: último, aleatorio y mediana de tres) y algoritmos de búsqueda recursiva. Se registran tiempos de ejecución para distintos tamaños de entrada.
    - Las variables que pueden ser modificadas se encuentran en el archivo `incs/generate_exec_times.h`: número de deportistas (seleccionado al generar el CSV), número de pasos de la prueba (NUM_STEPS) y cantidad de repeticiones por paso (NUM_TRIALS). Luego de modificar las variables, se debe ejecutar `make clean && make && make run` para recompilar el programa exitosamente.


> [!important]
> El programa incluye un sistema de paginación para mostrar cómodamente una lista de deportistas mayor a $20$ elementos. Para navegar por ella se usa `enter` para avanzar a los siguientes $20$ elementos y `q` para salir de la paginación y continuar con la ejecución del programa.

## Generación de gráficos y animaciones

El repositorio incluye una utilidad en Python para visualizar los resultados experimentales a partir del archivo `experiment.csv`.

### Comandos disponibles

- `make install-allegro6`: instala las dependencias necesarias para la utilidad de visualización. Si el entorno actual no es adecuado, el instalador puede crear un entorno virtual dentro de `allegro6/`.
- `make plot`: ejecuta la utilidad de graficación y genera una animación GIF junto con una imagen PNG del frame final.

### Estructura relacionada

La funcionalidad asociada a `make plot` se encuentra encapsulada en la carpeta `allegro6/`, donde se ubican el script principal en Python, el archivo de dependencias y el instalador correspondiente a sistemas **UNIX**.

### Salida esperada

Al ejecutar `make plot`, el programa procesa los datos experimentales y genera archivos gráficos que permiten visualizar la evolución y comparación de los algoritmos analizados en `docs/results/`.

## Manejo de errores

Dentro del archivo [errors.c](src/errors.c) se encuentra la función `print_error` que se encarga de manejar los errores que puedan ocurrir en el programa. Los códigos de error que se manejan son los siguientes:

| Código de error | Descripción                                        |
| --------------- | ---------------------------------------------------|
|100              | File <target> could not be read                    |
|101              | File <target> could not be opened                  |
|102              | It was not possible to allocate memory for <target>|
|301              | The number of players is too high, console will show the first MAX_CONSOLE_READABLE_PLAYERS players|

## Estructura del Informe

El informe se organiza en las siguientes secciones:

1. **Introducción**: Contexto del problema y motivación
2. **Objetivos**: Objetivos generales y específicos
3. **Desarrollo**: Descripción detallada de la implementación y resultados experimentales
   - Implementación de algoritmos de ordenamiento (Merge Sort, Quick Sort)
   - Implementación de algoritmos de búsqueda recursiva
   - Implementación de algoritmo de selección (Quick Select)
   - Análisis teórico de complejidad temporal
   - Resultados experimentales y comparativas
4. **Conclusiones**: Análisis de los resultados y observaciones
5. **Contribución por integrante**: Detalle del trabajo realizado por cada estudiante

## Consideraciones Importantes

- Este proyecto es una continuación del Proyecto 1, extendiendo el sistema de deportistas con algoritmos de Divide y Vencerás
- Se recomienda realizar múltiples ejecuciones de cada algoritmo para cada tamaño de entrada, con el fin de reducir la variabilidad experimental
- Todos los algoritmos deben implementarse en su versión recursiva/divide y vencerás
- Se debe documentar claramente la complejidad temporal en mejor y peor caso para cada algoritmo
- Los resultados experimentales deben compararse con el análisis teórico esperado
