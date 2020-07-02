/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** header
*/

#ifndef CPE_BSQ_2019_MY_H
#define CPE_BSQ_2019_MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct dlist_node_s
{
    unsigned int pos;
    int box_state;
    int box_pos;
    struct dlist_node_s *back;
    struct dlist_node_s *next;
} dlist_node_t, node_t;

typedef struct dlist_s
{
    int length;
    struct dlist_node_s *begin;
    struct dlist_node_s *end;
} dlist_t;

typedef struct all_s
{
    int i;
    int j;
    int len;
    int lines;
    int ch;
    char *file;
    char *map;
    int o_check;
    WINDOW *window;
    dlist_t *list_boxes;
} all_t;

char *load_file_in_mem(char *filepath);
char *format_map(char *file, int size);
all_t *init_struct(char *av);
void move_up(all_t *all);
void move_down(all_t *all);
void move_left(all_t *all);
void move_right(all_t *all);
void move_up2(all_t *all);
void move_down2(all_t *all);
void move_left2(all_t *all);
void move_right2(all_t *all);
void init_ncurses(all_t *all);
dlist_t *new_list(void);
int is_empty_list(dlist_t *li);
dlist_node_t *new_dlist_node(int y);
void print_list(dlist_t *li);
dlist_t *push_back_list(dlist_t *li, int y);
dlist_t *push_front_list(dlist_t *li, int y);
dlist_t *pop_front_list(dlist_t *li);
dlist_t *pop_back_list(dlist_t *li);
dlist_t *clear_list(dlist_t *li);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void search_box_up(all_t *all, int i);
void search_box_down(all_t *all, int i);
void search_box_left(all_t *all, int i);
void search_box_right(all_t *all, int i);
void reprint_point(all_t *all);
void regroup_move(all_t *all);
void put_box_state_one(all_t *all, int i);
void put_box_state_zero(all_t *all, int i);
int get_box_state(all_t *all, int i);
int did_you_won(all_t *all);
all_t *reset(char *av, all_t *all);
void init_window(all_t *all);
void center_window(all_t *all);
void manual(void);
int my_strlen(char const *str);
int did_you_lose(all_t *all);
void move_up_bis(all_t *all);
void move_down_bis(all_t *all);
void move_up2_bis(all_t *all);
void move_down2_bis(all_t *all);
void box_state_check(all_t *all);

#endif
