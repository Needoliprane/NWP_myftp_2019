/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pwd
*/

#include "myftp.h"

void pwd(int csock, char *tmp, user_data_t *user)
{
    char *args;

    args = extract_parameter(tmp, strlen("PWD"));
    if (args != NULL && args[0] == '\r') {
        dprintf(csock, "257 \"%s\" created.\r\n", user->path);
        return;
    }
    dprintf(csock, "553 Requested action not taken.\r\n");
}