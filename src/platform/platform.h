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
 * \file        platform/platform.h
 *
 * \brief       Platform-abstraction layer functions.
 * \author      Kirill Diduk
 * \date        21 March 2020, 21:43
 * \copyright   GNU General Public License
 */

#ifndef SKAZKA_PLATFORM_H
#define SKAZKA_PLATFORM_H


void platform_init(void);

void platform_update(void);

void platform_shutdown(void);


#endif /* SKAZKA_PLATFORM_H */

/* EOF */
