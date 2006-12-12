/*!
 * \file bag_the_gnome.hxx
 * \brief A collection of enumerations and constants which unify behavior 
 * in Bag The Gnome, the game.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_HEADER__
#define __BG_HEADER__

#include "tile.hxx"
class Map;

/*!
 * \brief Time waited between each iteration of the game loop.  Use this
 * to control the speed of the game.
 */
#define GAME_LOOP_PERIOD 10


/*!
 * \brief The default terrain type to use when we have NULL tiles or 
 * other funny things.
 * 
 * \return The default Tile::TerrainType for the game
 */
static const Tile::TerrainType theDefaultTerrainType = Tile::Dirt;


/*!
 * \brief Initializes and returns a pointer to the correct map for 
 * the given level.
 * 
 * \param level The level number (beginning with 1)
 * 
 * \return Pointer to an initialized map.
 */
Map* map_for_level(int level);


#endif
