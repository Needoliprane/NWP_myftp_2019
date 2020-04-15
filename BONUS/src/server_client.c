/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server_client
*/

#include "myftp.h"

static bool init_max_socket(int *sd, int *client_socket, int *max_sock,
                                                        fd_set *readfs)
{
    int i = 0;

    for (i = 0; i < 30; ++i) {
        *sd = client_socket[i];
        (*sd > 0) ? (FD_SET(*sd, readfs)) : (*sd);
        (*sd > *max_sock) ? (*max_sock = *sd) : (*sd);
    }
    if (i < 29 || i > 30) {
        return (false);
    }
    return (true);
}

static int init_select_tools(fd_set *readfs, int sock)
{
    FD_ZERO(readfs);
    FD_SET(sock, readfs);
    return (sock);
}

static int server_loop(int sock, char *path)
{
    fd_set readfs = {0};
    int client_socket[30] = {0};

    for (int max_sock = 0, sd = 0; 1; ) {
        if ((max_sock = init_select_tools(&readfs, sock)) == -1)
            exit(84);
        if (init_max_socket(&sd, client_socket, &max_sock, &readfs)
                                                            == false)
            exit (84);
        if (select(max_sock + 1, &readfs, NULL, NULL, NULL) == -1) {
            perror("An error occured : select : ");
            exit (84);
        }
        if (FD_ISSET(sock, &readfs)) {
            accept_new_client(sock, client_socket);
        }
        if (interprete_client_command(path, client_socket, readfs) == 84)
            return (84);
    }
    return (0);
}

int init_ftp(char **av)
{
    int sock = 0;
    sockaddr_in_t sock_addr_in = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return (84);
    init_struct(&sock_addr_in, av[1]);
    if (bind(sock, (struct sockaddr *)&sock_addr_in, sizeof(sock_addr_in))
                                                                    == -1)
        return (print_error("An error occured : bind : \n"));
    if (listen(sock, 30) == -1)
        return (print_error("An error occured : liesten : \n"));
    server_loop(sock, av[2]);
    return (0);
}