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

Una vez ejecutado el programa el usuario se enfrentará a un menú principal de 6 opciones; finalizada y validada cada funcionalidad, el menú volverá a aparecer o deberá ser reiniciado:
1. **Generate new CSV**: Permite generar un archivo CSV con los datos de entrada del programa. Puede elegirse la cantidad de deportistas y el estado base del arreglo (ordenado, inverso o aleatorio). El archivo queda almacenado en la carpeta `build/db/`.
2. **Read actual CSV**: Permite leer el archivo CSV generado en el paso anterior y lo muestra por consola utilizando el sistema de paginación.
3. **Sort CSV**: Permite ordenar recursiva e iterativamente el archivo CSV, listando los diversos métodos implementados: Swap Sort, Insertion Sort, Selection Sort, Cocktail Shaker Sort, y los Algoritmos de Divide y Vencerás (Merge Sort Clásico, Merge Sort Optimizado con umbral dinámico, Quick Sort con pivote final, primer elemento, aleatorio y mediana de 3). La ordenación puede indicarse bajo cualquier subcampo o criterio del CSV (ID, Name, Team, Score, Competitions).
4. **Data Analytics & Rankings**: Submenú de análisis que conjunta varias herramientas de búsqueda y ranking avanzadas:
   - *Generate Top N Ranking*: Clasifica los mejores deportistas seleccionando primero un formato de ordenamiento avanzado, presentando finalmente el top N según sus puntajes.
   - *Find the K-th Best Athlete*: Utiliza `quick_select` (O(n)) o la búsqueda completa para encontrar la n-ésima posición por puntaje exacto.
   - *Search Athletes by Score Range*: Muestra a los deportistas cuyo puntaje se encuentra dentro de un rango numérico provisto a elección.
   - *Search Athlete by exact ID*: Permite buscar un ID específico probando a elección una Búsqueda Lineal o bien métodos avanzados como Búsqueda Binaria Pura, Iterativa, Recursiva, Exponencial o Interpolación. 
5. **Run experiment**: Permite ejecutar el experimento masivo de ordenamiento y búsqueda recursiva. El resultado experimental se almacena en la estructura en `build/db/experiment.csv` y se puede graficar su visualización con `make plot`.
    - El experimento evalúa 10 algoritmos de ordenamiento distintos, desde elementales cuadráticos en $O(n^2)$ hasta estructuras complejas optimizadas de tipo $O(n \log n)$. 
    - Las variables del ecosistema del test habitan y se alteran formalmente en `incs/generate_exec_times.h`: número de pasos experimentales (NUM_STEPS) y las repeticiones por cada paso (NUM_TRIALS). Acorde a las variaciones se solicita purgar los compilados y refrecar el core haciendo un `make clean && make`.
6. **Exit**: Cierra la sesión activa del binario por retorno nulo.


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
