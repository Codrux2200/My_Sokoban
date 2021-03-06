/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-saad.berrada
** File description:
** include a function that check if a game is over
*/
#include "my.h"

int check_defeat(sokoban *soko_x, char **map_tab, sokoban *soko_o, int nbr)
{
    for (int i = 0; i < soko_x[0].pos[2]; i++){
        if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] - 1] == '#' &&
        map_tab[soko_x[i].pos[1] + 1][soko_x[i].pos[0]] == '#')
            nbr++;
        if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] + 1] == '#' &&
        map_tab[soko_x[i].pos[1] - 1][soko_x[i].pos[0]] == '#')
            nbr++;
        if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] + 1] == '#' &&
        map_tab[soko_x[i].pos[1] + 1][soko_x[i].pos[0]] == '#')
            nbr++;
        if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] - 1] == '#' &&
        map_tab[soko_x[i].pos[1] - 1][soko_x[i].pos[0]] == '#')
            nbr++;
    }
    if (nbr == soko_x[0].pos[2])
        return (defeat(map_tab, soko_x, soko_o));
    else
        return 0;
}

void print_describe(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing");
    my_putstr(" ‘#’ for walls,\n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and");
    my_putstr(" ‘O’ for storage locations.\n");
}

void error_map_check(char c, char *map)
{
    if (c != 'P' && c != 'O' && c != 'X' && c != '#'
    && c != '\n' && c != ' '){
        my_putstr_err("ERROR MAP\n");
        free(map);
        exit(84);
    }
}

int l_save(int l, int state)
{
    static int la = 0;

    if (state == 1)
        la = l;
    return la;
}