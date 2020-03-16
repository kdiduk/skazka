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
 * \file        main.c
 * \brief       Contains entry-point function main() of "Skazka" game.
 * \author      Kirill Diduk
 * \date        08 March, 2020
 * \copyright   GNU General Public License
 */

#include "game.h"
#include <stdlib.h>

int main(void)
{
        game_init();
        game_run();

        return EXIT_SUCCESS;
}

/* EOF */
