/*!
 * \file character.cxx
 * \brief Implementation for the abstract Character class.
 *
 * \author: Andres J. Tack
 */
#include "character.h"


Character::Character(int x_pos_, int y_pos_, Direction dir_)
{
	mySprite.x_pos = x_pos_;
	mySprite.y_pos = y_pos_;
	mySprite.direction = dir_;
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


Direction Character::randomDirection()
{
	return Direction(rand() % 4);
}
