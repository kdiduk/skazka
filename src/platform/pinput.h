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
 * \file        platform/pinput.h
 *
 * \brief       Platform-independent keyboard input handling.
 * \author      Kirill Diduk
 * \date        18 March 2020, 21:15
 * \copyright   GNU General Public License
 */

#ifndef SKAZKA_PLATFORM_INPUT_H
#define SKAZKA_PLATFORM_INPUT_H

#include <stdbool.h>


/*!
 * \brief       Keyboard keys.
 */
enum pinput_key {
        INKEY_CAPS,
        INKEY_SYMBOL,
        INKEY_ENTER,
        INKEY_SPACE,

        INKEY_A,  INKEY_B,  INKEY_C,  INKEY_D,  INKEY_E,  INKEY_F,  INKEY_G,
        INKEY_H,  INKEY_I,  INKEY_J,  INKEY_K,  INKEY_L,  INKEY_M,  INKEY_N,
        INKEY_O,  INKEY_P,  INKEY_Q,  INKEY_R,  INKEY_S,  INKEY_T,  INKEY_U,
        INKEY_V,  INKEY_W,  INKEY_X,  INKEY_Y,  INKEY_Z,

        INKEY_0,  INKEY_1,  INKEY_2,  INKEY_3,  INKEY_4,
        INKEY_5,  INKEY_6,  INKEY_7,  INKEY_8,  INKEY_9,

        /*! A sentinel identifier to keep count of enum values. */
        MAX_INPUT_KEYS
};


/*!
 * \brief       Returns true if a key is pressed.
 */
bool pinput_pressed(enum pinput_key key);


#endif /* SKAZKA_PLATFORM_INPUT_H*/

/* EOF */
