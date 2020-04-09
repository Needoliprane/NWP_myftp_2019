/*
** EPITECH PROJECT, 2018
** help_noop.c
** File description:
** help_noop.c
*/

#include "server.h"
#include <stdio.h>

void help(int csock, char *tmp, user_data_t *var)
{
    (void)tmp;
    var = var;

    // if (var->password == NULL) {
    //     dprintf(csock, "530 Please login with USER and PASS.\r\n");
    //     return;
    // }
    dprintf(csock, "214 Help message.\r\n");
}

void noop(int csock, char *tmp, user_data_t *var)
{
    (void)tmp;
    var = var;

    // if (var->password == NULL) {
    //     dprintf(csock, "530 Please login with USER and PASS.\r\n");
    //     return;
    // }
    dprintf(csock, "200 Command okay.\r\n");
}
