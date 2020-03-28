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
 * \file        platform/pscreen.h
 *
 * \brief       Platform-independent screen-related functions.
 * \author      Kirill Diduk (kirill.diduk@mail.ru)
 * \date        28 March 2020, 13:51
 * \copyright   GNU General Public License
 */

#ifndef SKAZKA_PLATFORM_SCREEN_H
#define SKAZKA_PLATFORM_SCREEN_H


enum pcolor_ink {
        PCOLOR_INK_BLACK        = 0x00,
        PCOLOR_INK_BLUE         = 0x01,
        PCOLOR_INK_RED          = 0x02,
        PCOLOR_INK_MAGENTA      = 0x03,
        PCOLOR_INK_GREEN        = 0x04,
        PCOLOR_INK_CYAN         = 0x05,
        PCOLOR_INK_YELLOW       = 0x06,
        PCOLOR_INK_WHITE        = 0x07
};


void pscreen_border(enum pcolor_ink color);


#endif /* SKAZKA_PLATFORM_SCREEN_H */

/* EOF */
