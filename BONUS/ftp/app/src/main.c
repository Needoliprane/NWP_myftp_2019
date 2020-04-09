/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** main
*/

#include "server.h"

static int usage(char *name)
{
    printf("USAGE: %s port path\n", name);
    printf("       port is the port number on which \
            the server socket listens\n");
    printf("       path is the path to the home \
            directory for the Anonymous user\n");
    return (0);
}

static int master(char **av)
{
    struct stat stats;

    for (int i=0; i< av[1][i]; i++) {
        if (!isdigit(av[1][i])) {
            fprintf(stderr, "Wrong argument, -help for usage\n");
            return (84);
        }
    }
    stat(av[2], &stats);
    if (S_ISDIR(stats.st_mode))
        return (init_ftp(av));
    return (84);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp("-help", av[1]) == 0)
        return (usage(av[0]));
    if (ac == 3) {
        return (master(av));
    }
    fprintf(stderr, "Wrong argument, -help for usage\n");
    return (84);
}