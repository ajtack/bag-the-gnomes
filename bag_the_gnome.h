#ifndef __BG_HEADER__
#define __BG_HEADER__


/*!
 * \file bag_the_gnome.h
 * \brief A collection of enumerations and constants which unify behavior 
 * in Bag The Gnome, the game.
 *
 * \author: Andres J. Tack
 */

/*!
 * \brief Time waited between each iteration of the game loop.  Use this
 * to control the speed of the game.
 */
#define GAME_LOOP_PERIOD 50

/*!
 * Base movement speed of a gnome in game loop iterations per pixel moved.
 */
#define GNOME_SPEED 3

/*!
 * Base movement speed of a game character in game loop iterations
 * per pixel moved.
 */
#define GARDENER_SPEED 2


#endif
