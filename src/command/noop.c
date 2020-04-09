/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** noop
*/

#include "server.h"

void noop(int csock, char *tmp, user_data_t *var)
{
    (void)tmp;
    var = var;
    dprintf(csock, "200 Command okay.\r\n");
}