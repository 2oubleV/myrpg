/*
** EPITECH PROJECT, 2021
** end.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void manage_mouse_cursor2(s_game *game, button_t *cursor)
{
    cursor->pos.x = game->event.mouseMove.x;
    cursor->pos.y = game->event.mouseMove.y;
    sfSprite_setPosition(cursor->sprite, cursor->pos);
}

void is_sprite_clicked2(s_game *game, sfSprite *sprite)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    float x = game->event.mouseButton.x;
    float y = game->event.mouseButton.y;

    if (sfFloatRect_contains(&rect, x, y) == sfTrue)
        sfRenderWindow_close(game->win);
}

void final_screen(s_game *game)
{
    game->button = create_button("assets/Images/exit.png", 605, 580, 0.9);
    if (game->end == 1)
        game->final_screen = create_button("assets/Images/win.jpg", 0, 0, 1);
    if (game->end == 2)
        game->final_screen = create_button("assets/Images/loose.jpg", 0, 0, 1);
}

sfBool end_condition(game_t *game)
{
    sfClock *clock;

    if (game->inv->liv == sfTrue && game->inv->mik == sfTrue) {
        clock = sfClock_create();
        while (sfClock_getElapsedTime(clock).microseconds < 2000000);
        sfClock_destroy(clock);
        return (sfTrue);
    } else
        return (sfFalse);
}