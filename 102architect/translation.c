/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** translation
*/

#include "include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void translation(matrice_t *matrice, char *i, char *j)
{
    printf("Translation along vector (%g, %g)\n", atof(i), atof(j));
    fflush(stdout);
    matrice->matrice[2] += atof(i);
    matrice->matrice[5] += atof(j);
    matrice->x += atof(i);
    matrice->y += atof(j);
}
