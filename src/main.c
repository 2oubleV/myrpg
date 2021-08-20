/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

int main(int argc, char **argv)
{
    if (argc == 1) {
        return (my_rpg());
    } else if (argc == 2 && my_strcmp("-h", argv[1]) == 1) {
        my_putstr(HELP);
        return (0);
    } else {
        my_putstr_error("Error.\n");
        return (84);
    }
}
