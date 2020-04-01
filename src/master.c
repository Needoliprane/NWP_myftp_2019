/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** master
*/

#include "myftp.h"

int master(int port, char *path)
{
    int sd;
    int client_len;
    struct sockaddr_in client;
    pid_t child;

    signal(SIGINT, close_down);

    printf("Listen starting on port %d\n", port);
    ssockfd = obtain_socket(port);
    while (1) {
        client_len = sizeof(client);
        if ((sd = accept(ssockfd, (struct sockaddr *) &client, &client_len)) < 0) {
            perror("accept connection failure");
            return (84);
        }
        child = fork();
        if (child == 0) {
            close(sd);
        } else {
            show_message(sd, &client);
        }
    }
    return (0);
}