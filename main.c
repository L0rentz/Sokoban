/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main
*/

#include "my.h"

void sokoban_loop(all_t *all, char *av)
{
    while (all->ch != 'q') {
        center_window(all);
        if (all->ch == ' ') {
            all = reset(av, all);
            mvwprintw(all->window, 0, 0, all->map), wrefresh(all->window);
        }
        regroup_move(all), reprint_point(all);
        if (did_you_won(all) == all->list_boxes->length) {
            endwin(), free(all->map), clear_list(all->list_boxes), free(all);
            exit(0);
        }
        else if (did_you_lose(all) == all->list_boxes->length) {
            endwin(), free(all->map), clear_list(all->list_boxes), free(all);
            exit(1);
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 1 || ac > 2) return (84);
    if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        manual();
    else if (ac == 2) {
        all_t *all = init_struct(av[1]);
        init_ncurses(all);
        sokoban_loop(all, av[1]);
        endwin(), free(all->map), clear_list(all->list_boxes), free(all);
    }
    return (0);
}
