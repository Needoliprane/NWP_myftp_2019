/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** noop
*/

#include "myftp.h"

void noop(int csock, char *tmp, user_data_t *var)
{
    tmp = tmp;
    var = var;
    dprintf(csock, "200 Command okay.\r\n");
}