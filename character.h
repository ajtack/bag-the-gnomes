/*!
 * \file character.h
 * \brief Defines the Character class and its members.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_CHARACTER_CLASS__
#define __BG_CHARACTER_CLASS__

#include "entity.h"
#include "sprite.h"


/*!
 * \brief Defines an abstract, mobile character in the game.
 * 
 * This class is abstract, and subclasses are required to overload the
 * draw method, per the Entity class declaration.  Subclasses are also
 * required to overload the update() function, defined as a characteristic
 * of a mobile character.
 * 
 * \sa
 * Entity
 */
class Character : public Entity
{
public:
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	virtual void draw(BITMAP* screen) = 0;
	
	/*!
	 * \brief Returns a random direction to the user.
	 */
	static Direction randomDirection();
	
	/*!
	 * \brief Creates a character at the given location.
	 *
	 * \param x_pos_ is the X position of the sprite's top-left corner.
	 * \param y_pos_ is the Y position of the sprite's top-left corner.
	 * \param speed_ is the maximum speed in pixels/frame of the character.
	 * \param dir_ is optional; can indicate the direction the character
	 * 	is facing.
	 */
	Character(int x_pos_, int y_pos_, Direction dir_ = SOUTH);

	/*!
	 * \brief Moves the entity (but does not draw) by the indicated
	 * number of pixels.
	 * 
	 * \param dx is the change in X position
	 * \param dy is the change in Y position
	 */
	void move(int dx, int dy);
	
	/*!
	 * \brief Set the direction of the character.
	 */
	void setDirection(Direction dir_);
	
	/*!
	 * \brief Set the speed of the character.
	 */
	void setSpeed(int speed_);
	
	/*!
	 * \brief Updates the position and other internal attributes of the
	 * character according to last known direction, speed, frame delay,
	 * and position.
	 * 
	 * This method does not actually draw the character to the screen.
	 */
	void update();

protected:
	struct Sprite mySprite;
};

#endif
