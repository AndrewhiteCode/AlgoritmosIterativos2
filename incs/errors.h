/**
 * @file errors.h
 * @author Andres Barbosa, Milton Hernández, Iván Gallardo
 * @brief Funciones para manejo de errores (errors.c)
 */
#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utilities.h"

void print_error(int num, char *target, char *obs);

#endif