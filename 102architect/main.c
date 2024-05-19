/*
** EPITECH PROJECT, 2023
** 102architect
** File description:
** main
*/

#include "include/matrix.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int help()
{
    printf("USAGE\n\t./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n\n");
    printf("DESCRIPTION\n");
    printf("\tx\tabscissa of the original point\n\ty\tordinate of the original point\n\n");
    printf("\ttransfo arg1 [arg2]\n\t-t i j\ttranslation along vector (i, j)\n\t-z m n\tscaling by factors m (x-axis) and n (y-axis)\n");
    printf("\t-r d\trotation centered in O by a d degree angle\n");
    printf("\t-s d\treflection over the axis passing through O with an inclination\nangle of d degrees\n");
    return 0;
}

void struct_set(matrice_t *matrice, char **av)
{
    matrice->x = atof(av[1]);
    matrice->y = atof(av[2]);
    matrice->z = 1;
    double mat[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    matrice->matrice = calloc(9, sizeof(double));
    for (int i = 0; i < 9; i++)
        matrice->matrice[i] = mat[i];
}

void multiply_mat(matrice_t *matrice, double *oper)
{
    double *temp = calloc(10, sizeof(double));

    for (int i = 0; matrice->matrice[i]; i++)
        temp[i] = matrice->matrice[i];
    matrice->matrice[0] = (temp[0] * oper[0]) + (temp[1] * oper[3]) + (temp[2] * oper[6]);
    matrice->matrice[1] = (temp[0] * oper[1]) + (temp[1] * oper[4]) + (temp[2] * oper[7]);
    matrice->matrice[2] = (temp[0] * oper[2]) + (temp[1] * oper[5]) + (temp[2] * oper[8]);
    matrice->matrice[3] = (temp[3] * oper[0]) + (temp[4] * oper[3]) + (temp[5] * oper[6]);
    matrice->matrice[4] = (temp[3] * oper[1]) + (temp[4] * oper[4]) + (temp[5] * oper[7]);
    matrice->matrice[5] = (temp[3] * oper[2]) + (temp[4] * oper[5]) + (temp[5] * oper[8]);
    matrice->matrice[6] = (temp[6] * oper[0]) + (temp[7] * oper[3]) + (temp[8] * oper[6]);
    matrice->matrice[7] = (temp[6] * oper[1]) + (temp[7] * oper[4]) + (temp[8] * oper[7]);
    matrice->matrice[8] = (temp[6] * oper[2]) + (temp[7] * oper[5]) + (temp[8] * oper[8]);
}

void is_error_1arg(char *a)
{
    if (!a) {
        write(2, "error: invalid argument.\n", 25);
        exit(84);
    }
    if (my_str_isnum(a)) {
        write(2, "error: invalid argument.\n", 25);
        exit(84);
    }
}

void is_error_2arg(char *a, char *b)
{
    if (!a || !b) {
        write(2, "error: invalid argument.\n", 25);
        exit(84);
    }
    if (my_str_isnum(a) || my_str_isnum(b)) {
        write(2, "error: invalid argument.\n", 25);
        exit(84);
    }
}

int main(int ac, char **av)
{
    matrice_t matrice;

    if (ac == 2 && strcmp(av[1],"-h") == 0)
        return help();
    if (ac < 5) {
        write(2, "error: not enough argument.\n", 28);
        exit(84);
    }
    struct_set(&matrice, av);

    int pos = 3;
    while (pos < ac) {
        if (!strcmp(av[pos],"-t")) {
            is_error_2arg(av[pos + 1], av[pos + 2]);
            translation(&matrice, av[pos + 1], av[pos + 2]);
            pos += 3;
        } else if (!strcmp(av[pos], "-z")) {
            is_error_2arg(av[pos + 1], av[pos + 2]);
            scaling(&matrice, av[pos + 1], av[pos + 2]);
            pos += 3;
        } else if (!strcmp(av[pos], "-r")) {
            is_error_1arg(av[pos + 1]);
            rotation(&matrice, av[pos + 1]);
            pos += 2;
        } else if (!strcmp(av[pos], "-s")) {
            is_error_1arg(av[pos + 1]);
            reflection(&matrice, av[pos + 1]);
            pos += 2;
        } else {
            write(2, "error: invalid argument.\n", 25);
            exit(84);
        }
    }
    print_result(&matrice, av[1], av[2]);
    free(matrice.matrice);
    return 0;
}
