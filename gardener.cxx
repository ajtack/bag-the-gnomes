#include "gardener.hxx"
#include "gnome.hxx"
#include <allegro.h>
#include <iostream>


#define GARDENER_WIDTH 32
#define GARDENER_HEIGHT 48


Gardener::Gardener(MapPosition position, Direction dir_) :
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
		// Magic number 4 = 4 frames, assumed throughout
		mySprite.image_w = mySpriteSheet->w / 4;
		mySprite.image_h = mySpriteSheet->h / 4;
		mySprite.boundingBox = Sprite::BoundingBox(8, mySprite.image_w - 8, 15, mySprite.image_h - 9);
		
		mySprite.frame = 0;
		mySprite.frameTotal = 4;
		mySprite.frameDelay = GARDENER_FRAME_DELAY;
		mySprite.frameDelayCount = 0;
		mySprite.speed = GARDENER_SPEED;
	}
}


void Gardener::draw(BITMAP* screen)
{
	int sourceX = mySprite.frame * mySprite.image_w;
	int sourceY = mySprite.direction * mySprite.image_h;
	Coord position = myPosition;
	
	masked_blit(mySpriteSheet, screen, sourceX, sourceY, 
		position.x, position.y, mySprite.image_w, mySprite.image_h);
}


void Gardener::setSpeed(int speed_)
{
	if (speed_ == 0)
		mySprite.speed = 0;
	else
		mySprite.speed = GARDENER_SPEED;
}


void Gardener::bag(Gnome* gnome)
{
	if (gnome != NULL)
		gnome->bag();
		
	--myBagsLeft;
}


bool Gardener::canBag(Gnome* gnome) const
{
	return this->collidesWith(gnome);
}


int Gardener::getBagsLeft() const
{
	return myBagsLeft;
}
