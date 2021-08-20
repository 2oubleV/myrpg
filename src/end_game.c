/*
** EPITECH PROJECT, 2021
** end_game.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void update_animation(s_game *game)
{
    sfTime timer;

    if (game->data[game->index]->anim_clock == NULL || game->index == 0)
        return;
    timer = sfClock_getElapsedTime(game->data[game->index]->anim_clock);
    if (timer.microseconds >= 300000) {
        sfClock_destroy(game->data[game->index]->anim_clock);
        game->data[game->index]->anim_clock = NULL;
        get_next_turn(game);
    }
}

void update_menu(s_game *game)
{
    sfVector2f pos = sfRectangleShape_getPosition(game->selector);

    if (pos.y == 760) {
        pos.y = 790;
        sfRectangleShape_setPosition(game->selector, pos);
    } else {
        pos.y = 760;
        sfRectangleShape_setPosition(game->selector, pos);
    }
}

sfVector2f create_vector(float x, float y)
{
    sfVector2f ret = {x, y};

    return (ret);
}