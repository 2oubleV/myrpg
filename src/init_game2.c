/*
** EPITECH PROJECT, 2021
** init_game2.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

sfIntRect create_int_rect(int left, int top, int width, int height)
{
    sfIntRect rect = {left, top, width, height};

    return (rect);
}

keys_t **init_keys(void)
{
    sfTexture *texture = sfTexture_createFromFile("assets/Images/key.png",
        NULL);
    keys_t **key = malloc(sizeof(keys_t *) * 3);
    sfIntRect rect[3] = {{0, 0, 32, 32}, {96, 0, 32, 32}, {64, 0, 32, 32}};

    for (int i = 0; i < 3; i++) {
        key[i] = malloc(sizeof(keys_t));
        key[i]->sprite = sfSprite_create();
        key[i]->scale.x = 1;
        key[i]->scale.y = 1;
        sfSprite_setTextureRect(key[i]->sprite, rect[i]);
        sfSprite_setScale(key[i]->sprite, key[i]->scale);
        sfSprite_setTexture(key[i]->sprite, texture, sfFalse);
        key[i]->status = sfFalse;
    }
    key[0]->first_pos = create_first_pos(608, 545);
    key[1]->first_pos = create_first_pos(293, 844);
    key[2]->first_pos = create_first_pos(1326, 968);
    return (key);
}