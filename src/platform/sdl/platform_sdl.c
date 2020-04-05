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
 * \file        platform/sdl/platform_sdl.c
 *
 * \brief       Implementation of platform-abstraction layer using SDL.
 * \author      Kirill Diduk (kirill.diduk@mail.ru)
 * \date        21 March 2020, 21:49
 * \copyright   GNU General Public License
 */

#include <SDL2/SDL.h>
#include <stdlib.h>

#include "platform/sdl/pinput_sdl.h"
#include "platform/sdl/window.h"
#include "platform/platform.h"
#include "game.h"


static bool init_sdl(void);
static void update_events(void);
static void update_window_event(SDL_WindowEvent* event);


bool platform_init(void)
{
        if (init_sdl() == false) {
                return false;
        }

        if (window_create() == false) {
                return false;
        }

        return true;
}


void platform_update(void)
{
        window_update();
        update_events();
        SDL_Delay(20);
}


void platform_shutdown(void)
{
        window_destroy();
}


static bool init_sdl(void)
{
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
                return false;
        }

        if (atexit(SDL_Quit) != 0) {
                SDL_Log("Failed to set up `atexit()` function\n");
                SDL_Quit();
                return false;
        }

        return true;
}


static void update_events(void)
{
        SDL_Event event;
        while (SDL_PollEvent(&event) == 1) {
                switch (event.type) {
                        case SDL_QUIT:
                                game_quit();
                                break;
                        case SDL_KEYDOWN:
                        case SDL_KEYUP:
                                pinput_sdl_update(&event.key);
                                break;
                        case SDL_WINDOWEVENT:
                                update_window_event(&event.window);
                                break;
                }
        }
}


void update_window_event(SDL_WindowEvent* event)
{
        switch (event->event) {
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                        window_resize(event->data1, event->data2);
                        break;
                case SDL_WINDOWEVENT_CLOSE:
                        game_quit();
                        break;
        }
}


/* EOF */
