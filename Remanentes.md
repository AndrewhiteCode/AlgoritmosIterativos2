# Plan de Gestión: Informe vs Código C (Proyecto 2: Divide y Vencerás)

## Estado actual
Tras la reestructuración inicial del documento LaTeX, el estado es el siguiente:

### 1. Código C (Completo ✓)
El código cumple íntegramente con los requerimientos técnicos del Proyecto 2:
- **Ordenamiento:** Implementado `merge_sort_classic` y `merge_sort_optimized` (con umbral). Implementado `quick_sort` (Lomuto) y 4 variantes de pivote.
- **Búsqueda:** `binary_search_recursive`, `binary_search_range`, `exponential_search` e `interpolation_search`.
- **Selección:** `quick_select`.

### 2. Informe (Estructura formal lista ✓ / Contenido en progreso)
Se limpió el rastro de la Tarea 1. Los archivos `introduccion.tex`, `objetivos.tex`, `conclusiones.tex`, `anexos.tex`, `Informe.tex` y `desarrollo.tex` ya poseen el contexto, abstract y apartados exclusivos de *Divide y Vencerás*. Sin embargo, **las secciones se encuentran con placeholders (textos temporales)** a la espera de ser rellenadas.

---

## Tareas Pendientes (Remanentes)

### Paso 1: Análisis Teórico (Pseudocódigos y Complejidad)
Requiere redactar en LaTeX las fórmulas matemáticas, tablas de costo y algoritmos de:
- [ ] **Merge Sort**: Clásico y análisis de la justificación matemática del umbral vs Insertion Sort.
- [ ] **Quick Sort**: Análisis de complejidad de sus 4 heurísticas de pivote (Mejor, peor y promedio).
- [ ] **Búsquedas**: Binaria (recursiva y rango), Exponencial y por Interpolación. 
- [ ] **Selección**: Quick Select (Mejor y peor caso).

### Paso 2: Resultados Experimentales (Esperando Plots)
Una vez que se generen los gráficos, insertarlos y comentarlos:
- [ ] Comparativa empírica del umbral de Merge Sort vs Clásico.
- [ ] Comparativa empírica de pivotes en Quick Sort.
- [ ] Gráficos evaluativos de las búsquedas en peor caso y promedio.
- [ ] **Contraste de Paradigmas**: Comparación del rendimiento de Quick Sort/Merge Sort $\mathcal{O}(n \log n)$ contra los algoritmos previos de la Tarea 1 $\mathcal{O}(n^2)$.

### Paso 3: Aplicación Práctica / Funcionalidad
- [ ] Describir con capturas/texto cómo la consola del sistema implementa las funciones de ranking N, límite de rangos, y ordenamiento local.

### Paso 4: Cierre Documental
- [ ] Rellenar los párrafos pre-estructurados de `conclusiones.tex` basados en lo que digan los gráficos experimentales.
- [ ] Actualizar archivos de contribución de equipo (`contribucion_{andres, diego, emmanuel}.tex`).
