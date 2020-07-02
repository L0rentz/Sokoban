/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** init_ncurses
*/

#include "my.h"

void init_ncurses(all_t *all)
{
    initscr();
    raw();
    curs_set(0);
    noecho();
    init_window(all);
}

void init_window(all_t *all)
{
    int indent_y, indent_x, y, x;
    getmaxyx(stdscr, y, x);
    indent_x = x - all->len;
    indent_x /= 2;
    indent_y = y - all->lines;
    indent_y /= 2;
    all->window = subwin(stdscr, all->lines, all->len, indent_y, indent_x);
    keypad(all->window, TRUE);
    mvwprintw(all->window, 0, 0, all->map);
    wrefresh(all->window);
}

void center_window(all_t *all)
{
    int x, y;
    getmaxyx(stdscr, y, x);
    if (x >= all->len && y >= all->lines) {
        werase(all->window);
        wrefresh(all->window);
        endwin();
        init_ncurses(all);
    }
    else {
        werase(all->window);
        mvwprintw(all->window, all->lines / 2 - 1, 0,
            "Please enlarge \nyour terminal.");
        wrefresh(all->window);
    }
}