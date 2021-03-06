/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** trash
*/

#include "myftp.h"

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
    if (str) {
        free(str);
    }
    return (NULL);
}