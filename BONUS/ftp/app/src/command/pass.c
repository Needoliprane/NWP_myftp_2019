/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** pass
*/

#include "server.h"

static int basic_check(user_data_t *user, int csock);

void pass(int csock, char *tmp, user_data_t *user)
{
    char *pass_tmp;

    if (basic_check(user, csock) == 84)
        return;
    if (strcasecmp(user->username, "anonymous") == 0 &&
            (pass_tmp = extract_parameter(tmp, "PASS")) != NULL) {
        if (strcmp(pass_tmp, "\0") == 0) {
            user->password = pass_tmp;
            dprintf(csock, "230 User logged in, proceed.\r\n");
        }
    } else {
        user->username = free_work(user->username);
        dprintf(csock, "530 Login incorrect.\r\n");
    }
}

static int basic_check(user_data_t *user, int csock)
{
    if (user->username == NULL) {
        dprintf(csock, "503 Login with USER first.\r\n");
        return (84);
    }
    if (user->password != NULL) {
        dprintf(csock, "530 Can't change from guest user.\r\n");
        return (84);
    }
    return (0);
}