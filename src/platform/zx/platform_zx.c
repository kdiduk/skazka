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
 * \file        platform/zx/platform_zx.c
 *
 * \brief       Implementation of platform-abstraction layer for ZX Spectrum.
 * \author      Kirill Diduk (kirill.diduk@mail.ru)
 * \date        21 March 2020, 21:57
 * \copyright   GNU General Public License
 */

#include "platform/platform.h"


bool platform_init(void)
{
        return true;
}

void platform_update(void)
{
}

void platform_shutdown(void)
{
}

/* EOF */
