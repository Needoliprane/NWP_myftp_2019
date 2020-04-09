/*
** EPITECH PROJECT, 2018
** checker.c
** File description:
** checker.c
*/

#include "server.h"

int print_error(char *str)
{
    fprintf(stderr, "%s\n", str);
    return (84);
}

void init_struct(struct sockaddr_in *sock_addr_in, char *av)
{
    sock_addr_in->sin_family = AF_INET;
    sock_addr_in->sin_addr.s_addr = htonl(INADDR_ANY);
    sock_addr_in->sin_port = htons(atoi(av));
}

void *free_work(void *str)
{
    free(str);
    return (NULL);
}