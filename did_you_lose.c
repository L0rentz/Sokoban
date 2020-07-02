/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** did_you_lose
*/

#include "my.h"

int did_you_lose(all_t *all)
{
    int check = 0;
    dlist_node_t *tmp = all->list_boxes->begin;
    for (; tmp != NULL; tmp = tmp->next) {
        if ((all->map[tmp->box_pos - 1] == '#'
            && all->map[tmp->box_pos - all->len] == '#')
            || (all->map[tmp->box_pos - all->len] == '#'
            && all->map[tmp->box_pos + 1] == '#')
            || (all->map[tmp->box_pos + 1] == '#'
            && all->map[tmp->box_pos + all->len] == '#')
            || (all->map[tmp->box_pos + all->len] == '#'
            && all->map[tmp->box_pos - 1] == '#'))
            check++;
    }
    return (check);
}