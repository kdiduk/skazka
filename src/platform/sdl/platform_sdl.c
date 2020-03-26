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

#include "platform/sdl/pinput_sdl.h"
#include "platform/platform.h"


SDL_Window* window = NULL;
SDL_Surface* screen = NULL;


bool platform_init(void)
{
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
                return false;
        }

        window = SDL_CreateWindow("Skazka",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                256*3,
                192*3,
                SDL_WINDOW_SHOWN);
        if (window == NULL) {
                SDL_Log("Could not create window: %s\n", SDL_GetError());
                return false;
        }

        screen = SDL_GetWindowSurface(window);
        if (screen == NULL) {
                SDL_Log("Could not get window surface: %s\n", SDL_GetError());
                return false;
        }

        Uint32 color = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF);
        SDL_FillRect(screen, NULL, color);

        return true;
}


void platform_update(void)
{
        SDL_UpdateWindowSurface(window);
        SDL_Delay(20);
        pinput_sdl_update();
}


void platform_shutdown(void)
{
        if (window != NULL) {
                SDL_DestroyWindow(window);
                window = NULL;
        }

        SDL_Quit();
}

/* EOF */
