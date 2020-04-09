/*
** EPITECH PROJECT, 2018
** path_command.c
** File description:
** path_command.c
*/

#include "server.h"

    // if (user->password == NULL) PWD
    //     dprintf(csock, "530 Please login with USER and PASS.\r\n");
    // else 

void pwd(int csock, char *tmp, user_data_t *user)
{
    char *args;

    if ((args = get_args(tmp, "PWD")) != NULL && args[0] == '\r')
        dprintf(csock, "257 \"%s\" created.\r\n", user->path);
    else
        dprintf(csock, "553 Requested action not taken.\r\n");
}

    // if (user->password == NULL) { CDUP
    //     dprintf(csock, "530 Please login with USER and PASS.\r\n");
    //     return;
    // }

void cdup(int csock, char *tmp, user_data_t *user)
{
    char *path;

    if ((path = get_args(tmp, "CDUP")) != NULL &&
            path[0] == '\r' && chdir("../") != -1) {
        free(user->path);
        user->path = NULL;
        if ((user->path = getcwd(user->path, 0)) == NULL) {
            perror("getcwd()");
            return;
        }
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
    } else
        dprintf(csock, "550 Requested file action not taken.\r\n");
}

void cwd(int csock, char *tmp, user_data_t *user)
{
    char *path;

    if ((path = get_args(tmp, "CWD")) != NULL && chdir(path) != -1) {
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
        user->path = strcpy(user->path, path);
    } else
        dprintf(csock, "550 Requested file action not taken.\r\n");
}

    // if (user->password == NULL) { CWD
    //     dprintf(csock, "530 Please login with USER and PASS.\r\n");
    //     return;
    // }

void dele(int csock, char *tmp, user_data_t *user)
{
    char *path;

    user = user;
    if ((path = get_args(tmp, "DELE")) != NULL && remove(path) != -1)
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
    else
        dprintf(csock, "550 Requested file action not taken.\r\n");
}

    // if (user->password == NULL) { DELE
    //     dprintf(csock, "530 Please login with USER and PASS.\r\n");
    //     return;
    // }