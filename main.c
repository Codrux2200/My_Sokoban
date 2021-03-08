/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** main
*/
#include "lib/my/my.h"

int main(int ac, char **av)
{
    char *map = NULL;

    if (ac == 1){
        my_putstr_err("use -h command\n");
        return 84;
    }
    if (av[1][0] == '-' && av[1][1] == 'h')
        print_describe();
    else {
        map = read_map(av[1]);
        if (count_game(map, 0, 0, 0) == 84) {
            my_putstr_err("ERROR MAP\n");
            return 84;
        }
        WINDOW *page;
    }
}

int count_game(char *map, int p, int o, int x)
{
    int big_line , line = 0;

    for (int i = 0; map[i] != '\0'; i++){
        error_map_check(map[i], map);
        if (big_line == 0 && map[i] == 'X'){
            my_putstr_err("error map\n");
            exit(84);
        }
        if (map[i] == 'P')
            p++;
        else if (map[i] == 'X')
            x++;
        else if (map[i] == 'O')
            o++;
        if (map[i] == '\n') {
            if (big_line < line)
                big_line = line;
        } else line++;
    }
    function_error(map, p, x, o);
    sokoban_game(map, x, o, big_line);
}

void sokoban_game(char *map, int x, int o, int big_line)
{
    sokoban soko_o[o], soko_x[x], soko_p[2];
    char **map_tab = malloc((my_strlen(map) + 1)* sizeof(char *));
    char *line = malloc(big_line * sizeof(char));

    for (int i = 0, s = 0, x = 0, o = 0, l = 0; map[i] != '\0'; i++) {
        if (map[i] == '#' || map[i] == ' ')
            s = mini_function_s(map, line, s, i);
        else if (map[i] != '\n' && map[i] != '\0'){
            if (map[i] == 'P') p_soko_gestion(soko_p, s, l);
            else if (map[i] == 'O') o = mini_function_o(o, soko_o, s, l);
            else if (map[i] == 'X') x = mini_function_x(x, soko_x, s, l);
            s = s_plus_function(line, s);
        } else {
            l = l_gestion(l, s, line, map_tab);
            line = malloc(big_line * sizeof(char *));
            s = 0;
        }
    }
    small_reduce_soko(soko_o, soko_x, x, o);
    free_assemble(map, line);
    suite(map_tab, soko_o, soko_x, soko_p);
}

int suite(char **map_tab, sokoban *soko_o, sokoban *soko_x, sokoban *soko_p)
{
    int cols_end = COLS;
    int lign_end = LINES;
    int end = 0;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    while (end == 0){
        test_terminal_size(lign_end, cols_end);
        print_map(map_tab, soko_p[1]);
        print_elements(soko_o, soko_p, soko_x);
        if (test_final_game(soko_o, soko_x) == 1)
            end = 1;
        if (check_defeat(soko_x, map_tab, soko_o, 0) == 2)
            end = 2;
        gestion_print_elements(soko_o, soko_x, &soko_p[0], map_tab);
    }
    usleep(100000);
    free(map_tab);
    endwin();
    exit(end - 1);
}

int error_gestion_map(int p, int x, int o)
{
    if (x != o)
        return 84;
    if (p != 1)
        return 84;
}