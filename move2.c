/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** move2
*/

#include "my.h"

void move_up2(all_t *all)
{
    if (all->ch == KEY_UP && all->map[all->i - all->len] != '#') {
        if ((all->map[all->i - all->len] != 'O')
            || (all->map[all->i - all->len] == 'X'
            && all->map[all->i - all->len * 2] == ' '))
            all->o_check = 0;
        if (all->map[all->i - all->len] == 'X'
            && all->map[all->i - all->len * 2] == 'X')
            all->o_check = 1;
        move_up2_bis(all);
    }
}

void move_down2(all_t *all)
{
    if (all->ch == KEY_DOWN && all->map[all->i + all->len] != '#') {
        if (all->map[all->i + all->len] != 'O'
            || (all->map[all->i + all->len] == 'X'
            && all->map[all->i + all->len * 2] == ' '))
            all->o_check = 0;
        if (all->map[all->i + all->len] == 'X'
            && all->map[all->i + all->len * 2] == 'X')
            all->o_check = 1;
        move_down2_bis(all);
    }
}

void move_left2(all_t *all)
{
    if (all->ch == KEY_LEFT && all->map[all->i - 1] != '#') {
        if (all->map[all->i - 1] != 'O'
            || (all->map[all->i - 1] == 'X' && all->map[all->i - 2] == ' '))
            all->o_check = 0;
        if (all->map[all->i - 1] == 'X' && all->map[all->i - 2] == 'X')
            all->o_check = 1;
        if (all->map[all->i - 1] == 'X' && all->map[all->i - 2] == ' ') {
            all->map[all->i] = 'O', all->map[all->i - 1] = 'P';
            all->map[all->i - 2] = 'X', all->i -= 1;
            all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
            put_box_state_zero(all, all->i), search_box_left(all, all->i);
        }
        else if (all->map[all->i - 1] == ' ' || all->map[all->i - 1] == 'O')
            all->map[all->i] = 'O', all->map[all->i - 1] = 'P', all->i -= 1;
        else if (all->map[all->i - 1] == 'X' && all->map[all->i - 2] == 'O') {
            all->map[all->i] = 'O', all->map[all->i - 1] = 'P';
            all->map[all->i - 2] = 'X', all->i -= 1;
            all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
            put_box_state_one(all, all->i), search_box_left(all, all->i); }
    }
}

void move_right2(all_t *all)
{
    if (all->ch == KEY_RIGHT && all->map[all->i + 1] != '#') {
        if (all->map[all->i + 1] != 'O'
            || (all->map[all->i + 1] == 'X' && all->map[all->i + 2] == ' '))
            all->o_check = 0;
        if (all->map[all->i + 1] == 'X' && all->map[all->i + 2] == 'X')
            all->o_check = 1;
        if (all->map[all->i + 1] == 'X' && all->map[all->i + 2] == ' ') {
            all->map[all->i] = 'O', all->map[all->i + 1] = 'P';
            all->map[all->i + 2] = 'X', all->i += 1;
            all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
            put_box_state_zero(all, all->i), search_box_right(all, all->i);
        }
        else if (all->map[all->i + 1] == ' ' || all->map[all->i + 1] == 'O')
            all->map[all->i] = 'O', all->map[all->i + 1] = 'P', all->i += 1;
        else if (all->map[all->i + 1] == 'X' && all->map[all->i + 2] == 'O') {
            all->map[all->i] = 'O', all->map[all->i + 1] = 'P';
            all->map[all->i + 2] = 'X', all->i += 1;
            all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
            put_box_state_one(all, all->i), search_box_right(all, all->i); }
    }
}

void reprint_point(all_t *all)
{
    if (all->o_check == 1) {
        all->ch = wgetch(all->window);
        move_up2(all);
        move_down2(all);
        move_left2(all);
        move_right2(all);
        mvwprintw(all->window, 0, 0, all->map);
        wrefresh(all->window);
    }
}