/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** gestion_colision
*/

#include "my.h"

int test_colistion(int define, char **map_tab, sokoban *soko_x, sokoban *soko_p)
{
    test_x_colision(define, map_tab, soko_x, soko_p);
    switch (define){
        case -1:
            if (map_tab[soko_p->pos[1]][soko_p->pos[0] - 1] == '#')
                return 0;
            break;
        case 1:
            if (map_tab[soko_p->pos[1]][soko_p->pos[0] + 1] == '#')
                return 0;
            break;
        case 2:
            if (map_tab[soko_p->pos[1] + 1][soko_p->pos[0]] == '#')
                return 0;
            break;
        case -2:
            if (map_tab[soko_p->pos[1] - 1][soko_p->pos[0]] == '#')
                return 0;
            break;
    }
    return 1;
}

int test_colistion2(int define, char **map_tab, sokoban *soko_x,
sokoban *soko_p)
{
    switch (define) {
        case -1:
            if (map_tab[soko_x->pos[1]][soko_x->pos[0] - 1] == '#')
                return 0;
            break;
        case 1:
            if (map_tab[soko_x->pos[1]][soko_x->pos[0] + 1] == '#')
                return 0;
            break;
        case 2:
            if (map_tab[soko_x->pos[1] + 1][soko_x->pos[0]] == '#')
                return 0;
            break;
        case -2:
            if (map_tab[soko_x->pos[1] - 1][soko_x->pos[0]] == '#')
                return 0;
            break;
    }
    return 1;
}

int test_x_colision(int define , char **map_tab, sokoban *soko_x,
sokoban *soko_p)
{
    if (define == -1){
        for (int i = 0; i < soko_x[0].pos[2]; i++){
            if (soko_x[i].pos[0] + 1 == soko_p->pos[0] &&
            soko_x[i].pos[1] == soko_p->pos[1]){
                if (test_colistion2(define, map_tab, &soko_x[i], soko_p) == 1 &&
                test_x_to_x_colision(soko_x, i, define) == 1)
                    soko_x[i].pos[0] -= 1;
                else
                    soko_p->pos[0] = soko_x[i].pos[0] + 2;
            }
        }
    }
    test_x_colision_reduce(define, map_tab, soko_x, soko_p);
    test_x_colision_reduce2(define, map_tab, soko_x, soko_p);
    test_x_colision_reduce3(define, map_tab, soko_x, soko_p);
    return 1;
}

int test_final_game(sokoban *soko_o, sokoban *soko_x)
{
    static int win = 0;
    int count = 0;

    for (int i = 0; i < soko_x[0].pos[2]; i++){
        for (int j = 0; j < soko_o[0].pos[2]; j++){
            if (soko_x[i].pos[0] == soko_o[j].pos[0]
            && soko_x[i].pos[1] == soko_o[j].pos[1])
                count++;
        }
    }
    if (count == soko_x[0].pos[2])
        win = 1;
    else
        win = 0;
    return win;
}