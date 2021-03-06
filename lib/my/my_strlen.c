/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

void function_error(char *map, int p, int x, int o)
{
    int size = my_strlen(map);

    for (int i = size - 2; map[i] != '\n'; i--){
        if (map[i] == 'X'){
            my_putstr_err("error map\n");
            exit(84);
        }
    }
    if (error_gestion_map(p, x, o) == 84) exit(84);
    map_save(map, 0);
}