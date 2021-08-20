/*
** EPITECH PROJECT, 2021
** inventory.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void init_livai_mikasa(inv_t *inv)
{
    sfTexture *livai_t = sfTexture_createFromFile("assets/Images/livai.png",
        NULL);
    sfTexture *mikasa_t = sfTexture_createFromFile("assets/Images/mikasa.png",
        NULL);
    sfVector2f pos = {723, 388};

    inv->livai = sfSprite_create();
    sfSprite_setTexture(inv->livai, livai_t, sfFalse);
    sfSprite_setPosition(inv->livai, pos);
    inv->liv = sfFalse;
    inv->mikasa = sfSprite_create();
    sfSprite_setTexture(inv->mikasa, mikasa_t, sfFalse);
    sfSprite_setPosition(inv->mikasa, pos);
    inv->mik = sfFalse;
}

inv_t *init_inventory(void)
{
    inv_t *inv = malloc(sizeof(inv_t));
    sfTexture *texture = sfTexture_createFromFile("assets/Images/inventory"
        ".png", NULL);
    sfTexture *none = sfTexture_createFromFile("assets/Images/none.png",
        NULL);
    sfVector2f pos[6] = {{455, 320}, {679, 320}, {908, 320}, {455, 570},
        {679, 570}, {908, 570}};

    inv->sprite = sfSprite_create();
    sfSprite_setTexture(inv->sprite, texture, sfFalse);
    inv->none = malloc(sizeof(sfSprite *) * 6);
    for (int i = 0; i < 6; i++) {
        inv->none[i] = sfSprite_create();
        sfSprite_setTexture(inv->none[i], none, sfFalse);
        sfSprite_setPosition(inv->none[i], pos[i]);
    }
    init_livai_mikasa(inv);
    return (inv);
}

void make_inventory(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->map->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    for (int i = 0; i < 3; i++)
        if (game->key[i]->status == sfFalse)
            sfRenderWindow_drawSprite(game->window, game->key[i]->sprite,
                NULL);
    if (game->map->rain_status == sfTrue)
        sfRenderWindow_drawSprite(game->window, game->map->rain, NULL);
    sfRenderWindow_drawSprite(game->window, game->inv->sprite, NULL);
    for (int j = 0; j < 3; j++)
        if (game->key[j]->status == sfFalse)
            sfRenderWindow_drawSprite(game->window, game->inv->none[j], NULL);
    if (game->inv->liv == sfFalse)
        sfRenderWindow_drawSprite(game->window, game->inv->none[4], NULL);
    if (game->inv->mik == sfFalse)
        sfRenderWindow_drawSprite(game->window, game->inv->none[5], NULL);
}