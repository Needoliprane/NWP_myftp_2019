/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cdup
*/

#include "server.h"

void cdup(int csock, char *tmp, user_data_t *user)
{
    char *path;

    if ((path = extract_parameter(tmp, "CDUP")) != NULL &&
            path[0] == '\r' && chdir("../") != -1) {
        user->path = free_work(user->path);
        if ((user->path = getcwd(user->path, 0)) == NULL) {
            perror("An error occured : getcwd :");
            return;
        }
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
    } else {
        dprintf(csock, "550 Requested file action not taken.\r\n");
    }
}