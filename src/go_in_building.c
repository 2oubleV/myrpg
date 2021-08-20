/*
** EPITECH PROJECT, 2025
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
** File description:
** Created by William,
*/

#include "../include/game.h"

int check_hitbox_house(game_t *game, int tmp_x, int tmp_y)
{
    int x = tmp_x - 142;
    int y = tmp_y - 8;
    int color = sfColor_toInteger(sfImage_getPixel(game->house->hitbox, x, y));

    if (color != 255 && game->player->mov != 0)
        rotate_players(game);
    return (color);
}

void move_player_house(game_t *game)
{
    int x = game->house->player_pos.x;
    int y = game->house->player_pos.y;

    if (game->player->mov == 1 &&
        check_hitbox_house(game, x / 3, (y - 6) / 3) != 255)
        game->house->player_pos.y -= game->player->speed;
    if (game->player->mov == 2 &&
        check_hitbox_house(game, x / 3, (y + 6) / 3) != 255)
        game->house->player_pos.y += game->player->speed;
    if (game->player->mov == 3 &&
        check_hitbox_house(game, (x - 6) / 3, y / 3) != 255)
        game->house->player_pos.x -= game->player->speed;
    if (game->player->mov == 4 &&
        check_hitbox_house(game, (x + 6) / 3, y / 3) != 255)
        game->house->player_pos.x += game->player->speed;
    animate_player(game);
    sfSprite_setPosition(game->player->sprite, game->house->player_pos);
}

void make_house(game_t *game)
{
    move_player_house(game);
    sfRenderWindow_drawSprite(game->window, game->house->sprite, NULL);
    if (game->house->id == 3) {
        sfRenderWindow_drawSprite(game->window, game->inv->livai, NULL);
        game->inv->liv = sfTrue;
    } if (game->house->id == 7) {
        sfRenderWindow_drawSprite(game->window, game->inv->mikasa, NULL);
        game->inv->mik = sfTrue;
    }
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    if (game->house->player_pos.y > 675) {
        make_rain(game);
        game->status = 'g';
        game->pos.y -= 4;
    }
}

sfBool check_entry_house(game_t *game, int x, int y)
{
    if (game->pos.x < x && game->pos.x > x - 72)
        if (game->pos.y < y + 10 && game->pos.y > y - 10)
            return (sfTrue);
    return (sfFalse);
}

void check_home_pos(game_t *game)
{
    int p[8][2] = {{-1124, -692}, {-2132, -620}, {-1700, -1196}, {172, -2492},
        {-1202, -2132}, {-2350, -1844}, {-4224, -2204}, {-4438, -1700}};

    for (int i = 0; i < 8; i++) {
        if (check_entry_house(game, p[i][0], p[i][1]) == sfTrue) {
            if (is_door_locked(game, i) == sfFalse) {
                game->status = 'h';
                game->house->id = i;
                break;
            }
        }
    }
}
