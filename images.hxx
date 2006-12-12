/*!
 * \file images.hxx
 * \brief Central location for storing images used throughout the application.
 * 
 * This file defines a set of macros which control which images are used for
 * different entities or sprites throughout the game.  Changing an entry here
 * should be reflected throughout the rest of the program.
 * 
 * \author Andres J. Tack
 */

#ifndef __IMAGES_H__
#define __IMAGES_H__

#define TILE_IMAGE_PATH "./maps/tiles.bmp"
#define TILE_WIDTH 30
#define TILE_HEIGHT 30
#define TERRAIN_GRASS_ROW 1
#define TERRAIN_PLANT_ROW 4
#define TERRAIN_DIRT_ROW 7
#define TERRAIN_STONE_WALL_ROW 9
#define TERRAIN_GNOME_HOLE_ROW 3

#define GNOME_BAG_COL 19
#define GNOME_BAG_ROW 7

#endif
