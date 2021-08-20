/*
** EPITECH PROJECT, 2021
** my_rpg.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void make_status(game_t *game)
{
    switch (game->status) {
        case 'm':
            make_menu(game);
            break;
        case 'g':
            make_game(game);
            break;
        case 'p':
            make_pause(game);
            break;
        case 'h':
            make_house(game);
            break;
        case 'u':
            make_help(game);
            break;
        case 'i':
            make_inventory(game);
            break;
    }
}

void update_screen(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    make_status(game);
    sfClock_restart(game->clock);
    sfRenderWindow_display(game->window);
}

void clock_handling(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    game->ratio = game->seconds / 0.0166667;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *pointer = malloc(sizeof(framebuffer_t));

    pointer->width = width;
    pointer->height = height;
    pointer->pixels = malloc(width * height * 4);
    return (pointer);
}

int my_rpg(void)
{
    game_t *game = init_game();

    init_help(game);
    if (game == NULL)
        return (my_putstr_error("Error : malloc failed.\n"));
    while (sfRenderWindow_isOpen(game->window)) {
        clock_handling(game);
        if (game->ratio >= 1) {
            analyse_event(game);
            update_screen(game);
        }
        if (end_condition(game) == sfTrue)
            break;
    }
    final_game(game->window, game->pause[5]);
    destroy_game(game);
    return (0);
}
