/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** stor
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "myftp.h"

void stor(int csock, char *tmp, user_data_t *user)
{
    char *file;

    file = extract_parameter(tmp, strlen("STOR"));
    if (file != NULL && open(file, O_WRONLY | O_CREAT, 0644) != -1) {
        dprintf(csock, "150 Requested file action okay, completed.\r\n");
        user->path = free_work(user->path);
        if ((user->path = strdup(file)) == NULL) {
            perror("An error occured : strdup : ");
            return;
        }
        return;
    }
    dprintf(csock, "550 Requested file action not taken.\r\n");
}