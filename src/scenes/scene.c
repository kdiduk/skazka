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
 * \file        scenes/scene.c
 * \brief       Implementation of "scene" module.
 * \author      Kirill Diduk
 * \date        14 March 2020, 14:03
 * \copyright   GNU General Public License
 */

#include "scenes/scene.h"
#include "title/title_scene.h"


static enum sceneid current_scene = SCENE_INITIAL;


void scene_update(void)
{
        switch (current_scene) {
                case SCENE_TITLE:
                        title_scene_update();
                        break;
                default:
                        break;
        }
}

void scene_switch(enum sceneid id)
{
        current_scene = id;
}

void scene_push(enum sceneid id)
{
        (void) id;
}

void scene_pop(void)
{
}

/* EOF */
