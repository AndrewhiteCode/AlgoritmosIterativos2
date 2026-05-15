# Proyecto 2: Divide y Vencerás

| Campo | Detalle |
|---|---|
| **Curso** | Diseño de Algoritmos |
| **Docente** | Jacqueline Aldridge Águila |
| **Fecha** | Lunes, 27 de abril de 2026 |
| **Fecha de entrega** | Viernes 15 de mayo 2026, 12:00 (medio día) |
| **Fecha de presentación** | Lunes 18 de mayo |
| **Modalidad** | Grupos de 3 estudiantes (ver consideraciones) |
| **Lenguaje** | C (estándar C11 o C99) |
| **Valor** | 25% de la asignatura |

---

## Descripción del proyecto

En este proyecto, los estudiantes deberán implementar algoritmos de ordenamiento, búsqueda y selección basados en la estrategia de Divide y Vencerás. A partir de los datos del sistema de deportistas desarrollado en el proyecto anterior, analizarán su comportamiento desde una perspectiva teórica y experimental, evaluando además su rendimiento frente a distintos tamaños de entrada.

---

## Objetivos de aprendizaje

- Implementar correctamente algoritmos utilizando la estrategia de Divide y Vencerás.
- Analizar empíricamente la complejidad y el rendimiento de los algoritmos implementados, evaluando además el impacto de sus distintas optimizaciones y variantes.
- Documentar adecuadamente el código desarrollado y los resultados obtenidos en el análisis.

---

## Requisitos técnicos

### Algoritmos de ordenamiento

1. **Merge Sort**: Implementar tanto su versión clásica como una versión optimizada que utilice Insertion Sort para subarreglos de menor tamaño.
   - Se deberá analizar experimentalmente el impacto del umbral utilizado para determinar cuándo aplicar Insertion Sort y cuándo continuar con Merge Sort, evaluando distintos valores y comparando su rendimiento.

2. **Quick Sort**: Deberá implementarse utilizando el esquema de partición de Lomuto, considerando las siguientes variantes para la selección del pivote:
   - Último elemento
   - Primer elemento
   - Elemento aleatorio
   - Mediana de tres

   Se deberá analizar cómo la elección del pivote influye en el rendimiento del algoritmo, considerando su impacto en el mejor, peor y caso promedio.

   Se deberá analizar de manera experimental el comportamiento del algoritmo en el mejor, peor y caso promedio. Asimismo, los resultados obtenidos deberán compararse con los de los algoritmos implementados en la tarea 1.

### Algoritmos de búsqueda

1. **Búsqueda binaria**: Debe implementarse en su versión recursiva.
2. **Búsqueda binaria para rangos**: Variante que permite determinar los límites de un valor en un arreglo ordenado, identificando la primera y última posición en la que aparece.
3. **Búsqueda exponencial**: Variante híbrida basada en búsqueda binaria, que primero determina un rango de búsqueda mediante crecimiento exponencial.
4. **Búsqueda por interpolación**: Algoritmo que estima la posición del elemento a buscar mediante interpolación en un arreglo ordenado.

Se deberá analizar experimentalmente el comportamiento de estos algoritmos en el peor caso y caso promedio.

### Algoritmo de selección

1. **Quick Select**: Búsqueda del k-ésimo elemento.
   - Se deberá analizar el comportamiento en el mejor y peor caso.

> Se recomienda medir los tiempos de ejecución en múltiples ejecuciones para cada tamaño de entrada, con el fin de reducir la variabilidad experimental.

Todos los algoritmos deben implementarse en su versión divide y vencerás y además se deberá indicar su complejidad temporal para el mejor y peor caso.

---

## Aplicación práctica

Los algoritmos implementados deberán integrarse al sistema desarrollado en el Proyecto 1, incorporando las siguientes funcionalidades:

- Ordenar los datos del sistema según distintos campos utilizando Merge Sort y Quick Sort.
- Mostrar el k-ésimo mejor deportista.
- Generar un ranking con los mejores N deportistas, utilizando el puntaje como criterio (considerar el uso de algoritmos de selección).
- Mostrar los deportistas cuyo puntaje se encuentre dentro de un rango determinado.

Los algoritmos deberán seleccionarse justificando la elección en función de criterios como eficiencia, uso de memoria y comportamiento en distintos escenarios.

---

## Entregables

1. **Código fuente**: Archivos `.c` y `.h`
2. **Makefile**: Para compilar el proyecto
3. **Datos de prueba**: Archivos CSV generados por el sistema
4. **Repositorio de GitHub**
5. **Informe** (PDF) que incluya:
   - Descripción de la implementación de los algoritmos
   - Resultados experimentales con gráficos comparativos entre los algoritmos
   - Análisis y conclusiones de los resultados
   - Contribución por estudiante: aporte de cada integrante al trabajo final

---

## Evaluación

| Criterio | Descripción | Puntaje |
|---|---|---|
| Implementación algoritmos de ordenamiento | Correcta implementación (incluyendo optimizaciones y variantes) | 10% |
| Implementación algoritmos de búsqueda | Correcta implementación de los algoritmos | 10% |
| Implementación algoritmos de selección | Correcta implementación de los algoritmos | 10% |
| Interpretación y análisis de complejidad | Análisis teórico y experimental | 30% |
| Funcionalidad | Sistema cumple con todos los requerimientos solicitados | 5% |
| Presentación e informe | Presentación e informes claros, bien estructurados y que evidencian dominio del tema | 35% |

---

## Consideraciones

- Por cada 12 horas de retraso en la entrega, se descontarán **5 décimas**.
- Para que un proyecto sea evaluado, los estudiantes deberán:
  - Entregar el informe.
  - Realizar la presentación.
  - Subir el código a un repositorio de GitHub. Si el repositorio es privado, otorgar acceso al usuario `@JacquelineAldridge`.
- Las presentaciones se realizarán el **18 de mayo** durante los bloques de teoría y práctica, con un máximo de **10 minutos**. Presentaciones pendientes se realizarán el miércoles 20 de mayo.
- Los grupos deben estar conformados por **3 estudiantes** y no podrán repetir combinaciones de integrantes de la Tarea 1. No se permiten grupos de 2 ni trabajos individuales.
- Las presentaciones deben reflejar la información del informe.
- Todos los integrantes deben participar íntegramente en el diseño, desarrollo del código y elaboración del informe.
- Se permiten todas las modificaciones necesarias al Proyecto 1.