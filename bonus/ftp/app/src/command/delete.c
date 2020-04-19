/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** delete
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "myftp.h"

static int check_path(char *path);
static int rmtree(char *path, DIR *dir);
static char *buil_full_path(char *path, char *file);

void dele(int csock, char *tmp, user_data_t *user)
{
    char *path;
    DIR *dir;

    user = user;
    path = extract_parameter(tmp, strlen("DELE"));
    if (path != NULL && remove(path) != -1) {
        dprintf(csock, "250 Requested file action okay, completed.\r\n");
        return;
    }
    if (check_path(path) == 0 || (dir = opendir(path)) != NULL) {
        if (rmtree(path, dir) == 0) {
            dprintf(csock, "250 Requested file action okay, completed.\r\n");
            return;
        }
    }
    dprintf(csock, "550 Requested file action not taken.\r\n");
}

static char *buil_full_path(char *path, char *file)
{
    char *full_path;

    full_path = calloc(strlen(path) + strlen(file) + 1, sizeof(char));
    strcpy(full_path, path);
    strcat(full_path, "/");
    strcat(full_path, file);
    return (full_path);
}

static int check_path(char *path)
{
    struct stat stat_path;

    stat(path, &stat_path);
    if (S_ISDIR(stat_path.st_mode) == 0)
        return (84);
    return (0);
}

static int rmtree(char *path, DIR *dir)
{
    char *full_path;
    struct stat stat_entry;
    struct dirent *entry;

    for (;dir != NULL && (entry=readdir(dir)) != NULL; free_work(full_path)) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
            continue;
        full_path = buil_full_path(path, entry->d_name);
        stat(full_path, &stat_entry);
        if (S_ISDIR(stat_entry.st_mode) != 0) {
            rmtree(full_path, opendir(full_path));
            continue;
        }
        if (unlink(full_path) != 0)
            return (84);
    }
    if (rmdir(path) != 0)
        return (84);
    closedir(dir);
    return (0);
}