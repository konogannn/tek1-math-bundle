/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** scaling
*/

#include "include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void scaling(matrice_t *matrice, char *m, char*n)
{
    printf("Scaling by factors %g and %g\n", atof(m), atof(n));
    fflush(stdout);
    matrice->matrice[0] *= atof(m);
    matrice->matrice[1] *= atof(m);
    matrice->matrice[2] *= atof(m);
    matrice->matrice[3] *= atof(n);
    matrice->matrice[4] *= atof(n);
    matrice->matrice[5] *= atof(n);
    matrice->x *= atof(m);
    matrice->y *= atof(n);
}
