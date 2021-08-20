/*
** EPITECH PROJECT, 2025
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
** File description:
** Created by William,
*/

#include "../include/game.h"

void make_help(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->help, NULL);
}

void init_help(game_t *game)
{
    sfTexture *h = sfTexture_createFromFile("assets/Images/help.jpg", NULL);

    game->help = sfSprite_create();
    sfSprite_setTexture(game->help, h, sfFalse);
}