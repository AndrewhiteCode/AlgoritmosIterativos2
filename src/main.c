/**
 * @file main.c
 * @author Andres Barbosa, Milton Hernandez, Ivan Gallardo
 * @brief Funciones principales del programa
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generator.h"
#include "sorting.h"
#include "searching.h"
#include "utilities.h"
#include "player.h" 
#include "generate_exec_times.h"

int main() {
	// Variables de control
	int option = 0;
	int generationType = 0;
	int check = 1;

	Player* players = NULL;
	int n; // Numero de jugadores

	// Variables para ordenamiento (Opcion 2)
	int sortOption;
	int sortCriteria;

	// Variables para busqueda (Opcion 3)
	int searchOption;
	int searchId;
	int result;

	srand(time(0));

	printf(RESET "          ╔═══════════╗\n");
	printf( "          ║ MAIN MENU ║\n");
	printf("╔═════════╩═══════════╩══════════╗\n");
	printf("║ "DARK_YELLOW "1)" YELLOW " Generate new CSV" RESET "            ║\n");
	printf("║ "BROWN "2)" ORANGE " Read actual CSV" RESET "             ║\n");
	printf("║ "DARK_BLUE "3)" LIGHT_BLUE " Sort CSV" RESET "                    ║\n");
	printf("║ "DARK_GREEN "4)" LIGHT_GREEN " Search value in CSV" RESET "         ║\n");
	printf("║ "PURPLE "5)" MAGENTA " Run experiment" RESET "              ║\n");
	printf("║ "DARK_RED "6)" LIGHT_RED " Exit" RESET "                        ║\n");
	printf("╚════════════════════════════════╝\n");
	printf(DARK_GRAY"Choose an option: " RESET);
	
	check =	scanf("%d", &option);
	while (check != 1 || option < 1 || option > 6) {
		printf(DARK_GRAY"Invalid option, try again: " RESET);
		while (getchar() != '\n');
		check = scanf("%d", &option);
	}

	//getchar(); // Parche de paginador

	if (option == 1) { // Opcion 1: Generar CSV
		printf(DARK_YELLOW "\nType the number of players to generate: " YELLOW);
		check = scanf("%d", &n);
		while (check != 1 || n < 0) {
			printf(BROWN "Invalid number, try again: " DARK_YELLOW);
			while (getchar() != '\n');
			check = scanf("%d", &n);
		}

		printf(BROWN "   ╔════════════════════════╗\n");
		printf(BROWN "   ║" YELLOW "  Choose the case type  " BROWN "║" "\n");
		printf(BROWN "╔══╩════════════════════════╩══╗\n");
		printf(BROWN "║" DARK_YELLOW " 1)" YELLOW " Sorted Array" BROWN "              ║\n");
		printf(BROWN "║" DARK_YELLOW " 2)" YELLOW " Inverse Array" BROWN "             ║\n");
		printf(BROWN "║" DARK_YELLOW " 3)" YELLOW " Shuffled Array" BROWN "            ║\n");
		printf(BROWN"╚══════════════════════════════╝\n");

		printf(DARK_YELLOW"Option: " YELLOW);
		check = scanf("%d", &generationType);
		while (check != 1 || n < 0) {
			printf(BROWN "Invalid option, try again: " DARK_YELLOW);
			while (getchar() != '\n');
			check = scanf("%d", &generationType);
		}

		if (generationType == 1) {
			printf(YELLOW "\nGenerating SORTED array...\n");
		} else if (generationType == 2) {
			printf(YELLOW "\nGenerating INVERSE array...\n");
		} else {
			printf(YELLOW "\nGenerating SHUFFLED array...\n");
		}

		generate_csv(n, generationType);
	}

	else if (option == 2) { // Opcion 2: Leer CSV
		// Cargamos el arreglo de jugadores
		if ((players = load_players("build/db/players.csv", &n)) == NULL) {
			print_error(101, "build/db/players.csv", NULL);
			return 1;
		}

		printf(ORANGE "\nplayers.csv:\n" RESET);
		print_player_array_more(players, n);
	}

	else if (option == 3) { // Opcion 3: Ordenar arreglo
        // Cargamos el arreglo de jugadores
        if ((players = load_players("build/db/players.csv", &n)) == NULL) {
            return 1;
        }

        printf(LIGHT_BLUE "\nOriginal file:\n" RESET);
        print_player_array_more(players, n);

        
        printf(EVEN_DARKER_BLUE"    ╔════════════════════════════╗\n");
        printf(EVEN_DARKER_BLUE"    ║" LIGHT_BLUE " Choose a sorting algorithm " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "╔═══╩════════════════════════════╩═══╗\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 1)" LIGHT_BLUE " Swap Sort                       " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 2)" LIGHT_BLUE " Insertion Sort                  " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 3)" LIGHT_BLUE " Selection Sort                  " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 4)" LIGHT_BLUE " Cocktail Shaker Sort            " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 5)" LIGHT_BLUE " Merge Sort (Classic)            " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 6)" LIGHT_BLUE " Merge Sort (Optimized)          " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 7)" LIGHT_BLUE " Quick Sort (Last Pivot)         " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 8)" LIGHT_BLUE " Quick Sort (First Pivot)        " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 9)" LIGHT_BLUE " Quick Sort (Random Pivot)       " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 10)" LIGHT_BLUE" Quick Sort (Median of 3)       " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "╚════════════════════════════════════╝\n");
        printf(DARK_BLUE "Option: " LIGHT_BLUE);
        
        check = scanf("%d", &sortOption);
        while (check != 1 || sortOption < 1 || sortOption > 10) {
            printf(EVEN_DARKER_BLUE"Invalid option, try again: " DARK_BLUE);
            while (getchar() != '\n');
            check = scanf("%d", &sortOption);
        }

        // Si elige Merge Sort Optimizado, le pedimos el umbral para el Insertion Sort
        int threshold = 10; // Valor por defecto
        if (sortOption == 6) {
            printf(DARK_BLUE "\nType the threshold for Insertion Sort (e.g. 10): " LIGHT_BLUE);
            check = scanf("%d", &threshold);
            while (check != 1 || threshold < 1) {
                printf(EVEN_DARKER_BLUE"Invalid threshold, try again: " DARK_BLUE);
                while (getchar() != '\n');
                check = scanf("%d", &threshold);
            }
        }

        // Elegir el campo a ordenar
        
        printf(EVEN_DARKER_BLUE"   ╔══════════════════════╗\n");
        printf(EVEN_DARKER_BLUE"   ║" LIGHT_BLUE " Choose field to sort " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE"   ║" LIGHT_BLUE "    by (Ascending)    " EVEN_DARKER_BLUE "║\n");
        printf(EVEN_DARKER_BLUE "╔══╩══════════════════════╩══╗\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 1)" LIGHT_BLUE " ID                      " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 2)" LIGHT_BLUE " Name                    " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 3)" LIGHT_BLUE " Team                    " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 4)" LIGHT_BLUE " Score                   " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "║" DARK_BLUE " 5)" LIGHT_BLUE " Competitions            " EVEN_DARKER_BLUE "║" "\n");
        printf(EVEN_DARKER_BLUE "╚════════════════════════════╝\n");

        printf(DARK_BLUE "Option: " LIGHT_BLUE);

        check = scanf("%d", &sortCriteria);
        while (check != 1 || sortCriteria < 1 || sortCriteria > 5) {
            printf(EVEN_DARKER_BLUE"Invalid option, try again: " DARK_BLUE);
            while (getchar() != '\n');
            check = scanf("%d", &sortCriteria);
        }

        // Asignar el comparador segun la eleccion del usuario
        int (*comp_ptr)(Player*, Player*) = NULL;
        if (sortCriteria == 1) comp_ptr = compare_id;
        else if (sortCriteria == 2) comp_ptr = compare_name;
        else if (sortCriteria == 3) comp_ptr = compare_team;
        else if (sortCriteria == 4) comp_ptr = compare_score;
        else if (sortCriteria == 5) comp_ptr = compare_competitions;
        else {
            printf(RESET BG_RED "Invalid criteria option.\n" RESET);
        }

        // Ejecutar el ordenamiento
        if (sortOption == 1) {
            swap_sort(players, n, comp_ptr);
        } else if (sortOption == 2) {
            insertion_sort(players, n, comp_ptr);
        } else if (sortOption == 3) {
            selection_sort(players, n, comp_ptr);
        } else if (sortOption == 4) {
            cocktail_shaker_sort(players, n, comp_ptr);
        } else if (sortOption == 5) {
            merge_sort_classic(players, n, comp_ptr);
        } else if (sortOption == 6) {
            merge_sort_optimized(players, n, threshold, comp_ptr);
        } else if (sortOption >= 7 && sortOption <= 10) {
            // Transformamos la opcion del menu (7-10) al tipo de pivote (1-4)
            int pivot_type = sortOption - 6; 
            quick_sort(players, n, pivot_type, comp_ptr);
        } else {
            printf(RESET BG_RED "Invalid sorting option.\n" RESET);
        }

        printf(LIGHT_BLUE "\nSorted file (Ascending):\n" RESET);
        print_player_array_more(players, n);
        free(players);
    }

	else if (option == 4) { // Opcion 4: Buscar valor
		// Cargamos el arreglo de jugadores
		if ((players = load_players("build/db/players.csv", &n)) == NULL) {
			return 1;
		}
	
		printf(LIGHT_GREEN"\nCurrent file:" RESET "\n");
		print_player_array_more(players, n);

		printf(EVEN_DARKER_GREEN "   ╔═════════════════════════════════════╗\n");
		printf(EVEN_DARKER_GREEN "   ║" LIGHT_GREEN "      Choose a searching algorithm   " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "   ║" LIGHT_GREEN "            (Only by ID)             " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "╔══╩═════════════════════════════════════╩══╗\n");
		printf(EVEN_DARKER_GREEN "║" DARK_GREEN " 1)" LIGHT_GREEN " Linear Search                       " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "║" DARK_GREEN " 2)" LIGHT_GREEN " Binary Search (Iterative)           " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "║" DARK_GREEN " 3)" LIGHT_GREEN " Binary Search (Recursive)           " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "║" DARK_GREEN " 4)" LIGHT_GREEN " Binary Search (Ranges)              " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "║" DARK_GREEN " 5)" LIGHT_GREEN " Exponential Search                  " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "║" DARK_GREEN " 6)" LIGHT_GREEN " Interpolation Search                " EVEN_DARKER_GREEN "║" "\n");
		printf(EVEN_DARKER_GREEN "╚═══════════════════════════════════════════╝\n");

		printf(DARK_GREEN"Option: " LIGHT_GREEN);
		check = scanf("%d", &searchOption);
		// Actualizamos la validación para que acepte hasta la opción 6
		while (check != 1 || searchOption < 1 || searchOption > 6) {
			printf(EVEN_DARKER_GREEN "Invalid option, try again: " DARK_GREEN);
			while (getchar() != '\n');
			check = scanf("%d", &searchOption);
		}

		if (searchOption >= 1 && searchOption <= 6) {
			printf(DARK_GREEN "\nType the ID to search: " LIGHT_GREEN);
			check = scanf("%d", &searchId);
			while (check != 1) {
				printf(EVEN_DARKER_GREEN"Invalid ID, try again: " DARK_GREEN);
				while (getchar() != '\n');
				check = scanf("%d", &searchId);
			}
			
			Player target = {searchId, "", "", 0.0, 0, false};

			// Si NO es búsqueda lineal, ordenamos el arreglo antes de buscar
			if (searchOption >= 2) {
				quick_sort(players, n, 3, compare_id); // Cambiamos a Quick Sort con pivote aleatorio para ordenar por ID antes de la búsqueda binaria
				printf(LIGHT_GREEN "\nOrdered array (by ID) used for advanced search:" RESET "\n");
				print_player_array_more(players, n);
			}

			if (searchOption == 1) {
				result = linear_search(players, n, &target, compare_id);

				if (result == n) {
					printf(BG_RED "Player with ID %d was not found." RESET "\n\n", searchId);
				} else {
					printf(BG_GREEN "Player found at index %d via Linear Search:" RESET "\n\n", result+1);
					print_player(&players[result]);
				}
			} 
			else if (searchOption == 2) {
				result = binary_search(players, 0, n - 1, &target);

				if (result == -1) {
					printf(BG_RED "Player with ID %d was not found." RESET "\n\n", searchId);
				} else {
					printf(BG_GREEN "Player found at index %d via Iterative Binary Search:" RESET "\n\n", result+1);
					print_player(&players[result]);
				}
			}
			else if (searchOption == 3) {
				result = binary_search_recursive(players, 0, n - 1, &target);

				if (result == -1) {
					printf(BG_RED "Player with ID %d was not found." RESET "\n\n", searchId);
				} else {
					printf(BG_GREEN "Player found at index %d via Recursive Binary Search:" RESET "\n\n", result+1);
					print_player(&players[result]);
				}
			}
			else if (searchOption == 4) {
				int first = -1, last = -1;
				binary_search_range(players, n, &target, &first, &last);

				if (first == -1) {
					printf(BG_RED "Player with ID %d was not found." RESET "\n\n", searchId);
				} else {
					printf(BG_GREEN "Player(s) found from index %d to %d via Range Binary Search:" RESET "\n\n", first+1, last+1);
					// Imprimir todos los jugadores en el rango encontrado
					for (int i = first; i <= last; i++) {
						print_player(&players[i]);
					}
				}
			}
			else if (searchOption == 5) {
				result = exponential_search(players, n, &target);

				if (result == -1) {
					printf(BG_RED "Player with ID %d was not found." RESET "\n\n", searchId);
				} else {
					printf(BG_GREEN "Player found at index %d via Exponential Search:" RESET "\n\n", result+1);
					print_player(&players[result]);
				}
			}
			else if (searchOption == 6) {
				result = interpolation_search(players, n, &target);

				if (result == -1) {
					printf(BG_RED "Player with ID %d was not found." RESET "\n\n", searchId);
				} else {
					printf(BG_GREEN "Player found at index %d via Interpolation Search:" RESET "\n\n", result+1);
					print_player(&players[result]);
				}
			}
		}
		free(players);
	}

	else if (option == 5) { // Opcion 5: Ejecutar experimento
		run_experiment();
	}

	else if (option == 6) { // Opcion 6: Salir del programa

		// 1/2 de probablidad de salir crocodile o aligator
		if (rand() % 2 == 0) {
			printf(DARK_GREEN);
			printf("   _____                                   _                            _     _ _        \n");
			printf("  / ____|                                 (_)                          | |   (_) |       \n");
			printf(" | (___   ___  ___    _   _  ___  _   _    _ _ __      __ _   __      _| |__  _| | ___   \n");
			printf("  \\___ \\ / _ \\/ _ \\  | | | |/ _ \\| | | |  | | '_ \\    / _` |  \\ \\ /\\ / / '_ \\| | |/ _ \\  \n");
			printf("  ____) |  __/  __/  | |_| | (_) | |_| |  | | | | |  | (_| |   \\ V  V /| | | | | |  __/  \n");
			printf(" |_____/ \\___|\\___|   \\__, |\\___/_\\__,_|  |_|_| |_|   \\__,_|    \\_/\\_/ |_| |_|_|_|\\___|  \n");
			printf("                       __/ |  | (_) |    | |                                             \n");
			printf("   ___ _ __ ___   ___ |___/ __| |_| | ___| |                                             \n");
			printf("  / __| '__/ _ \\ / __/ _ \\ / _` | | |/ _ \\ |                                             \n");
			printf(" | (__| | | (_) | (_| (_) | (_| | | |  __/_|                                             \n");
			printf("  \\___|_|  \\___/ \\___\\___/ \\__,_|_|_|\\___(_)                                             \n");
			printf(RESET);
			return 0;
		}

		printf(DARK_RED);
		printf("   _____                                   _       _                     _ _             _             _ \n");
		printf("  / ____|                                 | |     | |                   | (_)           | |           | |\n");
		printf(" | (___   ___  ___    _   _  ___  _   _   | | __ _| |_ ___ _ __     __ _| |_  __ _  __ _| |_ ___  _ __| |\n");
		printf("  \\___ \\ / _ \\/ _ \\  | | | |/ _ \\| | | |  | |/ _` | __/ _ \\ '__|   / _` | | |/ _` |/ _` | __/ _ \\| '__| |\n");
		printf("  ____) |  __/  __/  | |_| | (_) | |_| |  | | (_| | ||  __/ |     | (_| | | | (_| | (_| | || (_) | |  |_|\n");
		printf(" |_____/ \\___|\\___|   \\__, |\\___/ \\__,_|  |_|\\__,_|\\__\\___|_|      \\__,_|_|_|\\__, |\\__,_|\\__\\___/|_|  (_)\n");
		printf("                       __/ |                                                  __/ |                      \n");
		printf("                      |___/                                                  |___/                       \n");
		printf(RESET);
	}

	return 0;
}

// MIAU !
                                                                                