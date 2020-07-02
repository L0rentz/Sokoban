/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
**  move3
*/

#include "my.h"

void box_state_check(all_t *all)
{
    if (get_box_state(all, all->i) == 1)
        put_box_state_zero(all, all->i), all->o_check = 1;
}

void move_up_bis(all_t *all)
{
    if (all->map[all->i - all->len] == 'X'
        && all->map[all->i - all->len * 2] == ' ') {
        all->map[all->i] = ' ', all->map[all->i - all->len] = 'P';
        all->map[all->i - all->len * 2] = 'X', all->i -= all->len;
        if (get_box_state(all, all->i) == 1)
            put_box_state_zero(all, all->i), all->o_check = 1;
        search_box_up(all, all->i);
    }
    else if (all->map[all->i - all->len] == ' '
        || all->map[all->i - all->len] == 'O') {
        all->map[all->i] = ' ', all->map[all->i - all->len] = 'P';
        all->i -= all->len;
    }
    else if (all->map[all->i - all->len] == 'X'
        && all->map[all->i - all->len * 2] == 'O') {
        all->map[all->i] = ' ', all->map[all->i - all->len] = 'P';
        all->map[all->i - all->len * 2] = 'X', all->i -= all->len;
        all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
        put_box_state_one(all, all->i), search_box_up(all, all->i);
    }
}

void move_down_bis(all_t *all)
{
    if (all->map[all->i + all->len] == 'X'
        && all->map[all->i + all->len * 2] == ' ') {
        all->map[all->i] = ' ', all->map[all->i + all->len] = 'P';
        all->map[all->i + all->len * 2] = 'X', all->i += all->len;
        if (get_box_state(all, all->i) == 1)
            put_box_state_zero(all, all->i), all->o_check = 1;
        search_box_down(all, all->i);
    }
    else if (all->map[all->i + all->len] == ' '
        || all->map[all->i + all->len] == 'O') {
        all->map[all->i] = ' ', all->map[all->i + all->len] = 'P';
        all->i += all->len;
    }
    else if (all->map[all->i + all->len] == 'X'
        && all->map[all->i + all->len * 2] == 'O') {
        all->map[all->i] = ' ', all->map[all->i + all->len] = 'P';
        all->map[all->i + all->len * 2] = 'X', all->i += all->len;
        all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
        put_box_state_one(all, all->i), search_box_down(all, all->i);
    }
}

void move_up2_bis(all_t *all)
{
    if (all->map[all->i - all->len] == 'X'
        && all->map[all->i - all->len * 2] == ' ') {
        all->map[all->i] = 'O', all->map[all->i - all->len] = 'P';
        all->map[all->i - all->len * 2] = 'X', all->i -= all->len;
        all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
        put_box_state_zero(all, all->i), search_box_up(all, all->i);
    }
    else if (all->map[all->i - all->len] == ' '
        || all->map[all->i - all->len] == 'O') {
        all->map[all->i] = 'O', all->map[all->i - all->len] = 'P';
        all->i -= all->len;
    }
    else if (all->map[all->i - all->len] == 'X'
        && all->map[all->i - all->len * 2] == 'O') {
        all->map[all->i] = 'O', all->map[all->i - all->len] = 'P';
        all->map[all->i - all->len * 2] = 'X', all->i -= all->len;
        all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
        put_box_state_one(all, all->i), search_box_up(all, all->i);
    }
}

void move_down2_bis(all_t *all)
{
    if (all->map[all->i + all->len] == 'X'
        && all->map[all->i + all->len * 2] == ' ') {
        all->map[all->i] = 'O', all->map[all->i + all->len] = 'P';
        all->map[all->i + all->len * 2] = 'X', all->i += all->len;
        all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
        put_box_state_zero(all, all->i), search_box_down(all, all->i);
    }
    else if (all->map[all->i + all->len] == ' '
        || all->map[all->i + all->len] == 'O') {
        all->map[all->i] = 'O', all->map[all->i + all->len] = 'P';
        all->i += all->len;
    }
    else if (all->map[all->i + all->len] == 'X'
        && all->map[all->i + all->len * 2] == 'O') {
        all->map[all->i] = 'O', all->map[all->i + all->len] = 'P';
        all->map[all->i + all->len * 2] = 'X', all->i += all->len;
        all->o_check = (get_box_state(all, all->i) == 1) ? 1 : 0;
        put_box_state_one(all, all->i), search_box_down(all, all->i);
    }
}