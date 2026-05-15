#include <stdio.h>
#include "smoke.h"
#include "generate_exec_times.h"
#include "generator.h"

extern SortAlgorithmFlag current_active_flags;

void run_smoke_tests() {
    printf("\n" "\033[0;35m" "=== STARTING SMOKE TESTS ===" "\033[0m" "\n");

    printf("1) Generando conjuntos de datos (Sorted, Inverted, Shuffled 5000 n)...\n");
    generate_csv(5000, 1); system("mv build/db/players.csv build/db/players_sorted.csv");
    generate_csv(5000, 2); system("mv build/db/players.csv build/db/players_inverted.csv");
    generate_csv(5000, 3); system("mv build/db/players.csv build/db/players_shuffled.csv");

    // ============================================
    // EXPERIMENTO 1: ORDENAMIENTO (Merge Opt 16 vs Quicksort)
    // ============================================
    printf("\n" "\033[44m" "--- Exp 1: Ordenamiento ---" "\033[0m" "\n");
    SortAlgorithmFlag exp1_flags[] = {FLAG_MERGE_OPT16, FLAG_QUICK_LAST, FLAG_QUICK_RANDOM, FLAG_QUICK_MEDIAN, 0};
    set_active_sort_flags(&current_active_flags, exp1_flags);
    
    printf("\n-> Exp 1 (Mejor Caso) en progreso...\n");
    run_experiment("build/db/players_sorted.csv", "build/db/exp1_ordenamiento_mejor_experiment.csv");
    
    printf("\n-> Exp 1 (Peor Caso) en progreso...\n");
    run_experiment("build/db/players_inverted.csv", "build/db/exp1_ordenamiento_peor_experiment.csv");
    
    printf("\n-> Exp 1 (Caso Promedio) en progreso...\n");
    run_experiment("build/db/players_shuffled.csv", "build/db/exp1_ordenamiento_promedio_experiment.csv");

    // ============================================
    // EXPERIMENTO 2: BUSQUEDAS
    // ============================================
    printf("\n" "\033[44m" "--- Exp 2: Busqueda ---" "\033[0m" "\n");
    // Los algoritmos de busqueda requieren arreglos ordenados
    printf("\n-> Exp 2 (Promedio) en progreso...\n");
    run_search_experiment("build/db/players_sorted.csv", "build/db/exp2_busqueda_promedio_experiment.csv", 0);
    
    printf("\n-> Exp 2 (Peor Caso) en progreso...\n");
    // Pseudo-peor: buscar siempre el del final en arreglos muy grandes
    run_search_experiment("build/db/players_sorted.csv", "build/db/exp2_busqueda_peor_experiment.csv", 1);


    // ============================================
    // EXPERIMENTO 3: SELECCION QUICK SELECT
    // ============================================
    printf("\n" "\033[44m" "--- Exp 3: Selección ---" "\033[0m" "\n");
    printf("\n-> Exp 3 (Mejor Caso) en progreso...\n"); // Pivote aleatorio, array shuffle
    run_select_experiment("build/db/players_shuffled.csv", "build/db/exp3_seleccion_mejor_experiment.csv", 0);

    printf("\n-> Exp 3 (Peor Caso) en progreso...\n"); // Pivote last, array ordenado
    run_select_experiment("build/db/players_sorted.csv", "build/db/exp3_seleccion_peor_experiment.csv", 1);


    // ============================================
    // EXPERIMENTO 4: THRESHOLD MERGE SORT (Ya implementado, forzamos ejecucion base)
    // ============================================
    printf("\n" "\033[44m" "--- Exp 4: Threshold de optimizacion ---" "\033[0m" "\n");
    printf("\n-> Exp 4 (Threshold justification) en progreso...\n");
    run_threshold_experiment();

    // Revertir a todas las flags
    current_active_flags = FLAG_ALL_SORTS;

    printf("\n" "\033[0;35m" "=== SMOKE TESTS COMPLETED ===" "\033[0m" "\n");
    printf("Recuerda ejecutar 'make plot' para generar los graficos.\n\n");
}
