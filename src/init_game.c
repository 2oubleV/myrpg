/*
** EPITECH PROJECT, 2021
** init_game.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

house_t *init_house(void)
{
    house_t *house = malloc(sizeof(house_t));
    sfVector2f origin = {100, 113};

    house->texture = sfTexture_createFromFile(
        "assets/Images/interior_house.png", NULL);
    house->sprite = sfSprite_create();
    sfSprite_setTexture(house->sprite, house->texture, sfFalse);
    house->scale.x = 3;
    house->scale.y = 3;
    sfSprite_setScale(house->sprite, house->scale);
    sfSprite_setOrigin(house->sprite, origin);
    house->pos.x = 750;
    house->pos.y = 425;
    sfSprite_setPosition(house->sprite, house->pos);
    house->hitbox = sfImage_createFromFile(
        "assets/Images/interior_house_binaire.png");
    house->player_pos.x = 723;
    house->player_pos.y = 670;
    return (house);
}

void init_player2(player_t *player)
{
    player->mov = 0;
    player->step = sfSound_create();
    player->step_buff = sfSoundBuffer_createFromFile("assets/Sounds/step.ogg");
    sfSound_setBuffer(player->step, player->step_buff);
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->speed = 2;
    player->texture = sfTexture_createFromFile("assets/Images/SNK/Pack/Eren"
        ".png", NULL);
    player->rain_t = sfTexture_createFromFile("assets/Images/SNK/Pack/Eren2"
        ".png", NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    player->pos.x = 734;
    player->pos.y = 409;
    sfSprite_setPosition(player->sprite, player->pos);
    player->scale.x = 2;
    player->scale.y = 2;
    sfSprite_setScale(player->sprite, player->scale);
    player->rect = create_int_rect(0, 0, 27, 32);
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->clock = sfClock_create();
    init_player2(player);
    return (player);
}

void init_game2(game_t *game)
{
    game->menu = init_menu();
    game->house = init_house();
    game->key = init_keys();
    game->fkey_buff = sfSoundBuffer_createFromFile("assets/Sounds/heal.ogg");
    game->fkey = sfSound_create();
    sfSound_setVolume(game->fkey, 20);
    sfSound_setBuffer(game->fkey, game->fkey_buff);
    game->inv = init_inventory();
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {1500, 850, 32};

    game->window = sfRenderWindow_create(mode, "MyRPG", sfDefaultStyle, NULL);
    game->status = 'm';
    game->fb = framebuffer_create(1920, 1080);
    game->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    game->click = sfSound_create();
    game->click_buff = sfSoundBuffer_createFromFile("assets/Sounds/click.ogg");
    sfSound_setBuffer(game->click, game->click_buff);
    game->pos.x = -1000;
    game->pos.y = -1000;
    game->map = init_map();
    game->player = init_player();
    game->pause = init_pause();
    init_game2(game);
    return (game);
}
