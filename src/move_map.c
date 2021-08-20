/*
** EPITECH PROJECT, 2021
** move_map.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void move_rect(sfIntRect *rect, int offset, int max_value, int rect_left)
{
    if (rect->left < max_value)
        rect->left += offset;
    else
        rect->left = rect_left;
}

void adjust_x_corners(game_t *game)
{
    if (game->pos.x < -4040) {
        game->player->pos.x = 734 + (-game->pos.x - 4040);
    } else if (game->pos.x > 0) {
        game->player->pos.x = 734 - game->pos.x;
    } else {
        game->map->pos.x = game->pos.x;
        for (int i = 0; i < game->map->nb_trees; i++)
            game->map->tree[i]->pos.x = game->map->pos.x +
                game->map->tree[i]->first_pos.x;
        for (int j = 0; j < 3; j++)
            game->key[j]->pos.x = game->map->pos.x +
                game->key[j]->first_pos.x;
    }
}

void adjust_y_corners(game_t *game)
{
    if (game->pos.y < -2246) {
        game->player->pos.y = 409 + (-game->pos.y - 2246);
    } else if (game->pos.y > 0) {
        game->player->pos.y = 409 - game->pos.y;
    } else {
        game->map->pos.y = game->pos.y;
        for (int i = 0; i < game->map->nb_trees; i++)
            game->map->tree[i]->pos.y = game->map->pos.y +
                game->map->tree[i]->first_pos.y;
        for (int j = 0; j < 3; j++)
            game->key[j]->pos.y = game->map->pos.y +
                game->key[j]->first_pos.y;
    }
}

void move_map(game_t *game)
{
    adjust_x_corners(game);
    adjust_y_corners(game);
    sfSprite_setPosition(game->map->sprite, game->map->pos);
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfSprite_setScale(game->map->sprite, game->map->scale);
    for (int i = 0; i < game->map->nb_trees; i++)
        sfSprite_setPosition(game->map->tree[i]->sprite,
            game->map->tree[i]->pos);
    for (int j = 0; j < 3; j++)
        sfSprite_setPosition(game->key[j]->sprite, game->key[j]->pos);
}
