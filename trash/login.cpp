/*
** EPITECH PROJECT, 2018
** login.c
** File description:
** login.c
*/

#include "server.h"

void user(int csock, char *tmp, user_data_t *var)
{
    char *user_name;

    if (var->password != NULL) {
        dprintf(csock, "530 Can't change from guest user.\r\n");
        return;
    }
    if ((user_name = get_args(tmp, "USER")) != NULL &&
            strcmp(user_name, "\r") == 0) {
        dprintf(csock, "530 Permission denied.\r\n");
        return;
    } else if (user_name == NULL) {
        dprintf(csock, "500 Syntax error, command unrecognized.\r\n");
        return;
    }
    var->username = user_name;
    dprintf(csock, "331 User name okay, need password.\r\n");
}

void pass(int csock, char *tmp, user_data_t *var)
{
    char *pass_tmp;

    if (var->username == NULL) {
        dprintf(csock, "503 Login with USER first.\r\n");
        return;
    }
    if (var->password != NULL) {
        dprintf(csock, "530 Can't change from guest user.\r\n");
        return;
    }
    if (strcasecmp(var->username, "anonymous") == 0 &&
            (pass_tmp = get_args(tmp, "PASS")) != NULL) {
        if (strcmp(pass_tmp, "\0") == 0) {
            var->password = pass_tmp;
            dprintf(csock, "230 User logged in, proceed.\r\n");
        }
    } else {
        free(var->username);
        var->username = NULL;
        dprintf(csock, "530 Login incorrect.\r\n");
    }
}
