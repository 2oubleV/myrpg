/*
** EPITECH PROJECT, 2021
** framebuffer.c
** File description:
** Bootstrap my_defender
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include "../include/my.h"

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

#endif
