#include "gardener.h"
#include <allegro.h>
#include <cstdio>


#define GARDENER_WIDTH 32
#define GARDENER_HEIGHT 48


Gardener::Gardener(struct Coord position, Direction dir_) :
	Character(position, dir_)
{
	char* image_path = "./sprites/farmer_sheet.bmp";
	mySpriteSheet = load_bitmap(image_path, NULL);
	if (!mySpriteSheet)
	{
		allegro_message("Gnome.cxx:18 Couldn't find image: %s\n", image_path);
		return;
	}
	else
	{
		mySprite.image_w = mySpriteSheet->w / 4;
		mySprite.image_h = mySpriteSheet->h / 4;
		mySprite.frame = 0;
		mySprite.frameTotal = 4;
		mySprite.frameDelay = 3;
		mySprite.frameDelayCount = 0;
		mySprite.speed = GARDENER_SPEED;
	}
}


void Gardener::draw(BITMAP* screen)
{
	int sourceX = mySprite.frame * mySprite.image_w;
	int sourceY = mySprite.direction * mySprite.image_h;
	
	masked_blit(mySpriteSheet, screen, sourceX, sourceY, 
		mySprite.position.x, mySprite.position.y, mySprite.image_w, mySprite.image_h);
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
