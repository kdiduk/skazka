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
 * \file        platform/zx/pinput_zx.c
 *
 * \brief       ZX Spectrum implementation of keyboar input module.
 * \author      Kirill Diduk
 * \date        21 March 2020, 15:31
 * \copyright   GNU General Public License
 */

#include "platform/pinput.h"


bool pinput_pressed(enum pinput_key key)
{
        (void) key;

        return false;
}

/* EOF */
