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
 * \file        scenes/scene.h
 *
 * \brief       Interface of "scene" module.
 *
 * \details     Scene module implements a mechanism for organizing
 *   high-level game logic as a set of scenes, and switching between them.
 *   Each individual scene is a kind of game screen.
 *   For example, title screen scene, in-level scene, battle scene, etc.
 *   Scene module works as a finite-state machine. In essens it works more
 *   or less as a "State" design pattern from "Gang of Four" book.
 *   Individual scenes represent states. Switching between scenes (states)
 *   are done by the scenes themselves. In general, any scene may switch
 *   to any other scene, however none of the scenes may "know" the details
 *   of implementation of any other scene. Scenes only may know about
 *   existence of each other through the enum sceneid.
 *
 * \author      Kirill Diduk
 * \date        14 March 2020, 13:07
 * \copyright   GNU General Public License
 */

#ifndef SKAZKA_SCENE_H
#define SKAZKA_SCENE_H


/*!
 * \brief       An enum containing identifiers of game scenes.
 */
enum sceneid {
        /*! Marker enum to be assigned to the initial scene's identifier. */
        SCENE_INITIAL = 0,

        /*! Title screen scene. */
        SCENE_TITLE = SCENE_INITIAL,

        /*! A sentinel identifier to keep count of enum values. */
        MAX_SCENES
};


/*!
 * \brief       Updates current active scene.
 *
 * \details     This function is periodically called in the game loop.
 *   In essence it delegates the call to the update function of the
 *   current active scene which was previously set by scene_switch() call.
 *
 * \sa          scene_switch(enum sceneid)
 */
void scene_update(void);

/*!
 * \brief       Switch the current scene to a new one.
 *
 * \details     This function changes the current scene to the given one.
 *   The following calls to scene_update() will be applied to this new scene.
 *   This function doesn't save the previous scene as scene_push() does.
 *
 * \note        In the beginning before this function is called,
 *   the current scene is SCENE_INITIAL.
 *
 * \param [in]  id      Identifier of the new scene to be set.
 * \sa          scene_upate()
 * \sa          scene_push()
 */
void scene_switch(enum sceneid id);

/*!
 * \brief       Pushes the current scene onto stack and sets the new scene.
 *
 * \details     This functions works similarly to scene_switch() but before
 *   changing the current scene, it preserves it by pushing it onto a stash.
 *   Later on, the preserved scene can be set as the current one by calling
 *   the function scene_pop().
 *
 * \param [in]  id      Identifier of the new scene to be set.
 */
void scene_push(enum sceneid id);

/*!
 * \brief       Pops the top scene from the stack and sets it as the current.
 *
 * \details     This function removes the latest scene from the stack, which
 *   was pushed with scene_push() call, and sets it as the current scene.
 *
 * \sa          scene_push()
 */
void scene_pop(void);


#endif /* SKAZKA_SCENE_H */

/* EOF */
