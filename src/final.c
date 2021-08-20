/*
** EPITECH PROJECT, 2021
** defender.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-antoine.podvin
*/

#include "../include/game.h"

void render_game(s_game *game, s_data **data, button_t *cursor)
{
    if (game->end == 0) {
        sfRenderWindow_drawSprite(game->win, game->map, NULL);
        sfRenderWindow_drawRectangleShape(game->win, game->back, NULL);
        sfRenderWindow_drawText(game->win, game->vs_text, NULL);
        sfRenderWindow_drawSprite(game->win, game->turn_arrow, NULL);
        if (game->show_menu == 1 && game->index != 0) {
            sfRenderWindow_drawRectangleShape(game->win, game->selector, NULL);
            sfRenderWindow_drawText(game->win, game->menu_content, NULL);
        }
        for (int i = 0; i < 4; i++) {
            sfRenderWindow_drawSprite(game->win, data[i]->m_spr, NULL);
            sfRenderWindow_drawSprite(game->win, data[i]->spr, NULL);
            sfRenderWindow_drawRectangleShape(game->win, data[i]->hp_bar, NULL);
        }
    } else {
        sfRenderWindow_drawSprite(game->win, game->final_screen->sprite, NULL);
        sfRenderWindow_drawSprite(game->win, game->button->sprite, NULL);
        sfRenderWindow_drawSprite(game->win, cursor->sprite, NULL);
    }
}

void init_game_ui(s_game *game)
{
    sfVector2f pos = {950, 750};
    sfVector2f txt_pos = {250, 740};
    sfVector2f selector_pos = {240, 760};
    sfVector2f selector_size = {250, 30};

    game->code_font = sfFont_createFromFile("assets/Fonts/code.ttf");
    game->turn_arrow = create_sprite("assets/Images/arrow_d.png", 0, 0, 0.15);
    game->menu_content = sfText_create();
    game->selector = sfRectangleShape_create();
    game->vs_text = sfText_create();
    sfText_setPosition(game->menu_content, txt_pos);
    sfText_setFont(game->menu_content, game->code_font);
    sfText_setCharacterSize(game->menu_content, 15);
    sfText_setFont(game->vs_text, game->code_font);
    sfText_setCharacterSize(game->vs_text, 50);
    sfText_setString(game->vs_text, "VS");
    sfText_setPosition(game->vs_text, pos);
    sfRectangleShape_setFillColor(game->selector, sfBlack);
    sfRectangleShape_setPosition(game->selector, selector_pos);
    sfRectangleShape_setSize(game->selector, selector_size);
}

s_game *init_final_game(void)
{
    sfColor grey = {112, 111, 108, 255};
    sfTexture *tex = sfTexture_createFromFile("assets/Images/map.png", NULL);
    s_game *new_game = malloc(sizeof(s_game));

    new_game->map = sfSprite_create();
    new_game->back = sfRectangleShape_create();
    new_game->index = 0;
    new_game->menu_index = 0;
    sfSprite_setTexture(new_game->map, tex, sfFalse);
    sfRectangleShape_setFillColor(new_game->back, grey);
    sfRectangleShape_setPosition(new_game->back, create_vector(0, 700));
    sfRectangleShape_setSize(new_game->back, create_vector(1500, 150));
    sfSprite_setPosition(new_game->map, create_vector(-1670, -1450));
    sfSprite_setScale(new_game->map, create_vector(3, 3));
    init_game_ui(new_game);
    new_game->end = 0;
    return (new_game);
}

void manage_event(s_game *game, button_t *cursor)
{
    while (sfRenderWindow_pollEvent(game->win, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->win);
        if (game->end == 0) {
            if (game->event.type == sfEvtKeyPressed) {
                if (game->event.key.code == sfKeyEnter && game->show_menu == 1)
                    check_input(game);
                if (game->event.key.code == sfKeyUp ||
                    game->event.key.code == sfKeyDown)
                    update_menu(game);
            }
        } if (game->end != 0 && game->event.type == sfEvtMouseButtonPressed)
            is_sprite_clicked2(game, game->button->sprite);
        if (game->event.type == sfEvtMouseMoved)
            manage_mouse_cursor2(game, cursor);
    }
}

void final_game(sfRenderWindow *window, button_t *cursor)
{
    s_game *game = init_final_game();
    s_data **data = init_data();
    unsigned int seed = malloc(sizeof(int));

    game->win = window;
    srand(seed);
    game->data = data;
    get_next_turn(game);
    while (sfRenderWindow_isOpen(game->win)) {
        update_animation(game);
        manage_event(game, cursor);
        if (game->index == 0)
            play_mob_turn(game);
        if (check_winner(game) != 0)
            final_screen(game);
        sfRenderWindow_clear(game->win, sfBlack);
        render_game(game, data, cursor);
        sfRenderWindow_display(game->win);
    }
}