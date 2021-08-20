/*
** EPITECH PROJECT, 2021
** move_map.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void animate_player(game_t *game)
{
    float sec_player = sfClock_getElapsedTime(game->player->clock).microseconds
        / 1000000.0;
    float sec_rain = sfClock_getElapsedTime(game->map->clock).microseconds
        / 1000000.0;

    if (game->map->rain_status == sfTrue && sec_rain > 0.07) {
        move_rect(&game->map->rect_rain, 512, 3584, 0);
        sfSprite_setTextureRect(game->map->rain, game->map->rect_rain);
        sfClock_restart(game->map->clock);
    } if (sec_player > 0.12) {
        if (game->player->mov == 0)
            game->player->rect.left = 27;
        else {
            move_rect(&game->player->rect, 27, 81, 0);
        }
        if (game->player->rect.left == 0 || game->player->rect.left == 54)
            sfSound_play(game->player->step);
        sfClock_restart(game->player->clock);
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
}

void rotate_players(game_t *game)
{
    switch (game->player->mov)
    {
        case 1:
            game->player->rect.top = 96;
            break;
        case 2:
            game->player->rect.top = 0;
            break;
        case 3:
            game->player->rect.top = 32;
            break;
        case 4:
            game->player->rect.top = 64;
            break;
    }
}

int check_hb(game_t *game, int x, int y)
{
    int color = sfColor_toInteger(sfImage_getPixel(game->map->hitbox, x, y));

    if (color != 255 && game->player->mov != 0)
        rotate_players(game);
    return (color);
}

void is_key_found(game_t *game)
{
    sfFloatRect intersection;
    sfFloatRect player = sfSprite_getGlobalBounds(game->player->sprite);
    sfFloatRect key;

    for (int i = 0; i < 3; i++) {
        key = sfSprite_getGlobalBounds(game->key[i]->sprite);
        if (sfFloatRect_intersects(&player, &key, &intersection) == sfTrue) {
            if (game->key[i]->status == sfFalse) {
                sfSound_play(game->fkey);
                game->key[i]->status = sfTrue;
            }
        }
    }
}

void move_player(game_t *game)
{
    int x = -game->pos.x + 745 + 14;
    int y = -game->pos.y + 425 + 40;
    int b = 255;

    if (game->player->mov == 1 && check_hb(game, x / 3, (y - 6) / 3)
        != b) {
        game->pos.y += game->player->speed;
    } if (game->player->mov == 2 && check_hb(game, x / 3, (y + 6) / 3)
        != b) {
        game->pos.y -= game->player->speed;
    } if (game->player->mov == 3 && check_hb(game, (x - 6) / 3, y / 3)
        != b) {
        game->pos.x += game->player->speed;
    } if (game->player->mov == 4 && check_hb(game, (x + 6) / 3, y / 3)
        != b) {
        game->pos.x -= game->player->speed;
    }
    animate_player(game);
    move_map(game);
    is_key_found(game);
}
