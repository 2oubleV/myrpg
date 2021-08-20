/*
** EPITECH PROJECT, 2021
** mob.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void reset_player_effect(s_game *game)
{
    for (int i = 1; i < 4; i++) {
        if (game->data[i]->dmg_reduc != 1)
            game->data[i]->dmg_reduc = 1;
    }
}

void update_rect(s_game *game, sfTime *timer)
{
    sfIntRect rect = {0, 0, 96, 96};
    float rect_off;

    if (timer->microseconds >= 1000000) {
        sfSprite_setTextureRect(game->data[0]->spr, rect);
        return;
    }
    rect_off = ((float)timer->microseconds / 1000000) * 9;
    if (game->buffer == 0)
        rect.top = 576;
    else
        rect.top = 288;
    rect.left = 96 * (int)rect_off;
    sfSprite_setTextureRect(game->data[0]->spr, rect);
}

int choose_spell(s_game *game)
{
    int r_val = rand() % 2;

    if (r_val == 0) {
        for (int i = 1; i < 4; i++) {
            if (game->data[i]->hp > 0) {
                game->data[i]->hp -= 15 * game->data[1]->dmg_reduc;
                update_player_hp(game, i);
            }
        }
    } else {
        for (int count = 0; count < 3; count++) {
            r_val = rand() % 3 + 1;
            if (game->data[r_val]->hp > 0) {
                game->data[r_val]->hp -= 40 * game->data[1]->dmg_reduc;
                update_player_hp(game, r_val);
                return 1;
            }
        }
    }
    return (0);
}

void play_mob_turn(s_game *game)
{
    sfTime timer;

    if (game->data[0]->anim_clock == NULL) {
        game->data[0]->anim_clock = sfClock_create();
        game->buffer = choose_spell(game);
        return;
    }
    timer = sfClock_getElapsedTime(game->data[0]->anim_clock);
    update_rect(game, &timer);
    if (timer.microseconds >= 1000000) {
        reset_player_effect(game);
        sfClock_destroy(game->data[game->index]->anim_clock);
        game->data[game->index]->anim_clock = NULL;
        get_next_turn(game);
    }
}