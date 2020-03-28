/* ************************************************************************** *

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
 * \file        game.h
 *
 * \brief       Interface of "game" module.
 *
 * \details     A top-level module which is responsible for initialization of
 *   other submodules (particularly initializing the platform layer) and run
 *   the main game loop.
 *
 * \author      Kirill Diduk (kirill.diduk@mail.ru)
 * \date        8 March 2020, 20:39
 * \copyright   GNU General Public License
 */

#ifndef SKAZKA_GAME_H
#define SKAZKA_GAME_H

#include <stdbool.h>


/*!
 * \brief       Initializes the game and it's submodules before the run.
 */
bool game_init(void);

/*!
 * \brief       Runs the game main loop.
 */
void game_run(void);

/*!
 * \brief       Function to quit the game in normal mode.
 *
 * \details     This function is normally called by one of the scenes to
 *   finish the game and quit to system. This is a normal mode to quit
 *   the game program. In fact this function ceases the main game loop
 *   and shuts down all the submodules. In other words, it performs a
 *   graceful shutdown.
 *
 */
void game_quit(void);

#endif /* SKAZKA_GAME_H */

/* EOF */
