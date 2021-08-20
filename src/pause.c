/*
** EPITECH PROJECT, 2021
** pause.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void manage_music_volume(void)
{
    if (sfListener_getGlobalVolume() == 100)
        sfListener_setGlobalVolume(0);
    else
        sfListener_setGlobalVolume(100);
}

void manage_pause_buttons(game_t *game)
{
    if (is_sprite_clicked(game, game->pause[0]->sprite))
        game->status = 'm';
    if (is_sprite_clicked(game, game->pause[1]->sprite))
        game->status = 'g';
    if (is_sprite_clicked(game, game->pause[2]->sprite))
        sfRenderWindow_close(game->window);
    if (is_sprite_clicked(game, game->pause[3]->sprite))
        manage_music_volume();
}

button_t *create_button(char *fp, float x_pos, float y_pos, float scale_xy)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f position = {x_pos, y_pos};
    sfVector2f scale = {scale_xy, scale_xy};

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(fp, NULL);
    button->pos = position;
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setScale(button->sprite, scale);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    return (button);
}

button_t **init_pause(void)
{
    button_t **pause = malloc(sizeof(button_t *) * 6);

    pause[0] = create_button("assets/Images/main_menu.png", 605, 180, 0.9);
    pause[1] = create_button("assets/Images/resume.png", 605, 380, 0.9);
    pause[2] = create_button("assets/Images/exit.png", 605, 580, 0.9);
    pause[3] = create_button("assets/Images/sound.png", 1400, 20, 0.08);
    pause[4] = create_button("assets/Images/cross.png", 1360, -25, 0.07);
    pause[5] = create_button("assets/Images/sword.png", 500, 500, 0.4);
    return (pause);
}

void make_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    for (int j = 0; j < 3; j++)
        if (game->key[j]->status == sfFalse)
            sfRenderWindow_drawSprite(game->window, game->key[j]->sprite,
                NULL);
    if (game->map->rain_status == sfTrue)
        sfRenderWindow_drawSprite(game->window, game->map->rain, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(game->window, game->pause[i]->sprite, NULL);
    display_sound_logo(game);
    sfRenderWindow_drawSprite(game->window, game->pause[5]->sprite, NULL);
}
