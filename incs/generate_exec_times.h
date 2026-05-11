/**
 * @file generate_exec_times.h
 * @author Andres Barbosa, Milton Hernandez, Ivan Gallardo
 * @brief Funciones para la ejecusion de tests (generate_exec_times.c)
 */
#ifndef EXEC_H
#define EXEC_H
#define NUM_TRIALS 100
#define NUM_STEPS 20
#include <stdio.h>
#include <time.h>

#include "errors.h"
#include "player.h"
#include "sorting.h"
#include "searching.h"
#include "generator.h"

typedef struct ExecResults {
    int n;
    // Tarea 1: Cuadráticos O(n^2)
    double timeSwapSort;
    double timeInsertionSort;
    double timeSelectionSort;
    double timeCocktailSort;
    // Tarea 2: Divide y Vencerás O(n log n)
    double timeMergeClassic;
    double timeMergeOpt10;
    double timeMergeOpt50;
    double timeQuickLast;
    double timeQuickRandom;
    double timeQuickMedian;
} ExecResults;


void run_experiment(void);

#endif