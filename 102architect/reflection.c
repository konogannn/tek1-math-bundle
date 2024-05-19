/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** reflection
*/

#include "include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void reflection(matrice_t *matrice, char *d)
{
    printf("Reflection over an axis with an inclination angle of %s degrees\n", d);
    fflush(stdout);
    double c = cos(2 * ((atof(d) * M_PI) / 180));
    double s = sin(2 * ((atof(d) * M_PI) / 180));
    double ref[] = {c, s, 0, s, -c, 0, 0, 0, 1};
    for (int i = 0; i < 9; i++)
        matrice->matrice[i] = ref[i];
    double temp = matrice->x;
    matrice->x = temp * ref[0] + matrice->y *ref[1];
    matrice->y = temp * ref[3] + matrice->y *ref[4];
}
