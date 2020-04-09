/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** extract_parameter
*/

#include "server.h"

inline char *extract_parameter(char *tmp, char *cmd)
{
    char *data_from_client = strdup(tmp + strlen(cmd));
    char *input_after_clean;

    if (data_from_client[0] == '\r' && data_from_client[1] == '\0')
        return data_from_client;
    if (data_from_client[0] == ' ' && data_from_client[strlen(data_from_client) - 1] == '\r') {
        if ((input_after_clean = strdup(data_from_client + 1)) != NULL) {
            free_work(data_from_client);
            input_after_clean[strlen(input_after_clean) - 1] = '\0';
            return (input_after_clean);
        } else {
            return (NULL);
        }
    }
    return (NULL);
}