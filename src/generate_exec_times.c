/**
 * @file generate_exec_times.c
 * @author Andres Barbosa, Milton Hernandez, Ivan Gallardo
 * @brief Funciones para la ejecución de pruebas experimentales de algoritmos.
 */

#include <stdlib.h>
#include <string.h>
#include "generate_exec_times.h"
#include "utilities.h"

// Variable global o estática local para almacenar las flags activadas
SortAlgorithmFlag current_active_flags = FLAG_ALL_SORTS;

/**
 * @brief Setea una flag única a partir de un arreglo de flags pre-seleccionadas
 */
void set_active_sort_flags(SortAlgorithmFlag* active_flags, SortAlgorithmFlag selected_flags[]) {
    *active_flags = 0;
    int i = 0;
    while(selected_flags[i] != 0 && i < 10) { /* Asumiremos 0 como finalizador o un tope de 10 */
        *active_flags |= selected_flags[i];
        i++;
    }
}

/**
 * @brief Ejecuta un experimento masivo comparando 10 algoritmos de ordenamiento

 * y los algoritmos de búsqueda, generando un reporte detallado en CSV.
 */
void run_experiment(const char* target_file, const char* out_filename)
{
	int n = 0; 
	Player* players;
	if ((players = load_players((char*)target_file, &n)) == NULL) {
			return;
	}
	printf("Arreglo de jugadores cargado desde %s\n", target_file);
	print_player_array(players, n);

	const int num_points = NUM_STEPS;
	
	// Inicializamos los arreglos de jugadores
	Player* swapSortP = malloc(n * sizeof(Player));
	Player* insertionSortP = malloc(n * sizeof(Player));
	Player* selectionSortP = malloc(n * sizeof(Player));
	Player* cocktailP = malloc(n * sizeof(Player));
	Player* mergeClassicP = malloc(n * sizeof(Player));
	Player* mergeOpt10P = malloc(n * sizeof(Player));
	Player* mergeOpt50P = malloc(n * sizeof(Player));
	Player* quickLastP = malloc(n * sizeof(Player));
	Player* quickRandP = malloc(n * sizeof(Player));
	Player* quickMedianP = malloc(n * sizeof(Player));

	if (!swapSortP || !insertionSortP || !selectionSortP || !cocktailP || !mergeClassicP || !mergeOpt10P || !mergeOpt50P || !quickLastP || !quickRandP || !quickMedianP) {
		print_error(102, "players", NULL);
		return;
	}

	// Abrimos el archivo de resultados
	FILE *csv = fopen(out_filename, "w");
	if (csv == NULL) {
		print_error(101, out_filename, NULL);
		return;
	}

    // ¡La magia para que main.py funcione! Todos tienen "Sort" en el nombre.
	fprintf(csv, "N,Swap Sort,Insertion Sort,Selection Sort,Cocktail Shaker Sort,Merge Sort Classic,Merge Sort Opt(16),Merge Sort Opt(50),Quick Sort (Last),Quick Sort (Random),Quick Sort (Median)\n");

	// header
	printf(PURPLE "╔══════════════════════════════════════════════════════╗\n");

	for (int s = 0; s < num_points; s++) {
		int k = (num_points == 1) ? n : 1 + (s * (n - 1)) / (num_points - 1);

		printf(PURPLE "║" MAGENTA " Procesando n =" WHITE" %8d" PURPLE "                             ║\n", k);
		printf(PURPLE "║" MAGENTA " Paso:" WHITE" %4d/%4d" PURPLE "                                     ║\n", s+1, num_points);
		clock_t start, end;

		// --- Tiempos Swap Sort ---
		double tSwap = 0;
		if (current_active_flags & FLAG_SWAP_SORT) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(swapSortP, players, k * sizeof(Player));
				start = clock(); swap_sort(swapSortP, k, compare_id); end = clock();
				tSwap += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tSwap /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_BLUE "\tSwap Sort:             " WHITE " %f\t" PURPLE "       ║\n", tSwap);
		}
 
		// --- Tiempos Insertion Sort ---
		double tIns = 0;
		if (current_active_flags & FLAG_INSERTION_SORT) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(insertionSortP, players, k * sizeof(Player));
				start = clock(); insertion_sort(insertionSortP, k, compare_id); end = clock();
				tIns += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tIns /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_BLUE "\tInsertion Sort:        " WHITE " %f\t" PURPLE "       ║\n", tIns);
		}
		
		// --- Tiempos Selection Sort ---
		double tSel = 0;
		if (current_active_flags & FLAG_SELECTION_SORT) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(selectionSortP, players, k * sizeof(Player));
				start = clock(); selection_sort(selectionSortP, k, compare_id); end = clock();
				tSel += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tSel /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_BLUE "\tSelection Sort:        " WHITE " %f\t" PURPLE "       ║\n", tSel);
		}

		// --- Tiempos Cocktail Shaker Sort ---
		double tCock = 0;
		if (current_active_flags & FLAG_COCKTAIL_SORT) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(cocktailP, players, k * sizeof(Player));
				start = clock(); cocktail_shaker_sort(cocktailP, k, compare_id); end = clock();
				tCock += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tCock /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_BLUE "\tCocktail Shaker Sort:  " WHITE " %f" PURPLE "         ║\n", tCock);
		}

        // --- Tiempos Merge Sort Classic ---
		double tMergeClas = 0;
		if (current_active_flags & FLAG_MERGE_CLASSIC) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(mergeClassicP, players, k * sizeof(Player));
				start = clock(); merge_sort_classic(mergeClassicP, k, compare_id); end = clock();
				tMergeClas += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tMergeClas /= NUM_TRIALS;
			printf(PURPLE "║" YELLOW "\tMerge Sort Classic:    " WHITE " %f" PURPLE "         ║\n", tMergeClas);
		}

        // --- Tiempos Merge Sort Opt(16) ---
		double tMerge10 = 0;
		if (current_active_flags & FLAG_MERGE_OPT16) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(mergeOpt10P, players, k * sizeof(Player));
				start = clock(); merge_sort_optimized(mergeOpt10P, k, 16, compare_id); end = clock();
				tMerge10 += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tMerge10 /= NUM_TRIALS;
			printf(PURPLE "║" YELLOW "\tMerge Sort Opt(16):    " WHITE " %f" PURPLE "         ║\n", tMerge10);
		}

        // --- Tiempos Merge Sort Opt(50) ---
		double tMerge50 = 0;
		if (current_active_flags & FLAG_MERGE_OPT50) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(mergeOpt50P, players, k * sizeof(Player));
				start = clock(); merge_sort_optimized(mergeOpt50P, k, 50, compare_id); end = clock();
				tMerge50 += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tMerge50 /= NUM_TRIALS;
			printf(PURPLE "║" YELLOW "\tMerge Sort Opt(50):    " WHITE " %f" PURPLE "         ║\n", tMerge50);
		}

        // --- Tiempos Quick Sort (Last) ---
		double tQuickLast = 0;
		if (current_active_flags & FLAG_QUICK_LAST) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(quickLastP, players, k * sizeof(Player));
				start = clock(); quick_sort(quickLastP, k, 1, compare_id); end = clock();
				tQuickLast += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tQuickLast /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_GREEN "\tQuick Sort (Last):     " WHITE " %f" PURPLE "         ║\n", tQuickLast);
		}

        // --- Tiempos Quick Sort (Random) ---
		double tQuickRand = 0;
		if (current_active_flags & FLAG_QUICK_RANDOM) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(quickRandP, players, k * sizeof(Player));
				start = clock(); quick_sort(quickRandP, k, 3, compare_id); end = clock();
				tQuickRand += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tQuickRand /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_GREEN "\tQuick Sort (Random):   " WHITE " %f" PURPLE "         ║\n", tQuickRand);
		}

        // --- Tiempos Quick Sort (Median) ---
		double tQuickMed = 0;
		if (current_active_flags & FLAG_QUICK_MEDIAN) {
			for (int i = 0; i < NUM_TRIALS; i++) {
				memcpy(quickMedianP, players, k * sizeof(Player));
				start = clock(); quick_sort(quickMedianP, k, 4, compare_id); end = clock();
				tQuickMed += (double)(end - start) / CLOCKS_PER_SEC;
			}
			tQuickMed /= NUM_TRIALS;
			printf(PURPLE "║" LIGHT_GREEN "\tQuick Sort (Median):   " WHITE " %f" PURPLE "         ║\n", tQuickMed);
		}


		// Guardar en CSV
		fprintf(csv,
				"%d,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
				k, tSwap, tIns, tSel, tCock, tMergeClas, tMerge10, tMerge50, tQuickLast, tQuickRand, tQuickMed
			);        
		printf(PURPLE "╠══════════════════════════════════════════════════════╣\n");
	}
	// end of table
	printf(PURPLE "║" LIGHT_GREEN "                  CSV Data written                    " PURPLE "║\n");
	printf(PURPLE "╚══════════════════════════════════════════════════════╝\n" RESET);
	fclose(csv);

	printf("\n" BG_GREEN "Data saved in %s" RESET "\n", out_filename);

	free(players);
	free(swapSortP); free(insertionSortP); free(selectionSortP); free(cocktailP);
	free(mergeClassicP); free(mergeOpt10P); free(mergeOpt50P);
	free(quickLastP); free(quickRandP); free(quickMedianP);
}

void run_threshold_experiment()
{
    int n = 0;
    Player* players;
    if ((players = load_players("build/db/players.csv", &n)) == NULL) {
        return;
    }
    printf("Arreglo de jugadores cargado\n");

    const int num_points = NUM_STEPS;

    // Los 6 umbrales a comparar
    const int thresholds[] = {2, 8, 16, 32, 64, 128};
    const int num_thresholds = 6;

    Player* mergeP[num_thresholds];
    for (int t = 0; t < num_thresholds; t++) {
        mergeP[t] = malloc(n * sizeof(Player));
        if (!mergeP[t]) {
            print_error(102, "players", NULL);
            // Liberar los que sí se allocaron antes de salir
            for (int j = 0; j < t; j++) free(mergeP[j]);
            free(players);
            return;
        }
    }

    FILE *csv = fopen("build/db/threshold_experiment.csv", "w");
    if (csv == NULL) {
        print_error(101, "build/db/threshold_experiment.csv", NULL);
        return;
    }

    fprintf(csv, "N,Merge Sort T(2),Merge Sort T(8),Merge Sort T(16),Merge Sort T(32),Merge Sort T(64),Merge Sort T(128)\n");

    printf(PURPLE "╔══════════════════════════════════════════════════════╗\n");

    for (int s = 0; s < num_points; s++) {
        int k = (num_points == 1) ? n : 1 + (s * (n - 1)) / (num_points - 1);

        printf(PURPLE "║" MAGENTA " Procesando n =" WHITE " %8d" PURPLE "                             ║\n", k);
        printf(PURPLE "║" MAGENTA " Paso:" WHITE " %4d/%4d" PURPLE "                                     ║\n", s+1, num_points);

        fprintf(csv, "%d", k);

        for (int t = 0; t < num_thresholds; t++) {
            clock_t start, end;
            double tMerge = 0;

            for (int i = 0; i < NUM_TRIALS; i++) {
                memcpy(mergeP[t], players, k * sizeof(Player));
                start = clock();
                merge_sort_optimized(mergeP[t], k, thresholds[t], compare_id);
                end = clock();
                tMerge += (double)(end - start) / CLOCKS_PER_SEC;
            }
            tMerge /= NUM_TRIALS;

            printf(PURPLE "║" YELLOW "\tMerge Sort T(%3d):     " WHITE " %f" PURPLE "         ║\n",
                   thresholds[t], tMerge);

            fprintf(csv, ",%f", tMerge);
        }

        fprintf(csv, "\n");
        printf(PURPLE "╠══════════════════════════════════════════════════════╣\n");
    }

    printf(PURPLE "║" LIGHT_GREEN "                  CSV Data written                    " PURPLE "║\n");
    printf(PURPLE "╚══════════════════════════════════════════════════════╝\n" RESET);
    fclose(csv);

    printf("\n" BG_GREEN "Data saved in build/db/threshold_experiment.csv" RESET "\n");

    free(players);
    for (int t = 0; t < num_thresholds; t++) free(mergeP[t]);
}

void run_search_experiment(const char* target_file, const char* out_filename, int is_worst_case)
{
	int n = 0; 
	Player* players;
	if ((players = load_players((char*)target_file, &n)) == NULL) {
		return;
	}
	printf("Arreglo de jugadores cargado desde %s para busqueda\n", target_file);

	const int num_points = NUM_STEPS;
	FILE *csv = fopen(out_filename, "w");
	if (csv == NULL) return;
	
	fprintf(csv, "N,Binaria Recursiva,Binaria Rango,Exponencial,Interpolacion\n");
	
	for (int s = 0; s < num_points; s++) {
		int k = (num_points == 1) ? n : 1 + (s * (n - 1)) / (num_points - 1);
		clock_t start, end;
        double tBinRec = 0, tBinRan = 0, tExp = 0, tInt = 0;
        
        Player target;
        if (is_worst_case) {
            target = players[k - 1]; // Buscar elemento al final fuerza busquedas a lo profundo
        }

		for (int i = 0; i < NUM_TRIALS * 10; i++) {
            if (!is_worst_case) {
                target = players[rand() % k];
            }
            
            // Binaria recursiva
			start = clock(); binary_search_recursive(players, 0, k - 1, &target); end = clock();
			tBinRec += (double)(end - start) / CLOCKS_PER_SEC;
            
            // Binaria rango
            int first, last;
			start = clock(); binary_search_range(players, k, &target, &first, &last); end = clock();
			tBinRan += (double)(end - start) / CLOCKS_PER_SEC;

            // Exponencial
			start = clock(); exponential_search(players, k, &target); end = clock();
			tExp += (double)(end - start) / CLOCKS_PER_SEC;

            // Interpolacion
			start = clock(); interpolation_search(players, k, &target); end = clock();
			tInt += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tBinRec /= (NUM_TRIALS * 10);
		tBinRan /= (NUM_TRIALS * 10);
		tExp /= (NUM_TRIALS * 10);
		tInt /= (NUM_TRIALS * 10);
        
		fprintf(csv, "%d,%f,%f,%f,%f\n", k, tBinRec, tBinRan, tExp, tInt);
	}
	fclose(csv);
	free(players);
	printf("Search experiment saved in %s\n", out_filename);
}

void run_select_experiment(const char* target_file, const char* out_filename, int is_worst_case)
{
	int n = 0; 
	Player* players;
	if ((players = load_players((char*)target_file, &n)) == NULL) return;
	
	const int num_points = NUM_STEPS;
	FILE *csv = fopen(out_filename, "w");
	if (csv == NULL) return;
	
	fprintf(csv, "N,Quick Select\n");
	
	Player* arr = malloc(n * sizeof(Player));
	
	for (int s = 0; s < num_points; s++) {
		int k = (num_points == 1) ? n : 1 + (s * (n - 1)) / (num_points - 1);
		double tSel = 0;
        
        int k_target = is_worst_case ? k - 1 : k / 2; // k_target

		for (int i = 0; i < NUM_TRIALS; i++) {
		    memcpy(arr, players, k * sizeof(Player));
            int pivot_t = is_worst_case ? 1 : 3; // 1 = Last, 3 = Random
			clock_t start = clock(); 
            quick_select(arr, k, k_target, pivot_t, compare_id); 
            clock_t end = clock();
			tSel += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tSel /= NUM_TRIALS;
		fprintf(csv, "%d,%f\n", k, tSel);
	}
	fclose(csv);
	free(players);
	free(arr);
	printf("Select experiment saved in %s\n", out_filename);
}
