/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
char *read_map(char *filepath);
int l_save(int l, int state);
int count_game(char *map, int p, int o, int x);
void my_putstr_err(char *str);
int my_strlen(char *str);
void my_putstr(char *str);
int error_gestion_map(int p, int x, int o);
void test_terminal_size(int lign_end, int cols_end);
int l_gestion(int l, int s, char *line, char **map_tab);
int s_plus_function(char *line, int s);
void free_assemble(char *map, char *line);
int mini_function_s(char *map, char *line, int s, int i);
void print_describe(void);
void error_map_check(char c, char *map);
typedef struct sokoban sokoban;
struct sokoban{
    int pos[4];
};
typedef struct map_stock map_stock;
struct map_stock{
    char *map;
};
int defeat(char **map_tab, sokoban *soko_x, sokoban *soko_o);
void p_soko_gestion(sokoban *soko_p, int s, int l);
void copie(sokoban *soko_p, int s, int l);
void test_x_colision_reduce(int define , char **map_tab, sokoban *soko_x,
sokoban *soko_p);
char *map_save(char *map, int conv);
void small_reduce_soko(sokoban *soko_o, sokoban *soko_x, int x, int o);
void print_elements(sokoban *soko_o, sokoban *soko_p, sokoban *soko_x);
int mini_function_o(int o, sokoban *soko_o, int s, int l);
int mini_function_x(int x, sokoban *soko_x, int s, int l);
int suite(char **map_tab, sokoban *soko_o, sokoban *soko_x, sokoban *soko_p);
void print_map(char **map_tab, sokoban soko_p);
void sokoban_game(char *map, int x, int o, int big_line);
int test_colistion2(int define, char **map_tab, sokoban *soko_x,
sokoban *soko_p);
int test_x_to_x_colision(sokoban *soko_x, int i, int define);
void test_x_colision_reduce2(int define , char **map_tab,
sokoban *soko_x, sokoban *soko_p);
void test_x_colision_reduce3(int define , char **map_tab,
sokoban *soko_x, sokoban *soko_p);
int check_defeat(sokoban *soko_x, char **map_tab, sokoban *soko_o, int nbr);
void gestion_print_elements(sokoban *soko_o, sokoban *soko_x,
sokoban *soko_p, char **map_tab);
int test_colistion(int define, char **map_tab, sokoban *soko_x,
sokoban *soko_p);
int test_x_colision(int define , char **map_tab, sokoban *soko_x,
sokoban *soko_p);
int test_final_game(sokoban *soko_o, sokoban *soko_x);
#endif /* !MY_H_ */
