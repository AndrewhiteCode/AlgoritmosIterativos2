/**
 * @file main.c
 * @author Andres Barbosa, Milton Hernández, Iván Gallardo
 * @brief Punto de inicio del programa
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

/**
 * @brief Funcion principal del programa
 *
 * @return 0 si todo va bien, 1 si hay errores
 */
int main()
{
    // Apertura de un archivo inexistente para mostrar el error
    FILE *fp = fopen("inexistente.txt", "r");
    if (fp == NULL)
    {
        print_error(100, "inexistente.txt", NULL);
        return 1;
    }

    return 0;
}