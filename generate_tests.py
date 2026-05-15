import os

with open("src/generate_exec_times.c", "a") as f:
    f.write("""

void run_search_experiment(const char* target_file, const char* out_filename, int is_worst_case)
{
	int n = 0; 
	Player* players;
	if ((players = load_players((char*)target_file, &n)) == NULL) {
		return;
	}
	printf("Arreglo de jugadores cargado desde %s para busqueda\\n", target_file);

	const int num_points = NUM_STEPS;
	FILE *csv = fopen(out_filename, "w");
	if (csv == NULL) return;
	
	fprintf(csv, "N,Binaria Recursiva,Binaria Rango,Exponencial,Interpolacion\\n");
	
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
        
		fprintf(csv, "%d,%f,%f,%f,%f\\n", k, tBinRec, tBinRan, tExp, tInt);
	}
	fclose(csv);
	free(players);
	printf("Search experiment saved in %s\\n", out_filename);
}

void run_select_experiment(const char* target_file, const char* out_filename, int is_worst_case)
{
	int n = 0; 
	Player* players;
	if ((players = load_players((char*)target_file, &n)) == NULL) return;
	
	const int num_points = NUM_STEPS;
	FILE *csv = fopen(out_filename, "w");
	if (csv == NULL) return;
	
	fprintf(csv, "N,Quick Select\\n");
	
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
		fprintf(csv, "%d,%f\\n", k, tSel);
	}
	fclose(csv);
	free(players);
	free(arr);
	printf("Select experiment saved in %s\\n", out_filename);
}
""")

