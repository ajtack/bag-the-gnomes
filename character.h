#ifndef __BG_CHARACTER_CLASS__
#define __BG_CHARACTER_CLASS__

#include "entity.h"

class Character : public Entity
{
public:
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	virtual void draw(BITMAP* screen) = 0;
	
	/*!
	 * \brief Orientation of a character in 8-direction mode.
	 */
	enum Direction
	{
		NORTH,
		NORTHEAST,
		EAST,
		SOUTHEAST,
		SOUTH,
		SOUTHWEST,
		WEST,
		NORTHWEST
	};
	
	/*!
	 * \brief Returns a random direction to the user.
	 */
	static Direction randomDirection();
	
	/*!
	 * \brief Creates a character at the given location.
	 *
	 * \param x_pos_ is the X position of the sprite's top-left corner.
	 * \param y_pos_ is the Y position of the sprite's top-left corner.
	 * \param orientation is optional; can indicate the direction the character
	 * 	is facing.
	 */
	Character(int x_pos_, int y_pos_, Direction orientation = SOUTH);

	/*!
	 * \brief Moves the entity (but does not draw) by the indicated
	 * number of pixels.
	 * 
	 * \param dx is the change in X position
	 * \param dy is the change in Y position
	 */
	void move(int dx, int dy);

protected:
	unsigned int x_pos;
	unsigned int y_pos;

	Direction direction;
	
	unsigned int speed;
};

#endif
