/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** list_boxes
*/

#include "my.h"

void search_box_up(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    tmp->box_pos -= all->len;
}

void search_box_down(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    tmp->box_pos += all->len;
}

void search_box_left(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    tmp->box_pos -= 1;
}

void search_box_right(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    tmp->box_pos += 1;
}

void put_box_state_one(all_t *all, int i)
{
    dlist_node_t *tmp = all->list_boxes->begin;
    while (tmp->box_pos != i)
        tmp = tmp->next;
    tmp->box_state = 1;
}