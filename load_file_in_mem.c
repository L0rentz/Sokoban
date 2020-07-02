/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** load_file_in_mem
*/

#include "my.h"

void check_sokoban(char *file)
{
    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] != '\n' && file[i] != '#' && file[i] != 'O'
            && file[i] != 'P' && file[i] != ' ' && file[i] != 'X')
            exit(84);
}

char *load_file_in_mem(char *filepath)
{
    char *file;
    int fd = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    struct stat filestat;
    stat(filepath, &filestat);
    file = malloc((filestat.st_size + 1) * sizeof(char));
    read(fd, file, filestat.st_size);
    file[filestat.st_size] = '\0';
    close(fd);
    check_sokoban(file);
    return (file);
}

char *format_map2(char *file, int len_save, int size, int len_file)
{
    char *map = malloc((size + 1) * sizeof(char));
    for (int i = 0, j = 0, k = 0; i < size; i++, j += len_save) {
        for (; file[k] != '\n' && k <= len_file; i++, k++)
            map[i] = file[k];
        k++;
        for (; i < j + len_save - 1; i++)
            map[i] = ' ';
        map[i] = '\n';
    }
    return (map);
}

char *format_map(char *file, int size)
{
    int len_save = 0;
    int count = 0;
    int len_file = 0;
    for (; file[len_file] != '\0'; len_file++);
    for (int i = 0, len = 0; file[i] != '\0'; i++, len = 0, count++) {
        for (; file[i] != '\n'; i++, len++);
        len++;
        if (len > len_save)
            len_save = len;
    }
    size = len_save * count;
    char *map = format_map2(file, len_save, size, len_file);
    map[len_save * count] = '\0';
    free (file);
    return (map);
}