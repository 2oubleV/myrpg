/*
** EPITECH PROJECT, 2021
** game.h
** File description:
** my_defender
*/

#include "my.h"
#include "framebuffer.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define HELP "RPG created with CSFML.\n\n"\
             "USAGE\n"\
             "  ./my_rpg  [-h]\n"\
             "OPTIONS\n"\
             "  -h        print the usage and quit.\n"\
             "USER INTERACTIONS\n"\
             "  ESCAPE    pause the game.\n"\
             "  r         make rain.\n"\
             "  i         open the inventory.\n"

#ifndef defender
#define defender

struct button_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
};
typedef struct button_s button_t;

struct menu_s {
    sfClock *clock;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f scale;
    sfIntRect rect;
    button_t **button;
    sfMusic *sasageyo;
};
typedef struct menu_s menu_t;

struct player_s {
    int speed;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *rain_t;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
    sfClock *clock;
    int mov;
    sfSound *step;
    sfSoundBuffer *step_buff;
};
typedef struct player_s player_t;

struct tree_s {
    sfSprite *sprite;
    sfVector2f first_pos;
    sfVector2f pos;
};
typedef struct tree_s tree_t;

struct map_s {
    sfTexture *texture;
    sfTexture *rain_t;
    sfSprite *sprite;
    sfSprite *rain;
    sfIntRect rect_rain;
    sfBool rain_status;
    sfImage *hitbox;
    sfVector2f scale;
    sfVector2f pos;
    sfClock *clock;
    int nb_trees;
    tree_t **tree;
};
typedef struct map_s map_t;

struct house_s {
    sfTexture *texture;
    sfTexture *rain_t;
    sfSprite *sprite;
    sfImage *hitbox;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f player_pos;
    int id;
};
typedef struct house_s house_t;

struct keys_s {
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f first_pos;
    sfVector2f pos;
    sfBool status;
};
typedef struct keys_s keys_t;

struct inv_s {
    sfSprite **none;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *livai;
    sfSprite *mikasa;
    sfBool liv;
    sfBool mik;
};
typedef struct inv_s inv_t;

typedef struct
{
    int hp;
    int max_hp;
    int power_on_cd;
    float dmg_reduc;
    char *desc;
    sfVector2f pos;
    sfTexture *tex;
    sfSprite *m_spr;
    sfSprite *spr;
    sfRectangleShape *hp_bar;
    sfClock *anim_clock;
} s_data;

typedef struct
{
    sfRenderWindow *win;
    sfSprite *map;
    sfRectangleShape *back;
    sfFont *code_font;
    sfText *vs_text;
    sfSprite *turn_arrow;
    sfEvent event;
    int index;
    int show_menu;
    int menu_index;
    sfRectangleShape *selector;
    sfText *menu_content;
    s_data **data;
    int buffer;
    int end;
    button_t *button;
    button_t *final_screen;
} s_game;

struct game_s {
    sfSprite *help;
    sfRenderWindow *window;
    framebuffer_t *fb;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
    float ratio;
    char status;
    map_t *map;
    player_t *player;
    button_t **pause;
    menu_t *menu;
    house_t *house;
    sfMusic *music;
    sfSound *click;
    sfSoundBuffer *click_buff;
    int moving;
    sfVector2f pos;
    keys_t **key;
    sfSound *fkey;
    sfSoundBuffer *fkey_buff;
    inv_t *inv;
};
typedef struct game_s game_t;

// Beggining & end
int main(int argc, char **argv);
int my_rpg(void);
button_t *create_button(char *fp, float x_pos, float y_pos, float scale_xy);
sfIntRect create_int_rect(int left, int top, int width, int height);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void move_rect(sfIntRect *rect, int offset, int max_value, int rect_left);
void destroy_game(game_t *game);
void display_sound_logo(game_t *game);
sfBool end_condition(game_t *game);

// Menu
menu_t *init_menu(void);
void make_menu(game_t *game);
void manage_menu_buttons(game_t *game);

// Game
game_t *init_game(void);
void make_game(game_t *game);
void move_player(game_t *game);
void move_map(game_t *game);

//Player
void rotate_players(game_t *game);
void animate_player(game_t *game);

// Map
map_t *init_map(void);
void make_rain(game_t *game);
keys_t **init_keys(void);
sfVector2f create_first_pos(float x, float y);
sfBool is_door_locked(game_t *game, int i);

//Inventory
inv_t *init_inventory(void);
void make_inventory(game_t *game);

//House
house_t *init_house(void);
void check_home_pos(game_t *game);
void make_house(game_t *game);
sfBool check_collision(game_t *game, sfFloatRect rect);

// Pause
button_t **init_pause(void);
void make_pause(game_t *game);
void manage_pause_buttons(game_t *game);

// Events
void analyse_event(game_t *game);
sfBool is_sprite_clicked(game_t *game, sfSprite *sprite);
void manage_key_pressed(game_t *game);
void manage_key_released(game_t *game);
void manage_music_volume(void);

// Help
void make_help(game_t *game);
void init_help(game_t *game);

// Final combat
void final_game(sfRenderWindow *window, button_t *cursor);
s_data **init_data(void);
void check_input(s_game *game);
void get_next_turn(s_game *game);
void update_player_hp(s_game *game, int index);
int check_winner(s_game *game);
void update_player_hp(s_game *game, int index);
void init_hp_bar(s_data *data, int x, int y);
sfSprite *create_sprite(char *path, int x, int y, float scale);
void play_mob_turn(s_game *game);
sfVector2f create_vector(float x, float y);
void update_animation(s_game *game);
void update_menu(s_game *game);
void final_screen(s_game *game);
void is_sprite_clicked2(s_game *game, sfSprite *sprite);
void manage_mouse_cursor2(s_game *game, button_t *cursor);

#endif /* !defender */
