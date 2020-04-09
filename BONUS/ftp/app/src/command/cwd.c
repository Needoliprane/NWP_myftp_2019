/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cwd
*/

#include "server.h"

void cwd(int csock, char *tmp, user_data_t *user)
{
    char *path;

    if ((path = extract_parameter(tmp, "CWD")) != NULL && chdir(path) != -1) {
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
        user->path = free_work(user->path);
        if ((user->path = strdup(path)) == NULL) {
            perror("An error occured : strdup : ");
            return;
        }
    } else {
        dprintf(csock, "550 Requested file action not taken.\r\n");
    }
}