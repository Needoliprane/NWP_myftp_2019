/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** delete
*/

#include "myftp.h"

void dele(int csock, char *tmp, user_data_t *user)
{
    char *path;

    user = user;
    path = extract_parameter(tmp, strlen("DELE"));
    if (path != NULL && remove(path) != -1) {
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
        return;
    }
    dprintf(csock, "550 Requested file action not taken.\r\n");
}
