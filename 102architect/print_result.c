/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** print_result
*/

#include "include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int print_result(matrice_t *matrice, char *c1, char *c2)
{
    for (int i = 0; matrice->matrice[i] < 9; i++)
        if (matrice->matrice[i] > -0.001 && matrice->matrice[i] < 0.001)
            matrice->matrice[i] = 0.00;
    printf("%.2f\t%.2f\t%.2f\n", matrice->matrice[0], matrice->matrice[1], matrice->matrice[2]);
    printf("%.2f\t%.2f\t%.2f\n", matrice->matrice[3], matrice->matrice[4], matrice->matrice[5]);
    printf("%.2f\t%.2f\t%.2f\n", matrice->matrice[6], matrice->matrice[7], matrice->matrice[8]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(c1), atof(c2), matrice->x, matrice->y);
    return EXIT_SUCCESS;
}
