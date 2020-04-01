/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** main
*/

#include "myftp.h"

int print_help(void)
{
    printf("USAGE:\t./myftp port path\n\tport\t");
    printf("is the port number on which the server socket listens\n\t");
    printf("path\tis the path to the home directory for the Anonymous user\n");
    return (0);
}

int main(int ac, char **av)
{
    if (ac >= 2 && strcmp(av[1], "-help") == 0) {
        return (print_help());
    }
    if (ac == 3) {
        return (master(atoi(av[1]), av[2]));
    }
    return (84);
}