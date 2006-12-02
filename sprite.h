/*!
 * \file sprite.h
 * \brief Declares structures which facilitate the use of sprites in the game.
 *
 * \author: Andres J. Tack
 */
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "coord.h"

/*!
 * \brief Directions that entities can face.
 */
enum Direction
{
	SOUTH,
	WEST,
	EAST,
	NORTH
};

/*!
 * \brief Wraps together the properties of an animated sprite.
 */
class Sprite
{
public:
	int image_w;	/*!< The width of the sprite's image. */
	int image_h;	/*!< The height of the sprite's image. */
	
	int speed;	/*!< The speed in pixels/moving frame */
	Direction direction;	/*!< The heading of the sprite. */
	
	int frame;	/*!< The current frame of animation. */
	int frameTotal;	/*!< The total frames of animation available. */
	
	int frameDelay;	/*!< The number of frames to delay before animating. */
	int frameDelayCount;	/*!< A counter for delaying frames. */
};

#endif
