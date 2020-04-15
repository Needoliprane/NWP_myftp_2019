/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** extract_parameter
*/

#include "myftp.h"

inline char *extract_parameter(char *tmp, int command_len)
{
    char *data_from_client;
    char *input_after_clean;

    if (command_len == 0 || tmp == NULL)
        return (NULL);
    if ((data_from_client = strdup(tmp + command_len)) == NULL)
        return (NULL);
    if (data_from_client[0] == '\r' && data_from_client[1] == '\0')
        return (data_from_client);
    if (data_from_client[0] == ' ' && 
            data_from_client[strlen(data_from_client) - 1] == '\r') {
        if ((input_after_clean = strdup(data_from_client + 1)) != NULL) {
            free_work(data_from_client);
            input_after_clean[strlen(input_after_clean) - 1] = '\0';
            return (input_after_clean);
        }
    }
    return (NULL);
}