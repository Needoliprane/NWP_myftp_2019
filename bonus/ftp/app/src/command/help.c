/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** help
*/

#include "myftp.h"

void help(int csock, char *tmp, user_data_t *var)
{
    tmp = tmp;
    var = var;
    dprintf(csock, "214 Help message.\r\n");
}