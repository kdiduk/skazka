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
 * \file        platform/sdl/window.h
 *
 * \brief       Header file with functions of the module `window`.
 * \details     The module `window` is an internal module of the module
 *       `platform`. This module implements main SDL window of the game app.
 * \author      Kirill Diduk (kirill.diduk@mail.ru)
 * \date        04 April 2020, 18:59
 * \copyright   GNU General Public License
 */

#ifndef SKAZKA_PLATFORM_SDL_WINDOW_H
#define SKAZKA_PLATFORM_SDL_WINDOW_H

#include <stdbool.h>


bool window_create(void);

void window_update(void);

void window_resize(int x, int y);

void window_destroy(void);


#endif /* SKAZKA_PLATFORM_SDL_WINDOW_H */

/* EOF */
