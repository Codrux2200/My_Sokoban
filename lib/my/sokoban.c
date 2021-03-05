/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** sokoban
*/
#include "my.h"

void print_map(char **map_tab, sokoban soko_p)
{
    for (int i = 0; map_tab[i] != NULL; i++)
        mvprintw(0 + i, 0,  map_tab[i]);
}

char *read_map(char *filepath)
{
    struct stat sb;
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &sb);
    buffer = malloc((sb.st_size + 2) * sizeof(char));
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\n';
    buffer[sb.st_size + 1] = '\0';
    return buffer;
}

void gestion_print_elements(sokoban *soko_o, sokoban *soko_x,
sokoban *soko_p, char **map_tab)
{
    switch(getch()) {
        case KEY_LEFT:
            if (test_colistion(-1, map_tab, soko_x, soko_p) == 1)
                soko_p->pos[0] -= 1;
            break;
        case KEY_UP:
            if (test_colistion(-2, map_tab, soko_x, soko_p) == 1)
                soko_p->pos[1] -= 1;
            break;
        case KEY_DOWN:
            if (test_colistion(2, map_tab, soko_x, soko_p) == 1)
                soko_p->pos[1] += 1;
            break;
        case KEY_RIGHT:
            if (test_colistion(1, map_tab, soko_x, soko_p) == 1)
                soko_p->pos[0] += 1;
            break;
        case 32:
            count_game(map_save("\0", 1), 0, 0, 0);
            break;
        case 'a': break;
    }
}

void print_elements(sokoban *soko_o, sokoban *soko_p, sokoban *soko_x)
{
    for (int i = 0; i < soko_o[0].pos[2]; i++)
        mvaddch(0 + soko_o[i].pos[1], 0 + soko_o[i].pos[0], 'O');
    for (int i = 0; i < soko_x[0].pos[2]; i++)
        mvaddch(0 + soko_x[i].pos[1], 0 + soko_x[i].pos[0], 'X');
    mvaddch(0 + soko_p->pos[1], 0 + soko_p->pos[0], 'P');
}

void test_terminal_size(int lign_end, int cols_end)
{
    if (cols_end != COLS && lign_end != LINES){
            clear();
            cols_end = COLS;
            lign_end = LINES;
    }
}
