/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** not_implem
*/

#include "myftp.h"

void not_implem(int socks, char *tmp, user_data_t *user)
{
    tmp = tmp;
    user = user;
    dprintf(socks, "502	Command not implemented.\r\n");
}