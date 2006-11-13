/*!
 * \file character.cxx
 * \brief Implementation for the abstract Character class.
 *
 * \author: Andres J. Tack
 */
#include "character.h"
#include <stdlib.h>
#include <time.h>


Character::Character(int x_pos_, int y_pos_, Direction dir_)
{
	mySprite.x_pos = x_pos_;
	mySprite.y_pos = y_pos_;
	mySprite.direction = dir_;
}


Coord_t Character::getPosition() const
{
	return (Coord_t) {mySprite.x_pos, mySprite.y_pos};
}


void Character::move(int dx, int dy)
{
	mySprite.x_pos += dx;
	mySprite.y_pos += dy;
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
				mySprite.y_pos -= mySprite.speed;
			else if (mySprite.direction == SOUTH)
				mySprite.y_pos += mySprite.speed;
			else if (mySprite.direction == EAST)
				mySprite.x_pos += mySprite.speed;
			else
				mySprite.x_pos -= mySprite.speed;
		}
	}
}


Direction Character::randomDirection()
{
	return Direction(rand() % 4);
}
