/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-saad.berrada
** File description:
** include a function that check if a game is over
*/
#include "my.h"

void check_defeat(sokoban *soko_x, char **map_tab, sokoban *soko_o)
{
   for (int i = 0; i < soko_x[0].pos[2]; i++){
      if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] - 1] == '#' &&
      map_tab[soko_x[i].pos[1] + 1][soko_x[i].pos[0]] == '#')
         defeat(map_tab, &soko_x[i], soko_o);
      if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] + 1] == '#' &&
      map_tab[soko_x[i].pos[1] - 1][soko_x[i].pos[0]] == '#')
         defeat(map_tab, &soko_x[i], soko_o);
      if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] + 1] == '#' &&
      map_tab[soko_x[i].pos[1] + 1][soko_x[i].pos[0]] == '#')
         defeat(map_tab, &soko_x[i], soko_o);
      if (map_tab[soko_x[i].pos[1]][soko_x[i].pos[0] - 1] == '#' &&
      map_tab[soko_x[i].pos[1] - 1][soko_x[i].pos[0]] == '#')
         defeat(map_tab, &soko_x[i], soko_o);
   }
}