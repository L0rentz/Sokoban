/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include "my.h"

int my_put_nbr(int nb);

void if_int_min(void)
{
    int i = 214748364;
    if (i >= 10) {
        my_put_nbr(i / 10);
        my_putchar(i % 10 + '0');
    }
    else
        my_putchar(i % 10 + '0');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_put_nbr(nb / 10);
            my_putchar(nb % 10 + '0');
        }
        else
            my_putchar(nb % 10 + '0');
    }
    if (nb == -2147483648)
        if_int_min();
    return (0);
}
