/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move
*/

#include "my.h"

void move_up(all_t *all)
{
    if (all->ch == KEY_UP && all->map[all->i - all->len] != '#') {
        all->o_check = (all->map[all->i - all->len] == 'O') ? 1 : 0;
        move_up_bis(all);
    }
}

void move_down(all_t *all)
{
    if (all->ch == KEY_DOWN && all->map[all->i + all->len] != '#') {
        all->o_check = (all->map[all->i + all->len] == 'O') ? 1 : 0;
        move_down_bis(all);
    }
}

void move_left(all_t *all)
{
    if (all->ch == KEY_LEFT && all->map[all->i - 1] != '#') {
        all->o_check = (all->map[all->i - 1] == 'O') ? 1 : 0;
        if (all->map[all->i - 1] == 'X' && all->map[all->i - 2] == ' ') {
            all->map[all->i] = ' ', all->map[all->i - 1] = 'P';
            all->map[all->i - 2] = 'X', all->i -= 1;
            box_state_check(all);
            search_box_left(all, all->i);
        }
        else if (all->map[all->i - 1] == ' ' || all->map[all->i - 1] == 'O')
            all->map[all->i] = ' ', all->map[all->i - 1] = 'P', all->i -= 1;
        else if (all->map[all->i - 1] == 'X' && all->map[all->i - 2] == 'O') {
            all->map[all->i] = ' ', all->map[all->i - 1] = 'P';
            all->map[all->i - 2] = 'X', all->i -= 1;
            all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
            put_box_state_one(all, all->i), search_box_left(all, all->i);
        }
    }
}

void move_right(all_t *all)
{
    if (all->ch == KEY_RIGHT && all->map[all->i + 1] != '#') {
        all->o_check = (all->map[all->i + 1] == 'O') ? 1 : 0;
        if (all->map[all->i + 1] == 'X' && all->map[all->i + 2] == ' ') {
            all->map[all->i] = ' ', all->map[all->i + 1] = 'P';
            all->map[all->i + 2] = 'X', all->i += 1;
            box_state_check(all);
            search_box_right(all, all->i);
        }
        else if (all->map[all->i + 1] == ' ' || all->map[all->i + 1] == 'O')
            all->map[all->i] = ' ', all->map[all->i + 1] = 'P', all->i += 1;
        else if (all->map[all->i + 1] == 'X' && all->map[all->i + 2] == 'O') {
            all->map[all->i] = ' ', all->map[all->i + 1] = 'P';
            all->map[all->i + 2] = 'X', all->i += 1;
            all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
            put_box_state_one(all, all->i), search_box_right(all, all->i);
        }
    }
}

void regroup_move(all_t *all)
{
    if (all->o_check != 1) {
        all->ch = wgetch(all->window);
        move_up(all);
        move_down(all);
        move_left(all);
        move_right(all);
        mvwprintw(all->window, 0, 0, all->map);
        wrefresh(all->window);
    }
}
