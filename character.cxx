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
#include <iostream>

Character::Character(MapPosition position, Direction dir_) :
	Entity(position)
{
	mySprite.direction = dir_;
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
		Coord newCoord = myPosition.getCoordinates();
		
		// Don't move if we're stopped.
		if (mySprite.speed != 0)
		{
			mySprite.frame = (mySprite.frame + 1) % mySprite.frameTotal;
			
			if (mySprite.direction == NORTH)
				newCoord.y -= mySprite.speed;
			else if (mySprite.direction == SOUTH)
				newCoord.y += mySprite.speed;
			else if (mySprite.direction == EAST)
				newCoord.x += mySprite.speed;
			else
				newCoord.x -= mySprite.speed;
		}
		
		
		// Check whether terrain is now passable
		MapPosition newPosition(myPosition);
		newPosition = newCoord;
		std::cout << this->canPass(newPosition.detectTerrain()) << std::endl;
		if (this->canPass(newPosition.detectTerrain()))
			myPosition = newCoord;
	}
}


Direction Character::randomDirection()
{
	return Direction(rand() % 4);
}


bool Character::canPass(Tile::TerrainType terrain)
{
	switch(terrain)
	{
		case Tile::Grass:
		case Tile::Dirt:
			return true;
		case Tile::Plant:
			return false;
	}
}
