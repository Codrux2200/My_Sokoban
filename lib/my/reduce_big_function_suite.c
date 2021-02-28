/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-saad.berrada
** File description:
** reduce_big_function_suite
*/

#include "my.h"

int s_plus_function(char *line, int s)
{
    line[s] = ' ';
    s++;
    return s;
}

void free_assemble(char *map, char *line)
{
    free(line);
}

void p_soko_gestion(sokoban *soko_p, int s, int l)
{
    soko_p[0].pos[0] = s;
    soko_p[0].pos[1] = l;
}

char *map_save(char *map, int conv)
{
    static char *map_save = NULL;

    if (conv == 0){
        map_save = map;
        return " ";
    } else
        return map_save;
}

void defeat(char **map_tab)
{
    endwin();
    free(map_tab);
    my_putstr("you loose ;(\n");
    exit(1);
}