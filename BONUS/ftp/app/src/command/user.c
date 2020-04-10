/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** user
*/

#include "myftp.h"

static int basic_check(user_data_t *user, int csock);

void user(int csock, char *tmp, user_data_t *var)
{
    char *user_name;

    if (basic_check(var, csock) == 84)
        return;
    user_name = extract_parameter(tmp, strlen("USER"));
    if (user_name != NULL && strcmp(user_name, "\r") == 0) {
        dprintf(csock, "530 Permission denied.\r\n");
        return;
    } else if (user_name == NULL) {
        dprintf(csock, "500 Syntax error, command unrecognized.\r\n");
        return;
    }
    var->username = user_name;
    dprintf(csock, "331 User name okay, need password.\r\n");
}

static int basic_check(user_data_t *user, int csock)
{
    if (user->password != NULL) {
        dprintf(csock, "530 Can't change from guest user.\r\n");
        return (84);
    }
    return (0);
}