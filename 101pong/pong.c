/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** pong
*/

#include "include/struct.h"

int help(void)
{
    printf("USAGE\n    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    printf("DESCRIPTION\n");
    printf("    x0  ball abscissa at time t - 1\n");
    printf("    y0  ball ordinate at time t - 1\n");
    printf("    z0  ball altitude at time t - 1\n");
    printf("    x1  ball abscissa at time t\n");
    printf("    y1  ball ordinate at time t\n");
    printf("    z1  ball altitude at time t\n");
    printf("    n   time shift (greater than or equal to zero, integer)\n");
    return 0;
}

structure_t arguments_reader(char **av)
{
    structure_t structure;

    structure.x0 = atof(av[1]);
    structure.y0 = atof(av[2]);
    structure.z0 = atof(av[3]);
    structure.x1 = atof(av[4]);
    structure.y1 = atof(av[5]);
    structure.z1 = atof(av[6]);
    structure.n = atoi(av[7]);
    structure.pi = M_PI;
    return(structure);
}

int calculus(structure_t *structure)
{
    double vx = structure->x1 - structure->x0;
    double vy = structure->y1 - structure->y0;
    double vz = structure->z1 - structure->z0;
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", vx, vy, vz);
    printf("At time t + %i, ball coordinates will be:\n", structure->n);
    double xf = structure->x0 + (vx * (structure->n + 1));
    double yf = structure->y0 + (vy * (structure->n + 1));
    double zf = structure->z0 + (vz * (structure->n + 1));
    printf("(%.2f, %.2f, %.2f)\n", xf, yf, zf);
    double alpha = (acos(vz / sqrt((vx * vx) + (vy * vy) + (vz * vz))) / structure->pi) * 180 - 90;
    if (!alpha) {
        printf("The incidence angle is:\n%f degrees", 0.00);
        return 0;
    }
    if (alpha > 0 && alpha < 90 && structure->z1 / vz < 0)
        printf("The incidence angle is:\n%.2f degrees\n", alpha);
    else
        printf("The ball won't reach the paddle.\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 2) {
        write(2, "Invalid input\n", 14);
        return 84;
    }
    if (!strcmp(av[1], "-h"))
        return help();
    if (ac == 8) {
        structure_t structure = arguments_reader(av);

        if ((structure.n <= 0) ) {
            write(2, "Incorrect time shift\n", 21);
            return 84;
        }
        for (int j = 1; j < 7; j++) {
            for (int i = 0; av[j][i]; i++) {
                if (!isdigit(av[j][i]) || (av[j][i] != 45) || (av[j][i] != 46)) {
                    write(2, "Invalid coordinate\n", 19);
                    return 84;
                }
            }
        }
        return calculus(&structure);
    } else {
        write(2, "Invalid input\n", 14);
        return 84;
    }
}
