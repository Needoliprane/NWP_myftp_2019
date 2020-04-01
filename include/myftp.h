/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** myftp
*/

#ifndef MYFTP_H_
#define MYFTP_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/signal.h>

int ssockfd;
extern int ssockfd;


//*********************************************************//
void close_down(int sigtype);
void show_message(int sd, struct sockaddr_in *client);
int obtain_socket(int port);
int master(int port, char *path);

#endif /* !MYFTP_H_ */
