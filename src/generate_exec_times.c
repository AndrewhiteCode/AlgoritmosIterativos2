/**
 * @file generate_exec_times.c
 * @author Andres Barbosa, Milton Hernandez, Ivan Gallardo
 * @brief Funciones para la ejecución de pruebas experimentales de algoritmos.
 */

#include <stdlib.h>
#include <string.h>
#include "generate_exec_times.h"
#include "utilities.h"

/**
 * @brief Ejecuta un experimento masivo comparando 10 algoritmos de ordenamiento
 * y los algoritmos de búsqueda, generando un reporte detallado en CSV.
 */
void run_experiment()
{
	int n = 0; 
	Player* players;
	if ((players = load_players("build/db/players.csv", &n)) == NULL) {
			return;
	}
	printf("Arreglo de jugadores cargado\n");
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
	FILE *csv = fopen("build/db/experiment.csv", "w");
	if (csv == NULL) {
		print_error(101, "build/db/experiment.csv", NULL);
		return;
	}

    // ¡La magia para que main.py funcione! Todos tienen "Sort" en el nombre.
	fprintf(csv, "N,Swap Sort,Insertion Sort,Selection Sort,Cocktail Shaker Sort,Merge Sort Classic,Merge Sort Opt(10),Merge Sort Opt(50),Quick Sort (Last),Quick Sort (Random),Quick Sort (Median)\n");

	// header
	printf(PURPLE "╔══════════════════════════════════════════════════════╗\n");

	for (int s = 0; s < num_points; s++) {
		int k = (num_points == 1) ? n : 1 + (s * (n - 1)) / (num_points - 1);

		printf(PURPLE "║" MAGENTA " Procesando n =" WHITE" %8d" PURPLE "                             ║\n", k);
		printf(PURPLE "║" MAGENTA " Paso:" WHITE" %4d/%4d" PURPLE "                                     ║\n", s+1, num_points);
		clock_t start, end;

		// --- Tiempos Swap Sort ---
		double tSwap = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(swapSortP, players, k * sizeof(Player));
			start = clock(); swap_sort(swapSortP, k, compare_id); end = clock();
			tSwap += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tSwap /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_BLUE "\tSwap Sort:             " WHITE " %f\t" PURPLE "       ║\n", tSwap);
 
		// --- Tiempos Insertion Sort ---
		double tIns = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(insertionSortP, players, k * sizeof(Player));
			start = clock(); insertion_sort(insertionSortP, k, compare_id); end = clock();
			tIns += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tIns /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_BLUE "\tInsertion Sort:        " WHITE " %f\t" PURPLE "       ║\n", tIns);
		
		// --- Tiempos Selection Sort ---
		double tSel = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(selectionSortP, players, k * sizeof(Player));
			start = clock(); selection_sort(selectionSortP, k, compare_id); end = clock();
			tSel += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tSel /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_BLUE "\tSelection Sort:        " WHITE " %f\t" PURPLE "       ║\n", tSel);

		// --- Tiempos Cocktail Shaker Sort ---
		double tCock = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(cocktailP, players, k * sizeof(Player));
			start = clock(); cocktail_shaker_sort(cocktailP, k, compare_id); end = clock();
			tCock += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tCock /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_BLUE "\tCocktail Shaker Sort:  " WHITE " %f" PURPLE "         ║\n", tCock);

        // --- Tiempos Merge Sort Classic ---
		double tMergeClas = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(mergeClassicP, players, k * sizeof(Player));
			start = clock(); merge_sort_classic(mergeClassicP, k, compare_id); end = clock();
			tMergeClas += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tMergeClas /= NUM_TRIALS;
		printf(PURPLE "║" YELLOW "\tMerge Sort Classic:    " WHITE " %f" PURPLE "         ║\n", tMergeClas);

        // --- Tiempos Merge Sort Opt(10) ---
		double tMerge10 = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(mergeOpt10P, players, k * sizeof(Player));
			start = clock(); merge_sort_optimized(mergeOpt10P, k, 10, compare_id); end = clock();
			tMerge10 += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tMerge10 /= NUM_TRIALS;
		printf(PURPLE "║" YELLOW "\tMerge Sort Opt(10):    " WHITE " %f" PURPLE "         ║\n", tMerge10);

        // --- Tiempos Merge Sort Opt(50) ---
		double tMerge50 = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(mergeOpt50P, players, k * sizeof(Player));
			start = clock(); merge_sort_optimized(mergeOpt50P, k, 50, compare_id); end = clock();
			tMerge50 += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tMerge50 /= NUM_TRIALS;
		printf(PURPLE "║" YELLOW "\tMerge Sort Opt(50):    " WHITE " %f" PURPLE "         ║\n", tMerge50);

        // --- Tiempos Quick Sort (Last) ---
		double tQuickLast = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(quickLastP, players, k * sizeof(Player));
			start = clock(); quick_sort(quickLastP, k, 1, compare_id); end = clock();
			tQuickLast += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tQuickLast /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_GREEN "\tQuick Sort (Last):     " WHITE " %f" PURPLE "         ║\n", tQuickLast);

        // --- Tiempos Quick Sort (Random) ---
		double tQuickRand = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(quickRandP, players, k * sizeof(Player));
			start = clock(); quick_sort(quickRandP, k, 3, compare_id); end = clock();
			tQuickRand += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tQuickRand /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_GREEN "\tQuick Sort (Random):   " WHITE " %f" PURPLE "         ║\n", tQuickRand);

        // --- Tiempos Quick Sort (Median) ---
		double tQuickMed = 0;
		for (int i = 0; i < NUM_TRIALS; i++) {
			memcpy(quickMedianP, players, k * sizeof(Player));
			start = clock(); quick_sort(quickMedianP, k, 4, compare_id); end = clock();
			tQuickMed += (double)(end - start) / CLOCKS_PER_SEC;
		}
		tQuickMed /= NUM_TRIALS;
		printf(PURPLE "║" LIGHT_GREEN "\tQuick Sort (Median):   " WHITE " %f" PURPLE "         ║\n", tQuickMed);


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

	printf("\n" BG_GREEN "Data saved in build/db/experiment.csv" RESET "\n");

	free(players);
	free(swapSortP); free(insertionSortP); free(selectionSortP); free(cocktailP);
	free(mergeClassicP); free(mergeOpt10P); free(mergeOpt50P);
	free(quickLastP); free(quickRandP); free(quickMedianP);
}