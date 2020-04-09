/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** delete
*/

#include "server.h"

void dele(int csock, char *tmp, user_data_t *user)
{
    char *path;

    user = user;
    if ((path = extract_parameter(tmp, "DELE")) != NULL && remove(path) != -1) {
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
    } else {
        dprintf(csock, "550 Requested file action not taken.\r\n");
    }
}
