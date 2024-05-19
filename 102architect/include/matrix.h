/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** matrice
*/

#pragma once
#define _USE_MATH_DEFINES
#include <stdbool.h>
typedef struct matrice_s {
    double x;
    double y;
    double z;
    double *matrice;
} matrice_t;
void multiply_mat(matrice_t *matrice, double *oper);
bool my_str_isnum(char const *str);
int print_result(matrice_t *matrice, char *c1, char *c2);
void reflection(matrice_t *matrice, char *d);
void rotation(matrice_t *matrice, char *d);
void scaling(matrice_t *matrice, char *m, char*n);
void struct_set(matrice_t *matrice, char **av);
void translation(matrice_t *matrice, char *i, char *j);
int my_putstr(char const *str);
