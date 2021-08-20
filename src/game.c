/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void display_sound_logo(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->pause[3]->sprite, NULL);
    if (sfListener_getGlobalVolume() == 0)
        sfRenderWindow_drawSprite(game->window, game->pause[4]->sprite, NULL);
}

void make_game(game_t *game)
{
    if (sfMusic_getStatus(game->menu->sasageyo) == sfPlaying)
        sfMusic_stop(game->menu->sasageyo);
    check_home_pos(game);
    move_player(game);
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    for (int i = 0; i < game->map->nb_trees; i++)
        sfRenderWindow_drawSprite(game->window, game->map->tree[i]->sprite,
            NULL);
    for (int j = 0; j < 3; j++)
        if (game->key[j]->status == sfFalse)
            sfRenderWindow_drawSprite(game->window, game->key[j]->sprite,
                NULL);
    if (game->map->rain_status == sfTrue)
        sfRenderWindow_drawSprite(game->window, game->map->rain, NULL);
    return;
}
