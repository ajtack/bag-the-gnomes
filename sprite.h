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
 * \brief Wraps together the properties of an animated sprite.
 */
typedef struct Sprite
{
	int x_pos, y_pos;
	int speed;
	Direction direction;
	
	int frame;
	int frameTotal;
	
	int frameDelay;
	int frameDelayCount;
} sprite_t;

#endif
