/* ************************************************************************** *

    SPDX-License-Identifier: GPL-3.0-or-later

    Skazka - a game for ZX Spectrum computer.
    Copyright (C) 2020 Kirill Diduk (kirill.diduk@mail.ru)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

* ************************************************************************** */

/*!
 * \file        platform/sdl/pinput_sdl.c
 *
 * \brief       SDL implementation of keyboar input module.
 * \author      Kirill Diduk
 * \date        21 March 2020, 15:32
 * \copyright   GNU General Public License
 */

#include <SDL2/SDL_events.h>
#include <stdbool.h>

#include "platform/pinput.h"
#include "game.h"


static void update_key_pressed(SDL_Event* event, bool pressed);


bool pinput_pressed(enum pinput_key key)
{
        (void) key;

        return false;
}


void pinput_sdl_update(void)
{
        SDL_Event event;

        while (SDL_PollEvent(&event) == 1) {
                if(event.type == SDL_QUIT) {
                        game_quit();
                } else if (event.type == SDL_KEYDOWN) {
                        update_key_pressed(&event, true);
                } else if (event.type == SDL_KEYUP) {
                        update_key_pressed(&event, false);
                }
        }
}


static void update_key_pressed(SDL_Event* event, bool pressed)
{
        (void) event;
        (void) pressed;
}

/* EOF */
