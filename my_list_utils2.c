/*
** EPITECH PROJECT, 2019
** list_utils2
** File description:
** Linked list functions
*/

#include "my.h"

dlist_t *new_list(void)
{
    return (NULL);
}

int is_empty_list(dlist_t *li)
{
    if (li == NULL)
        return (1);
    return (0);
}

dlist_node_t *new_dlist_node(int y)
{
    dlist_node_t *element;
    element = malloc(sizeof(*element));
    element->box_state = 0;
    element->box_pos = y;
    element->next = NULL;
    element->back = NULL;
    return (element);
}

void print_list(dlist_t *li)
{
    if (is_empty_list(li)) {
        my_putstr("Nothing to display, list is empty\n");
        return;
    }
    dlist_node_t *tmp = li->begin;
    while (tmp != NULL) {
        my_put_nbr(tmp->box_pos);
        if (tmp->next != NULL)
            my_putchar(' ');
        tmp = tmp->next;
    }
    my_putchar('\n');
}