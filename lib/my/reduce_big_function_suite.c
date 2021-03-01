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

int defeat(char **map_tab, sokoban *soko_x, sokoban *soko_o)
{
    for (int i = 0; i < soko_o[0].pos[2]; i++){
        if (soko_o[i].pos[0] == soko_x->pos[0] &&
        soko_o[i].pos[1] == soko_x->pos[1])
            return 0;
    }
    endwin();
    free(map_tab);
    my_putstr("you loose ;(\n");
    exit(1);
}