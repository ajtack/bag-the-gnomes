/*!
 * \file character.hxx
 * \brief Declares the Character class.
 * 
 * \author Andres J. Tack
 */
#ifndef __BG_CHARACTER_CLASS__
#define __BG_CHARACTER_CLASS__

#include "map_position.hxx"
#include "entity.hxx"
#include "sprite.hxx"

/*!
 * \class Character
 * \brief Defines an abstract, mobile character in the game.
 * 
 * This class is abstract, and subclasses are required to overload the
 * draw method, per the Entity class declaration.  Subclasses are also
 * required to overload the update() function, defined as a characteristic
 * of a mobile character.
 */
class Character : public Entity
{
public:
	
	/*!
	 * \brief Returns a random direction to the user.
	 */
	static Direction randomDirection();
	
	/*!
	 * \brief Creates a character at the given location.
	 *
	 * \param position is the starting position of the character
	 * \param dir_ is optional; can indicate the direction the character
	 * 	is facing.
	 */
	Character(MapPosition &position, Direction dir_ = SOUTH);
	
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
	virtual bool canPass(Tile::TerrainType terrain) const;
	
	
	/*!
	 * \brief Collision-detection for Character sprites
	 * 
	 * \param otherGuy is who we are testing for collisions
	 * 
	 * \return true if this Character is colliding with otherGuy.
	 * false otherwise.
	 */
	virtual bool collidesWith(Character* otherGuy) const;

protected:
	Sprite mySprite;	/*!< Sprite used to animate the character */
	
private:
	/*!
	 * \brief Performs the same function as canPass, but test a specific
	 * set of bounding box corners depending on the direction of the sprite.
	 * 
	 * \bug Characters must all be able to pass on GnomeHole terrain or
	 * Gnomes cannot leave the holes.  How do we get this to refer to
	 * canPass() method in children?
	 * 
	 * \param position the base position of the sprite to test
	 * 
	 * \return true if the bounding box of this sprite does not extend into
	 * unpassable terrain.  false otherwise.
	 */
	bool boundingBoxCanPass(MapPosition &position) const;
};

#endif
