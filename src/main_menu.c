/*
** EPITECH PROJECT, 2021
** main_menu.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void manage_menu_buttons(game_t *game)
{
    if (is_sprite_clicked(game, game->menu->button[1]->sprite))
        game->status = 'g';
    if (is_sprite_clicked(game, game->menu->button[2]->sprite))
        game->status = 'u';
    if (is_sprite_clicked(game, game->menu->button[3]->sprite))
        sfRenderWindow_close(game->window);
    if (is_sprite_clicked(game, game->pause[3]->sprite))
        manage_music_volume();
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("assets/Images/titan.png", NULL);
    sfSprite_setTexture(menu->sprite, menu->texture, sfFalse);
    menu->scale.x = 3;
    menu->scale.y = 3.025;
    sfSprite_setScale(menu->sprite, menu->scale);
    menu->rect = create_int_rect(0, 0, 500, 281);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    menu->clock = sfClock_create();
    menu->button = malloc(sizeof(button_t) * 4);
    menu->button[0] = create_button("assets/Images/title.png", 808, -20, 0.9);
    menu->button[1] = create_button("assets/Images/play.png", 205, 650, 0.9);
    menu->button[2] = create_button("assets/Images/help.png", 605, 650, 0.9);
    menu->button[3] = create_button("assets/Images/exit.png", 1005, 650, 0.9);
    menu->sasageyo = sfMusic_createFromFile("assets/Sounds/sasageyo.ogg");
    sfMusic_setVolume(menu->sasageyo, 20);
    sfMusic_setLoop(menu->sasageyo, sfTrue);
    return (menu);
}

void make_menu(game_t *game)
{
    float sec = sfClock_getElapsedTime(game->menu->clock).microseconds
        / 1000000.0;

    if (sfMusic_getStatus(game->menu->sasageyo) == sfStopped)
        sfMusic_play(game->menu->sasageyo);
    if (sec > 0.08) {
        move_rect(&game->menu->rect, 500, 5500, 0);
        sfClock_restart(game->menu->clock);
        sfSprite_setTextureRect(game->menu->sprite, game->menu->rect);
    }
    sfRenderWindow_drawSprite(game->window, game->menu->sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(game->window, game->menu->button[i]->sprite,
            NULL);
    display_sound_logo(game);
    sfRenderWindow_drawSprite(game->window, game->pause[5]->sprite, NULL);
}
