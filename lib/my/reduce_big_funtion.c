/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** reduce_big_funtion
*/
#include "my.h"

int mini_function_o(int o, sokoban *soko_o, int s, int l)
{
    soko_o[o].pos[0] = s;
    soko_o[o].pos[1] = l;
    o++;
    return o;
}

int mini_function_x(int x, sokoban *soko_x, int s, int l)
{
    soko_x[x].pos[0] = s;
    soko_x[x].pos[1] = l;
    x++;
    return x;
}

int mini_function_s(char *map, char *line, int s, int i)
{
    line[s] = map[i];
    s++;
    return s;
}

int l_gestion(int l, int s, char *line, char **map_tab)
{
    line[s] = '\0';
    map_tab[l] = line;
    l++;
    l_save(l, 1);
    return l;
}

void small_reduce_soko(sokoban *soko_o, sokoban *soko_x, int x, int o)
{
    soko_o[0].pos[2] = o;
    soko_x[0].pos[2] = x;
}