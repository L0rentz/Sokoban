/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** manual
*/

#include "my.h"

void manual(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     Map representing the warehouse map file.\n");
    my_putstr("         Sokoban is a puzzle game in which the player pushes "
                "crates or boxes around in a warehouse, \n             "
                "trying to get them to storage locations.\n");
    my_putstr("     - ‘#’ are for walls.\n");
    my_putstr("     - ‘P’ for the player.\n");
    my_putstr("     - ‘X’ for boxes.\n");
    my_putstr("     - ‘O’ for storage locations.\n");
    my_putstr("CONTROLS\n");
    my_putstr("     - Use arrow up, left, right and down to move.\n");
    my_putstr("     - Press space to restart.\n");
    my_putstr("     - Press Q to quit\n");
}
