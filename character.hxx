/*!
 * \class Character
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
#ifndef __BG_CHARACTER_CLASS__
#define __BG_CHARACTER_CLASS__

#include "map_position.hxx"
#include "entity.hxx"
#include "sprite.hxx"


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
	Character(MapPosition position, Direction dir_ = SOUTH);
	
	/*!
	 * \brief Set the direction of the character.
	 */
	virtual void setDirection(Direction dir_);
	
	/*!
	 * \brief Set the speed of the character.
	 */
	virtual void setSpeed(int speed_);
	
	/*!
	 * \brief Updates the position and other internal attributes of the
	 * character according to last known direction, speed, frame delay,
	 * and position.
	 * 
	 * This method does not actually draw the character to the screen.
	 */
	virtual void update();
	
	
	/*!
	 * \brief Tells whether the character (or subclass) can pass over
	 * the given terrain type.
	 * 
	 * \param terrain is the type of terrain being tested against this Character.
	 * 
	 * \return true if the given terrain type is passable, otherwise
	 * false.
	 */
	virtual bool canPass(Tile::TerrainType terrain);
	
	
	/*!
	 * \brief Collision-detection for Character sprites
	 * 
	 * \param otherGuy is who we are testing for collisions
	 * 
	 * \return true if this Character is colliding with otherGuy.
	 * false otherwise.
	 */
	virtual bool collidesWith(Character* otherGuy);

protected:
	Sprite mySprite;
};

#endif
