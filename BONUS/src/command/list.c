/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** list
*/

#include <stdio.h>
#include <stdlib.h>
#include "myftp.h"

void list(int csock, char *tmp, user_data_t *user)
{
    char buf[1];
    FILE *pp = NULL;
    char *cmd = "ls -l";

    tmp = tmp;
    user = user;
    pp = popen(cmd, "r");
    free(cmd);
    if (!pp) {
        dprintf(csock, "550 Requested file action not taken.\r\n");
        return;
    }
    dprintf(csock, "150 ");
    while (fread(buf, sizeof(char), 1, pp) > 0) {
        if (buf[0] == '\n')
            dprintf(csock, "\r\n");
        else
            dprintf(csock, buf);
    }
}