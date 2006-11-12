#include "gardener.h"
#include <allegro.h>
#include <cstdio>


#define GARDENER_WIDTH 32
#define GARDENER_HEIGHT 48


Gardener::Gardener(int x_pos_, int y_pos_, Direction dir_) :
	Character(x_pos_, y_pos_, dir_)
{
	mySpriteSheet = load_bitmap("./sprites/farmer_sheet.bmp", NULL);
	mySprite.frame = 0;
	mySprite.frameTotal = 4;
	mySprite.frameDelay = 3;
	mySprite.frameDelayCount = 0;
	mySprite.speed = 3;
}


void Gardener::draw(BITMAP* screen)
{
	int sourceX = mySprite.frame * GARDENER_WIDTH;
	int sourceY = mySprite.direction * GARDENER_HEIGHT;
	
	masked_blit(mySpriteSheet, screen, sourceX, sourceY, 
		mySprite.x_pos, mySprite.y_pos, GARDENER_WIDTH, GARDENER_HEIGHT);
}


void Gardener::setSpeed(int speed_)
{
	if (speed_ == 0)
		mySprite.speed = 0;
	else
		mySprite.speed = GARDENER_SPEED;
}


void Gardener::update()
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
