/*
** EPITECH PROJECT, 2021
** defender.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void init_mob(s_data *data, char *path)
{
    sfVector2f pos = {650, 250};
    sfIntRect rect = {0, 0, 96, 96};

    init_hp_bar(data, 690, 270);
    data->desc = "None\n";
    data->anim_clock = NULL;
    data->pos = pos;
    data->m_spr = create_sprite(path, 1020, 650, 3);
    data->spr = create_sprite(path, 650, 250, 2);
    data->power_on_cd = 0;
    data->hp = 1000;
    data->max_hp = 1000;
    sfSprite_setTextureRect(data->spr, rect);
    sfSprite_setTextureRect(data->m_spr, rect);
}

void init_eren(s_data *data, char *path)
{
    sfVector2f pos = {650, 480};
    sfIntRect rect = {32, 96, 32, 32};
    sfIntRect m_rect = {32, 0, 32, 32};

    init_hp_bar(data, 580, 730);
    data->desc = "Eren :\n\nBasic attack \n\nBoosted attack";
    data->anim_clock = NULL;
    data->pos = pos;
    data->m_spr = create_sprite(path, 600, 760, 2.5);
    data->spr = create_sprite(path, 650, 480, 2);
    data->power_on_cd = 0;
    data->hp = 100;
    data->max_hp = 100;
    sfSprite_setTextureRect(data->spr, rect);
    sfSprite_setTextureRect(data->m_spr, m_rect);
}

void init_mikasa(s_data *data, char *path)
{
    sfVector2f pos = {710, 480};
    sfIntRect rect = {32, 96, 32, 32};
    sfIntRect m_rect = {32, 0, 32, 32};

    init_hp_bar(data, 690, 730);
    data->desc = "Mikasa :\n\nBasic attack\n\nHeal";
    data->anim_clock = NULL;
    data->pos = pos;
    data->m_spr = create_sprite(path, 700, 760, 2.5);
    data->spr = create_sprite(path, 710, 480, 2);
    data->power_on_cd = 0;
    data->hp = 100;
    data->max_hp = 100;
    sfSprite_setTextureRect(data->spr, rect);
    sfSprite_setTextureRect(data->m_spr, m_rect);
}

void init_levi(s_data *data, char *path)
{
    sfVector2f pos = {770, 480};
    sfIntRect rect = {32, 96, 32, 32};
    sfIntRect m_rect = {32, 0, 32, 32};

    init_hp_bar(data, 800, 730);
    data->desc = "Levi :\n\nBasic attack\n\nReduce Damage";
    data->anim_clock = NULL;
    data->pos = pos;
    data->m_spr = create_sprite(path, 800, 760, 2.5);
    data->spr = create_sprite(path, 770, 480, 2);
    data->power_on_cd = 0;
    data->hp = 100;
    data->max_hp = 100;
    sfSprite_setTextureRect(data->spr, rect);
    sfSprite_setTextureRect(data->m_spr, m_rect);
}

s_data **init_data(void)
{
    s_data **new_data = malloc(4 * sizeof(s_data *));

    for (int i = 0; i < 4; i++)
        new_data[i] = malloc(sizeof(s_data));
    init_mob(new_data[0], "assets/Images/mob_sprite.png");
    init_eren(new_data[1], "assets/Images/SNK/eren.png");
    init_mikasa(new_data[2], "assets/Images/SNK/mikasa.png");
    init_levi(new_data[3], "assets/Images/SNK/levi.png");
    return (new_data);
}