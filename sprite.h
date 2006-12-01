/*!
 * \file sprite.h
 * \brief Declares structures which facilitate the use of sprites in the game.
 *
 * \author: Andres J. Tack
 */
#ifndef __SPRITE_H__
#define __SPRITE_H__

/*!
 * \brief Orientation of a character in 4-direction mode.
 */
enum Direction
{
	SOUTH,
	WEST,
	EAST,
	NORTH
};


/*!
 * \brief An X,Y coordinate pair.
 */
typedef struct Coord
{
	int x;	/*!< Y coordinate of the point. */
	int y;	/*!< X coordinate of the point. */
} Coord_t;


/*!
 * \brief Wraps together the properties of an animated sprite.
 */
typedef struct Sprite
{
	int image_w;	/*!< The width of the sprite's image. */
	int image_h;	/*!< The height of the sprite's image. */
	
	struct Coord position;	/*!< The position of this sprite with respect to the screen. */
	int speed;	/*!< The speed in pixels/moving frame */
	Direction direction;	/*!< The heading of the sprite. */
	
	int frame;	/*!< The current frame of animation. */
	int frameTotal;	/*!< The total frames of animation available. */
	
	int frameDelay;	/*!< The number of frames to delay before animating. */
	int frameDelayCount;	/*!< A counter for delaying frames. */
} sprite_t;

#endif
