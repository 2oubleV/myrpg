/*
** EPITECH PROJECT, 2021
** events.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

sfBool is_sprite_clicked(game_t *game, sfSprite *sprite)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    float x = game->event.mouseButton.x;
    float y = game->event.mouseButton.y;

    return (sfFloatRect_contains(&rect, x, y));
}

void manage_click(game_t *game)
{
    sfSound_play(game->click);

    if (game->status == 'm')
        manage_menu_buttons(game);
    if (game->status == 'p')
        manage_pause_buttons(game);
}

void manage_mouse_cursor(game_t *game)
{
    game->pause[5]->pos.x = game->event.mouseMove.x;
    game->pause[5]->pos.y = game->event.mouseMove.y;
    sfSprite_setPosition(game->pause[5]->sprite, game->pause[5]->pos);
}

void analyse_event(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtMouseButtonPressed)
            manage_click(game);
        if (game->event.type == sfEvtKeyPressed)
            manage_key_pressed(game);
        if (game->event.type == sfEvtKeyReleased)
            manage_key_released(game);
        if (game->event.type == sfEvtMouseMoved && game->status != 'g')
            manage_mouse_cursor(game);
    }
}

void destroy_game(game_t *game)
{
    sfSound_destroy(game->click);
    sfSoundBuffer_destroy(game->click_buff);
    sfSound_destroy(game->player->step);
    sfSoundBuffer_destroy(game->player->step_buff);
    sfSound_destroy(game->fkey);
    sfSoundBuffer_destroy(game->fkey_buff);
    sfMusic_destroy(game->menu->sasageyo);
    free(game);
}