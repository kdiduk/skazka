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
#include "platform/platform.h"


/*! Border size that simulates the ZX Spectrum's border */
#define BORDER_SIZE     (32)

/*! Horizontal screen resolution in pixels, according to ZX Spectrum */
#define RESOLUTION_X    (256)

/*! Vertical screen resolution in pixels, according to ZX Spectrum */
#define RESOLUTION_Y    (192)

/*! Scale of the window initial size relative to resolution */
#define WINDOW_SCALE    (2)

static const char* WINDOW_TITLE = "Skazka";


SDL_Window      *window         = NULL;
SDL_Surface     *screen         = NULL;
SDL_Renderer    *renderer       = NULL;


static bool init_sdl(void);
static bool init_window(void);
static bool init_renderer(void);


bool platform_init(void)
{
        if (init_sdl() == false) {
                return false;
        }

        if (init_window() == false) {
                return false;
        }

        Uint32 color = SDL_MapRGB(screen->format, 0xD7, 0xD7, 0xD7);
        SDL_FillRect(screen, NULL, color);

        if (init_renderer() == false) {
                return false;
        }

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, NULL);

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
        if (renderer != NULL) {
                SDL_DestroyRenderer(renderer);
                renderer = NULL;
        }

        if (window != NULL) {
                SDL_DestroyWindow(window);
                window = NULL;
        }
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


static bool init_window(void)
{
        window = SDL_CreateWindow(WINDOW_TITLE,
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                (RESOLUTION_X + 2*BORDER_SIZE) * WINDOW_SCALE,
                (RESOLUTION_Y + 2*BORDER_SIZE) * WINDOW_SCALE,
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

        return true;
}


static bool init_renderer(void)
{
        renderer = SDL_CreateSoftwareRenderer(screen);
        if (renderer == NULL) {
                SDL_Log("Could note create renderer: %s\n", SDL_GetError());
                return false;
        }

        SDL_Rect rect;
        rect.x = (BORDER_SIZE) * WINDOW_SCALE;
        rect.y = (BORDER_SIZE) * WINDOW_SCALE;
        rect.w = RESOLUTION_X * WINDOW_SCALE;
        rect.h = RESOLUTION_Y * WINDOW_SCALE;
        SDL_RenderSetViewport(renderer, &rect);

        return true;
}


/* EOF */
