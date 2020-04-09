/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

/*Include*/
#include <stdbool.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>

/*STRUTURE*/

typedef struct user_data_s {
    char *username;
    char *password;
    char *path;
} user_data_t;

/*Init*/
int init_ftp(char **av);
void init_struct(struct sockaddr_in *sock_addr_in, char *av);

/* launch */
int server_socket(void);
int interprete_client_command(char *path, int *client_socket, fd_set readfs);

/* lib*/
void *free_work(void *str);
char *get_next_line(int fd);

/*loop tool*/
char *extract_parameter(char *tmp, char *cmd);

/* Pirnt Errpr*/
int print_error(char *str);

/* Command accepted*/
void user(int csock, char *tmp, user_data_t *var);
void pass(int csock, char *tmp, user_data_t *var);
void help(int csock, char *tmp, user_data_t *var);
void noop(int csock, char *tmp, user_data_t *var);
void pwd(int csock, char *tmp, user_data_t *var);
void cdup(int csock, char *tmp, user_data_t *var);
void cwd(int csock, char *tmp, user_data_t *var);
void dele(int csock, char *tmp, user_data_t *var);

#endif /*SERVER_H*/
