#include <stdio.h>
#include <stdlib.h>
#include "smoke.h"
#include "generate_exec_times.h"
#include "generator.h"

extern SortAlgorithmFlag current_active_flags;

void run_smoke_tests() {
    printf("\n" "\033[0;35m" "=== STARTING SMOKE TESTS ===" "\033[0m" "\n");

    set_generator_quiet(1);
    set_experiment_quiet(0);
    set_experiment_show_samples(0);

    printf("1) Generando conjuntos de datos (Sorted, Inverted, Shuffled 25000 n)...\n");
    generate_csv(25000, 1); rename("build/db/players.csv", "build/db/players_sorted.csv");
    generate_csv(25000, 2); rename("build/db/players.csv", "build/db/players_inverted.csv");
    generate_csv(25000, 3); rename("build/db/players.csv", "build/db/players_shuffled.csv");

    printf("Guardando informacion del equipo...\n");
    system("uname -a > docs/results/system_info.txt");
    system("lscpu >> docs/results/system_info.txt");

    // ============================================
    // EXPERIMENTO 1: ORDENAMIENTO (Merge Opt 16 vs Quicksort)
    // ============================================
    printf("\n" "\033[44m" "--- Exp 1: Ordenamiento ---" "\033[0m" "\n");
    SortAlgorithmFlag exp1_flags[] = {FLAG_MERGE_OPT16, FLAG_QUICK_LAST, FLAG_QUICK_RANDOM, FLAG_QUICK_MEDIAN, 0};
    set_active_sort_flags(&current_active_flags, exp1_flags);
    
    printf("\n-> Exp 1 (Mejor/Peor/Promedio) en progreso...\n");
    run_sort_experiments(
        "build/db/players_sorted.csv",
        "build/db/players_inverted.csv",
        "build/db/players_shuffled.csv",
        "build/db/ordenamiento"
    );

    // ============================================
    // EXPERIMENTO 2: BUSQUEDAS
    // ============================================
    printf("\n" "\033[44m" "--- Exp 2: Busqueda ---" "\033[0m" "\n");
    // Los algoritmos de busqueda requieren arreglos ordenados
    printf("\n-> Exp 2 (Promedio/Peor) en progreso...\n");
    run_search_experiments("build/db/players_sorted.csv", "build/db/busqueda");


    // ============================================
    // EXPERIMENTO 3: SELECCION QUICK SELECT
    // ============================================
    printf("\n" "\033[44m" "--- Exp 3: Selección ---" "\033[0m" "\n");
    printf("\n-> Exp 3 (Mejor/Peor) en progreso...\n");
    run_select_experiments(
        "build/db/players_sorted.csv",
        "build/db/players_shuffled.csv",
        "build/db/seleccion"
    );


    // ============================================
    // EXPERIMENTO 4: THRESHOLD MERGE SORT (Ya implementado, forzamos ejecucion base)
    // ============================================
    printf("\n" "\033[44m" "--- Exp 4: Threshold de optimizacion ---" "\033[0m" "\n");
    printf("\n-> Exp 4 (Threshold justification) en progreso...\n");
    system("cp build/db/players_shuffled.csv build/db/players.csv");
    run_threshold_experiment();

    // Revertir a todas las flags y salidas
    current_active_flags = FLAG_ALL_SORTS;
    set_generator_quiet(0);
    set_experiment_quiet(0);
    set_experiment_show_samples(1);

    printf("\n" "\033[0;35m" "=== SMOKE TESTS COMPLETED ===" "\033[0m" "\n");
    printf("Recuerda ejecutar 'make plot' para generar los graficos.\n\n");
}
