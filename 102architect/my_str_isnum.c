/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** my_str_isnum
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '+' || str[0] == '-')
        i++;
    for (; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return true;
    return false;
}