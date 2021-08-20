/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

sfSprite *create_sprite(char *path, int x, int y, float scale)
{
    sfSprite *new_sprite = sfSprite_create();
    sfTexture *tex = sfTexture_createFromFile(path, NULL);
    sfVector2f pos = {x, y};
    sfVector2f r_scale = {scale, scale};

    sfSprite_setTexture(new_sprite, tex, sfFalse);
    sfSprite_setPosition(new_sprite, pos);
    sfSprite_setScale(new_sprite, r_scale);
    return (new_sprite);
}

void init_hp_bar(s_data *data, int x, int y)
{
    sfVector2f pos = {x, y};
    sfVector2f size = {100, 10};
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfGreen);
    sfRectangleShape_setOutlineThickness(shape, 3);
    sfRectangleShape_setOutlineColor(shape, sfBlack);
    data->hp_bar = shape;
}

void update_player_hp(s_game *game, int index)
{
    sfRectangleShape *shape = game->data[index]->hp_bar;
    sfVector2f size = sfRectangleShape_getSize(shape);
    float hp = (100 / (float)game->data[index]->max_hp) * game->data[index]->hp;
    sfColor orange = {255, 153, 0, 255};

    size.x = hp;
    if (hp >= 75)
        sfRectangleShape_setFillColor(shape, sfGreen);
    if (hp < 75 && hp > 50)
        sfRectangleShape_setFillColor(shape, orange);
    if (hp < 50)
        sfRectangleShape_setFillColor(shape, sfRed);
    sfRectangleShape_setSize(shape, size);
}

int check_winner(s_game *game)
{
    if (game->data[0]->hp <= 0) {
        game->end = 1;
        return (1);
    } if (game->data[1]->hp <= 0 && game->data[2]->hp <= 0 &&
        game->data[2]->hp <= 0) {
        game->end = 2;
        return (2);
    }
    return (0);
}