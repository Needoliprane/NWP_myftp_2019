/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** call_commands
*/

#include "myftp.h"

char const *tab[] = {
        "USER", "PASS", "CWD", "CDUP", "DELE", "PWD",
        "HELP", "NOOP", "LIST", "STOR", "RETR", NULL};

void (* const command[])(int, char *, user_data_t *) = {
        user, pass, cwd, cdup, dele,pwd,
        help, noop, list, stor, not_implem, not_implem, NULL};

void not_implem(int socks, char *tmp, user_data_t *user)
{
    tmp = tmp;
    user = user;
    dprintf(socks, "502	Command not implemented.\r\n");
}

static void read_client_command(int csock, char *temporary, user_data_t *user)
{
    if (temporary == NULL || strlen(temporary) < 2) {
        if (temporary == NULL)
            return;
        if (strlen(temporary) < 2)
            free(temporary);
        return;
    }
    for (int i = 0; tab[i]; i++) {
        if (i > 2  && user->password == NULL) {
            dprintf(csock, "530 Please login with USER and PASS.\r\n");
            return;
        }
        if (tab[i] && strncmp(temporary, tab[i], strlen(tab[i]) - 1) == 0) {
            command[i](csock, temporary, user);
            return;
        }
    }
    dprintf(csock, "500 Syntax error, command unrecognized.\r\n");
}

static void free_try(user_data_t *user)
{
    if (user->password)
        free(user->password);
    if (user->path)
        free(user->path);
    if (user->username)
        free(user->username);
}

static int call_commands(int csock, char *path)
{
    char *temporary;
    user_data_t user = {0};

    user.path = strdup(path);
    while (1) {
        if ((temporary = get_next_line(csock)) != NULL && strncmp("QUIT\r",
                                                        temporary, 5) == 0) {
            dprintf(csock, "221 Service closing control connection.\r\n");
            break;
        }
        read_client_command(csock, temporary, &user);
    }
    if (temporary)
        free(temporary);
    free_try(&user);
    if (close(csock) == -1)
        return (84);
    return (0);
}

int interprete_client_command(char *path, int *client_socket, fd_set readfs)
{
    int control = 0;

    for (int i = 0; i < 30; i++) {
        if (FD_ISSET(client_socket[i], &readfs)) {
            control = call_commands(client_socket[i], path);
            client_socket[i] = 0;
        }
        if (control != 0) {
            return (84);
        }
    }
    return (0);
}
