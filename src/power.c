/*
** EPITECH PROJECT, 2021
** defender.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void heal_player(s_game *game, int player)
{
    if (game->data[player]->hp <= 0)
        return;
    if (game->data[player]->hp + 20 > 100) {
        game->data[player]->hp = 100;
    } else {
        game->data[player]->hp += 20;
    }
    update_player_hp(game, player);
}

void apply_spell(s_game *game, int power_type)
{
    if (power_type == 1) {
        game->data[0]->hp -= 70;
        update_player_hp(game, 0);
        return;
    }
    for (int i = 1; i < 4; i++) {
        if (power_type == 2)
            heal_player(game, i);
        else
            game->data[i]->dmg_reduc = 0.7;
    }
}

void get_next_turn(s_game *game)
{
    sfVector2f pos = {705, 210};

    game->show_menu = 0;
    while (1) {
        game->index++;
        if (game->index == 4)
            game->index = 0;
        if (game->data[game->index]->hp > 0) {
            if (game->index != 0) {
                pos.x = game->data[game->index]->pos.x - 5;
                pos.y = game->data[game->index]->pos.y - 60;
                game->show_menu = 1;
            }
            sfSprite_setPosition(game->turn_arrow, pos);
            sfText_setString(game->menu_content, game->data[game->index]->desc);
            return;
        }
    }
}

void check_input(s_game *game)
{
    sfVector2f pos = sfRectangleShape_getPosition(game->selector);

    if (pos.y == 760) {
        game->data[0]->hp -= 30;
        update_player_hp(game, 0);
        game->data[game->index]->power_on_cd = 0;
        game->data[game->index]->anim_clock = sfClock_create();
        game->show_menu = 0;
    } else {
        if (game->data[game->index]->power_on_cd == 0) {
            apply_spell(game, game->index);
            game->data[game->index]->power_on_cd = 1;
            game->data[game->index]->anim_clock = sfClock_create();
            game->show_menu = 0;
        }
    }
}