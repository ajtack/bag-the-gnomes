/*!
 * \file bag_the_gnome.h
 * \brief A collection of enumerations and constants which unify behavior 
 * in Bag The Gnome, the game.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_HEADER__
#define __BG_HEADER__

#include "square_map.h"

/*!
 * \brief Time waited between each iteration of the game loop.  Use this
 * to control the speed of the game.
 */
#define GAME_LOOP_PERIOD 20


/*!
 * \brief Initializes and returns a pointer to the correct map for 
 * the given level.
 * 
 * \param level The level number (beginning with 1)
 * 
 * \return Pointer to an initialized map.
 */
SquareMap* map_for_level(int level);


#endif
