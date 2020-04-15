/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** accept_connection
*/

#include "myftp.h"

int accept_new_client(int sock, int *client_socket)
{
    int csock;
    int done = 0;
    sockaddr_in_t new_connection = {0};
    unsigned int len = sizeof(new_connection);

    if ((csock = accept(sock, (struct sockaddr *)&new_connection,
                                            &len)) == -1) {
        perror("An error occured : accept : ");
        exit(84);
    }
    dprintf(csock, "220 Service ready for new user.\r\n");
    for (int i = 0; done == 0 && i < 30; i++) {
        if (done == 0 && client_socket[i] == 0) {
            client_socket[i] = csock;
            done = 1;
        }
    }
    return (0);
}