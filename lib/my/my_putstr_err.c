/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** my_putstr_err
*/
#include "my.h"

void my_putstr_err(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}