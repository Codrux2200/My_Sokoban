/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-saad.berrada
** File description:
** text_x_colision
*/

#include "my.h"

void test_x_colision_reduce(int define, char **map_tab, sokoban *soko_x,
sokoban *soko_p)
{
    if (define == 1){
        for (int i = 0; i < soko_x[0].pos[2]; i++){
            if (soko_x[i].pos[0] - 1 == soko_p->pos[0] &&
            soko_x[i].pos[1] == soko_p->pos[1]){
                if (test_colistion2(define, map_tab, &soko_x[i], soko_p) == 1
                && test_x_to_x_colision(soko_x, i, define) == 1)
                    soko_x[i].pos[0] += 1;
                else
                    soko_p->pos[0] = soko_x[i].pos[0] - 2;
            }
        }
    }
}

void test_x_colision_reduce2(int define , char **map_tab, sokoban *soko_x,
sokoban *soko_p)
{
    if (define == 2){
        for (int i = 0; i < soko_x[0].pos[2]; i++){
            if (soko_x[i].pos[1] - 1 == soko_p->pos[1] &&
            soko_x[i].pos[0] == soko_p->pos[0]){
                if (test_colistion2(define, map_tab, &soko_x[i], soko_p) == 1
                && test_x_to_x_colision(soko_x, i, define) == 1)
                    soko_x[i].pos[1] += 1;
                else
                    soko_p->pos[1] = soko_x[i].pos[1] - 2;
            }
        }
    }
}

void test_x_colision_reduce3(int define , char **map_tab,
sokoban *soko_x, sokoban *soko_p)
{
    if (define == -2){
        for (int i = 0; i < soko_x[0].pos[2]; i++){
            if (soko_x[i].pos[1] + 1 == soko_p->pos[1] &&
            soko_x[i].pos[0] == soko_p->pos[0]){
                if (test_colistion2(define, map_tab, &soko_x[i], soko_p) == 1
                && test_x_to_x_colision(soko_x, i, define) == 1)
                    soko_x[i].pos[1] -= 1;
                else
                    soko_p->pos[1] = soko_x[i].pos[1] + 2;
            }
        }
    }
}

int test_x_to_x_colision(sokoban *soko_x, int i, int define)
{
    for (int s = 0; s < soko_x[0].pos[2]; s++){
        if (define == -1){
            if (soko_x[i].pos[0] - 1 == soko_x[s].pos[0] &&
            soko_x[i].pos[1] == soko_x[s].pos[1])
                return 0;
        } else if (define == 1){
            if (soko_x[i].pos[0] + 1 == soko_x[s].pos[0] &&
            soko_x[i].pos[1] == soko_x[s].pos[1])
                return 0;
        } else if (define == -2) {
            if (soko_x[i].pos[0] == soko_x[s].pos[0] &&
            soko_x[i].pos[1] - 1 == soko_x[s].pos[1])
                return 0;
        } else if (define == 2) {
            if (soko_x[i].pos[0] == soko_x[s].pos[0] &&
            soko_x[i].pos[1] + 1 == soko_x[s].pos[1])
                return 0;
        }
    }
    return 1;
}