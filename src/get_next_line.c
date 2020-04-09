/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** get_next_line
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static unsigned int my_len(char const *str)
{
    unsigned int i = 0;

    for (; str && str[i]; i++);
    return (i);
}

static bool find_char(char const *str, char const c, char const d, char const e)
{
    for (unsigned int i = 0; str && str[i]; i++) {
        if (c == str[i])
            return (true);
        if (d == str[i])
            return (true);
        if (e == str[i])
            return (true);
    }
    return (false);
}

static char *my_starcat_gnl(char *tmp_ret, char *buf, unsigned int *i, int fd)
{
    unsigned int len_tmp = my_len(tmp_ret) + my_len(buf + *i);
    unsigned int cpy = 0;
    char *tmp = malloc(sizeof(char) * (len_tmp + 1));

    for (; tmp_ret && tmp && tmp_ret[cpy]; cpy++) {
        tmp[cpy] = tmp_ret[cpy];
    }
    for (; tmp && buf[*i] && buf[*i] != '\n'; *i += 1, cpy++)
        tmp[cpy] = buf[*i];
    tmp[cpy] = '\0';
    *i = (buf[*i] == '\0' || buf[*i] == EOF) ? 0 : *i + 1;
    for (unsigned int k = 0; buf && tmp_ret && k + 1 < 1; k++) {
        (fd == 0) ? (buf[k] = '\0') : 0;
    }
    free(tmp_ret);
    tmp_ret = NULL;
    return (tmp);
}

static char *one_read(char *buf)
{
    char *tmp = malloc(sizeof(char) * (my_len(buf) + 1));
    int i = 0;

    if (tmp == NULL)
        return (NULL);
    for (; buf && buf[i]; i++)
        tmp[i] = buf[i];
    tmp[i] = '\0';
    for (int i = 0; i <= 1; i++)
        buf[i] = '\0';
    return (tmp);
}

char *get_next_line(int fd)
{
    static char buf[1 + 1];
    char *tmp = malloc(sizeof(char) * (1 + 1));
    static unsigned int i = 0;

    (tmp != NULL) ? tmp[0] = '\0', buf[0] = '\0': 0;
    if (tmp && i != 0) {
        if (find_char(buf + i, '\n', '\0', '\r') == true)
            return (my_starcat_gnl(tmp, buf, &i, fd));
        tmp = my_starcat_gnl(tmp, buf, &i, fd);
    }
    for (int len = 0; tmp && (len = read(fd, buf, 1)) > 0; ) {
        if (find_char(buf, '\n', '\0', '\r') == true)
            return (my_starcat_gnl(tmp, buf, &i, fd));
        tmp = my_starcat_gnl(tmp, buf, &i, fd);
        if (1 > len && fd != 0)
            return ((tmp != NULL) ? tmp : one_read(buf));
    }
    if (tmp && my_len(tmp) > 1)
        return (tmp);
    return (NULL);
}