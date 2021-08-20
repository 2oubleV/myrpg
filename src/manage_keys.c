/*
** EPITECH PROJECT, 2021
** manage_keys.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

sfBool check_collision(game_t *game, sfFloatRect rect)
{
    float x = game->pos.x;
    float y = game->pos.y;

    return (sfFloatRect_contains(&rect, x, y));
}

void make_rain(game_t *game)
{
    if (game->map->rain_status == sfFalse) {
        game->map->rain_status = sfTrue;
        sfSprite_setTexture(game->map->sprite, game->map->rain_t, sfFalse);
        sfSprite_setTexture(game->player->sprite, game->player->rain_t,
            sfFalse);
    } else {
        game->map->rain_status = sfFalse;
        sfSprite_setTexture(game->map->sprite, game->map->texture, sfFalse);
        sfSprite_setTexture(game->player->sprite, game->player->texture,
            sfFalse);
    }
}

void manage_arrows(game_t *game)
{
    if (game->event.key.code == sfKeyUp)
        game->player->mov = 1;
    if (game->event.key.code == sfKeyDown)
        game->player->mov = 2;
    if (game->event.key.code == sfKeyLeft)
        game->player->mov = 3;
    if (game->event.key.code == sfKeyRight)
        game->player->mov = 4;
}

void manage_key_pressed(game_t *game)
{
    manage_arrows(game);
    if (game->event.key.code == sfKeyEscape) {
        if (game->status == 'g' || game->status == 'h')
            game->status = 'p';
        else if (game->status == 'u')
            game->status = 'm';
        else
            game->status = 'g';
    } if (game->event.key.code == sfKeyR)
        make_rain(game);
    if (game->event.key.code == sfKeyI) {
        if (game->status == 'g')
            game->status = 'i';
        else
            game->status = 'g';
    }
}

void manage_key_released(game_t *game)
{
    if (game->event.key.code == sfKeyUp && game->player->mov == 1)
        game->player->mov = 0;
    if (game->event.key.code == sfKeyDown && game->player->mov == 2)
        game->player->mov = 0;
    if (game->event.key.code == sfKeyLeft && game->player->mov == 3)
        game->player->mov = 0;
    if (game->event.key.code == sfKeyRight && game->player->mov == 4)
        game->player->mov = 0;
}
