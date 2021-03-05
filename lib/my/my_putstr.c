/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** my_putstr
*/
#include "my.h"

void my_putstr(char *str)
{
    int lenth = my_strlen(str);

    write (1, str, lenth);
}