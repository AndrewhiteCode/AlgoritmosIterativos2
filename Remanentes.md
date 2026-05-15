# Plan de Gestión: Informe vs Código C (Proyecto 2: Divide y Vencerás)

## Estado actual
Tras la revisión de la estructura del proyecto y los archivos en el repositorio, se detecta lo siguiente:

### 1. Código C (Completo)
El código cumple íntegramente con los requerimientos técnicos del Proyecto 2:
- **Ordenamiento:** Implementado `merge_sort_classic` y `merge_sort_optimized` (con umbral para Insertion Sort). Implementado `quick_sort` con esquema partición Lomuto y las 4 variantes de selección de pivote (Último, Primero, Aleatorio, Mediana de 3).
- **Búsqueda:** Implementadas `binary_search_recursive`, `binary_search_range`, `exponential_search` e `interpolation_search`.
- **Selección:** Implementado `quick_select` para el k-ésimo elemento.

### 2. Informe (En progreso - Urgente)
El archivo `desarrollo.tex` principal aún describe exclusivamente los algoritmos correspondientes a la **Tarea 1** (Búsqueda secuencial, Binaria iterativa, Swap, Insertion y Selection Sort). 

## Remanentes / Faltantes a integrar en el Informe

1. **Análisis Teórico de Algoritmos de Ordenamiento (D&V):**
   - Análisis de complejidad temporal y pseudocódigos para **Merge Sort clásico**.
   - Análisis teórico y justificación de optimización de **Merge Sort** junto con Insertion Sort.
   - Análisis de complejidad de **Quick Sort** indicando cómo afecta en el mejor, peor y promedio cada modo de elegir el pivote.

2. **Análisis Teórico de Algoritmos de Búsqueda (D&V):**
   - **Búsqueda Binaria recursiva** y **Búsqueda Binaria para rangos**.
   - **Búsqueda Exponencial** y **Búsqueda por Interpolación**.

3. **Análisis Teórico de Algoritmos de Selección (D&V):**
   - **Quick Select** (Mejor y peor caso).

4. **Resultados Experimentales (Próximo paso tras generar plots):**
   - Gráficos comparativos del umbral de Merge Sort vs Merge Sort clásico.
   - Gráficos comparativos y análisis de las variaciones del pivote de Quick Sort.
   - Comparación del rendimiento de Quick Sort contra los algoritmos previos de la Tarea 1.
   - Gráficos evaluativos de las búsquedas en peor caso y promedio.
   - Justificaciones con base empírica respecto al costo vs beneficio de cada implementación.

5. **Aplicación Práctica / Funcionalidad del Sistema:**
   - Describir cómo se integraron los algoritmos para visualizar un Ranking de N deportistas, listar en rangos de puntajes u ordenar el set completo.

6. **Actualización Estructural del Documento:**
   - Revisiones a los documentos de las contribuciones si aplica (`contribucion_{andres, diego, emmanuel}.tex`).
   - Conclusiones refactorizadas enfocadas en las ventajas y desventajas del paradigma de _Divide y Vencerás_.
