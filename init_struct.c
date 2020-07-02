/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** init_struct
*/

#include "my.h"

void boxes_pos(all_t *all)
{
    for (int i = 0; all->map[i] != '\0'; i++)
        if (all->map[i] == 'X')
            all->list_boxes = push_back_list(all->list_boxes, i);
}

void player_len(all_t *all)
{
    all->len = 0;
    for (; all->map[all->i] != 'P'; all->i++);
    all->j = all->i;
    for (; all->map[all->j] != '\n'; all->j--);
    all->j++;
    for (; all->map[all->j] != '\n'; all->j++, all->len++);
    all->len++;
}

all_t *init_struct(char *av)
{
    all_t *all = malloc(sizeof(*all));
    all->list_boxes = new_list();
    all->window = NULL;
    all->i = 0;
    all->j = 0;
    all->o_check = 0;
    all->len = 0;
    all->ch = 0;
    all->lines = 0;
    all->file = load_file_in_mem(av);
    for (int i = 0; all->file[i] != '\0'; i++)
        if (all->file[i] == '\n')
            all->lines++;
    all->map = format_map(all->file, all->lines);
    player_len(all);
    boxes_pos(all);
    return (all);
}

all_t *reset(char *av, all_t *all)
{
    all->list_boxes = new_list();
    all->i = 0;
    all->j = 0;
    all->o_check = 0;
    all->len = 0;
    all->ch = 0;
    all->file = load_file_in_mem(av);
    all->map = format_map(all->file, all->lines);
    player_len(all);
    boxes_pos(all);
    init_window(all);
    return (all);
}