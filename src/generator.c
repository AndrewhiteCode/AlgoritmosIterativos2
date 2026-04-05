/**
 * @file generator.c
 * @author Andres Barbosa, Milton Hernández, Ivan Gallardo
 * @brief Funciones de generacion de datos y archivo csv
 */

#include "generator.h"

static char *teams[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Theta", "Lambda", "Pi", "Tau"};

/**
 * @brief Genera una letra aleatoria (Minus y mayus).
 * @return char 
 */
static char random_letter()
{
	char c = 'A' + (rand() % 26);

	if (rand() % 2 == 0)
		c = c + 32;

	return c;
}


/**
 * @brief Genera un jugador con campos ID, nombre, equipo, puntaje y cantidad de competencias.
 * 
 * @param id valor unico de identificacion
 * @param player puntero a la estructura Player donde se almacenarán los datos generados
 */
static void generate_player(int id, Player *player) 
{
	int length = MIN_NAME_LENGTH + (rand() % (MAX_NAME_LENGTH-MIN_NAME_LENGTH));

	player->id = id;

	for (int j = 0; j < length; j++) {
		player->name[j] = random_letter();
	}
	player->name[length] = '\0';

	player->team = teams[rand() % 9];
	player->score = (rand() % 100 + 1) / 10.0f;
	player->competitions = rand() % 251;

	// Aqui no hay nada que ver agente...
	player->potatoe = rand() % 2 ? true : false;
	// Usted no vio nada aquí agente...
}

/**
 * @brief Funcion general de generacion de csv con datos aleatorios 
 * 
 * @param n cantidad de jugadores a generar
 * 
 * @return int 0 si todo va bien, otro codigo de error en caso de error
 */
int generate_csv(int n) 
{
	Player player;
	FILE *csv = fopen("build/db/players.csv", "w");

	if (csv == NULL) {
		print_error(101, "build/db/players.csv", NULL);
		return 101;
	}

	fprintf(csv, "ID,NAME,TEAM,SCORE,COMPETITIONS,POTATOE\n");

	printf(
		DARK_GRAY "|" RESET " "
		LIGHT_GRAY "%4s" RESET " "
		DARK_GRAY "|" RESET " "
		DARK_YELLOW "%10s" RESET " "
		DARK_GRAY "|" RESET " "
		DARK_BLUE "%7s" RESET " "
		DARK_GRAY "|" RESET " "
		DARK_GREEN "%4s" RESET " "
		DARK_GRAY "|" RESET " "
		PURPLE "%3s" RESET " "
		DARK_GRAY "|" RESET "\n",
		"ID", "NAME", "TEAM", "SCORE", "COMPS"
	);

	for (int i = 0; i < n; i++) {
		generate_player(i + 1, &player);
		fprintf(csv, "%d,%s,%s,%.1f,%d,%s\n", player.id, player.name, player.team, player.score, player.competitions, player.potatoe ? "true" : "false");

		printf(
			DARK_GRAY "|" RESET " "
			WHITE "%4d" RESET " "
			DARK_GRAY "|" RESET " "
			YELLOW "%10s" RESET " "
			DARK_GRAY "|" RESET " "
			LIGHT_BLUE "%7s" RESET " "
			DARK_GRAY "|" RESET " "
			LIGHT_GREEN "%5.1f" RESET " "
			DARK_GRAY "|" RESET " "
			MAGENTA "%5d" RESET " "
			DARK_GRAY "|" RESET "\n",
			player.id, player.name, player.team, player.score, player.competitions
		);

		}

	fclose(csv);
	printf(BG_GREEN"\nData generated and saved to players.csv"RESET"\n");
}

// Se rie en latex: 𝑗𝑎𝑗𝑎𝑗𝑎𝑗𝑎