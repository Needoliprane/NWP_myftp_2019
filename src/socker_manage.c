/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** socker_manage
*/

#define SIZE 2084
#include "myftp.h"

void close_down(int sigtype)
{
    close(ssockfd);
    printf("Listen terminated\n");
    exit(0);
}

void show_message(int sd, struct sockaddr_in *client)
{
    char buf[SIZE];
    int no;

    printf("port : %d\n", client->sin_port);
    printf("addr : %d\n", client->sin_addr.s_addr);

    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("could not create a socket");
        exit(83);
    }
    if (bind(sockfd, (struct sockaddr *)&client, sizeof(client)) < 0) {
        perror("could not bind socket to address");
        exit(84);
    }
    // if (listen(sockfd, 1024) == -1) {
    //     perror("listen error");
    //     exit(84);
    // }
    // return sockfd;

    while ((no = read(sd, buf, SIZE)) > 0)
        write(1, buf, no);
    write(sockfd, "lol", 4);
    exit(0);
}

int obtain_socket(int port)
{
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("could not create a socket");
        exit(84);
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("could not bind socket to address");
        exit(84);
    }
    if (listen(sockfd, 1024) == -1) {
        perror("listen error");
        exit(84);
    }
    return sockfd;
}