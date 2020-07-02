/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** list_boxes2
*/

#include "my.h"

void put_box_state_zero(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    tmp->box_state = 0;
}

int get_box_state(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    return (tmp->box_state);
}

int did_you_won(all_t *all)
{
    int len = 0;
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp != NULL) {
        if (tmp->box_state == 1)
            len++;
        tmp = tmp->next;
    }
    return (len);
}