/*!
 * \file character.cxx
 * \brief Implementation for the abstract Character class.
 *
 * \author: Andres J. Tack
 */
#include "character.h"
#include "sprite.h"
#include <stdlib.h>
#include <time.h>


Character::Character(struct Coord position, Direction dir_)
{
	mySprite.position = position;
	mySprite.direction = dir_;
}


Coord_t Character::getPosition() const
{
	return mySprite.position;
}


void Character::move(int dx, int dy)
{
	mySprite.position.x += dx;
	mySprite.position.y += dy;
}


void Character::setDirection(Direction dir_)
{
	mySprite.direction = dir_;
}


void Character::setSpeed(int speed_)
{
	mySprite.speed = speed_;
}


void Character::update()
{
	++mySprite.frameDelayCount;
	
	// Wait for the frame delay to resolve (slows drawing down)
	if (mySprite.frameDelayCount >= mySprite.frameDelay)
	{
		mySprite.frameDelayCount = 0;
		
		// Don't move if we're stopped.
		if (mySprite.speed != 0)
		{
			mySprite.frame = (mySprite.frame + 1) % mySprite.frameTotal;
			
			if (mySprite.direction == NORTH)
				mySprite.position.y -= mySprite.speed;
			else if (mySprite.direction == SOUTH)
				mySprite.position.y += mySprite.speed;
			else if (mySprite.direction == EAST)
				mySprite.position.x += mySprite.speed;
			else
				mySprite.position.x -= mySprite.speed;
		}
	}
}


Direction Character::randomDirection()
{
	return Direction(rand() % 4);
}
