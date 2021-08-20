/*
** EPITECH PROJECT, 2021
** init_game.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

sfBool is_door_locked(game_t *game, int i)
{
    if (i == 0 && game->key[0]->status == sfTrue)
        return (sfFalse);
    if (i == 3 && game->key[1]->status == sfTrue)
        return (sfFalse);
    if (i == 7 && game->key[2]->status == sfTrue)
        return (sfFalse);
    if (i != 0 && i != 3 && i != 7)
        return (sfFalse);
    else
        return (sfTrue);
}

void init_rain(map_t *map)
{
    sfTexture *rain_texture = sfTexture_createFromFile("assets/Images/"
        "rain.png", NULL);
    sfVector2f scale = {3.14, 3.14};
    sfVector2f pos = {0, 0};

    map->rain = sfSprite_create();
    sfSprite_setTexture(map->rain, rain_texture, sfFalse);
    sfSprite_setScale(map->rain, scale);
    sfSprite_setPosition(map->rain, pos);
    map->rect_rain = create_int_rect(0, 0, 512, 271);
    map->rain_status = sfFalse;
    map->clock = sfClock_create();
}

sfVector2f create_first_pos(float x, float y)
{
    sfVector2f ret = {0, 0};

    ret.x = x * 3;
    ret.y = y * 3;
    return (ret);
}

void init_trees(map_t *map)
{
    sfTexture *texture = sfTexture_createFromFile("assets/Images/tree.png",
        NULL);

    map->nb_trees = 6;
    map->tree = malloc(sizeof(tree_t *) * map->nb_trees);

    for (int i = 0; i < map->nb_trees; i++) {
        map->tree[i] = malloc(sizeof(tree_t));
        map->tree[i]->sprite = sfSprite_create();
        sfSprite_setScale(map->tree[i]->sprite, map->scale);
        sfSprite_setTexture(map->tree[i]->sprite, texture, sfFalse);
    }
    map->tree[0]->first_pos = create_first_pos(264, 480);
    map->tree[1]->first_pos = create_first_pos(528, 504);
    map->tree[2]->first_pos = create_first_pos(1224, 744);
    map->tree[3]->first_pos = create_first_pos(1632, 696);
    map->tree[4]->first_pos = create_first_pos(1656, 720);
    map->tree[5]->first_pos = create_first_pos(648, 984);
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->texture = sfTexture_createFromFile("assets/Images/map.png", NULL);
    map->rain_t = sfTexture_createFromFile("assets/Images/map2.png", NULL);
    map->sprite = sfSprite_create();
    sfSprite_setTexture(map->sprite, map->texture, sfFalse);
    map->scale.x = 3;
    map->scale.y = 3;
    sfSprite_setScale(map->sprite, map->scale);
    map->pos.x = -1000;
    map->pos.y = -1000;
    sfSprite_setPosition(map->sprite, map->pos);
    map->hitbox = sfImage_createFromFile("assets/Images/map_binaire.png");
    init_trees(map);
    init_rain(map);
    return (map);
}