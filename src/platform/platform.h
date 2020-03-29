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

#include <stdbool.h>


/*!
 * \brief       Initialize the module `platform`.
 *
 * \details     This function shoud be called before any other calls
 *      to the functions from `platform` module, i.e. any functions from
 *      the header files in the `platform` subdirectory. In case of success,
 *      this function returns true. In case of error this function returns
 *      false. In both cases at the end of the program the module should
 *      be deinitialized with function platform_shutdown().
 *
 * \return      true in case of success or false in case of error
 * \sa          platform_shutdown()
 */
bool platform_init(void);


/*!
 * \brief       Function to update internal state of the module `platform`.
 *
 * \details     This function is called periodically from the main game loop
 *      to update all internal structures of the module `platform` and all
 *      it's submodules such as input handling, screen handling, etc.
 *      In the main game-loop this function is called before updating the
 *      game logic.
 *      Apart from updating the module, this function takes care of delay
 *      for synchronizing the frames, i.e. a call to this function will block
 *      so that between two calls to this function there should proper time
 *      period to maintain constant FPS. On SDL platform this is done by
 *      measuring the time elapsed and delaying. On ZX Spectrum platform
 *      this is done by waiting for an interrupt which is 50 times per second
 *      on that platform.
 */
void platform_update(void);


/*!
 * \brief       De-initialize (shut-down) the module `platform`.
 *
 * \details     This function should be called if the function platform_init()
 *      was called. This is usually done before the program exit. Even if
 *      platform_init() returned false, this functions should be called.
 */
void platform_shutdown(void);


#endif /* SKAZKA_PLATFORM_H */

/* EOF */
