/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** call_commands
*/

#include "server.h"

char const *tab[] = {"USER", "PASS", "CWD", "CDUP", "DELE", "PWD",
        "HELP", "NOOP", NULL};

void (* const command[])(int, char *, user_data_t *) = {user, pass, cwd,
        cdup, dele,pwd, help, noop, NULL};

static void read_client(int csock, char *temporary, user_data_t *user)
{
    if (temporary == NULL || strlen(temporary) < 2)
        return;
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

static int call_commands(int csock, char *path)
{
    char *temporary;
    user_data_t user;

    memset(&user, 0, sizeof(user));
    user.path = strdup(path);
    while (1) {
        if ((temporary = get_next_line(csock)) != NULL && strncmp("QUIT\r",
                                                        temporary, 5) == 0) {
            dprintf(csock, "221 Service closing control connection.\r\n");
            break;
        }
        read_client(csock, temporary, &user);
    }
    if (temporary)
        free(temporary);
    close(csock);
    return (0);
}

int interprete_client_command(char *path, int *client_socket, fd_set readfs)
{
    for (int i = 0; i < 30; i++) {
        if (FD_ISSET(client_socket[i], &readfs)) {
            call_commands(client_socket[i], path);
            client_socket[i] = 0;
        }
    }
    return 0;
}
