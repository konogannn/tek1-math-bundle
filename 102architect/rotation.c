/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** rotation
*/

#include "include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void rotation(matrice_t *matrice, char *d)
{
    printf("Rotation by a %s degree angle\n", d);
    fflush(stdout);
    double c = cos((atof(d) * M_PI) / 180);
    double s = sin((atof(d) * M_PI) / 180);
    double rot[] = {c, -s, 0, s, c, 0, 0, 0, 1};
    for (int i = 0; i < 9; i++)
        matrice->matrice[i] = rot[i];
    double temp = matrice->x;
    matrice->x = temp * rot[0] + matrice->y *rot[1];
    matrice->y = temp * rot[3] + matrice->y *rot[4];
}
