/*!
 * \file snail.cxx
 * \brief Implementation for the Snail class.
 */
#include <allegro.h>
#include "gnome_food.hxx"
#include "images.hxx"
#include "snail.hxx"

BITMAP* Snail::mySpriteSheet = NULL;

Snail::Snail(MapPosition &position) :
	GnomeFood(position)
{
	char* image_path = "./maps/tiles.bmp";
	if (!mySpriteSheet)
	{
		mySpriteSheet = load_bitmap(image_path, NULL);
	}
		
	if (!mySpriteSheet)
	{
		allegro_message("Snail.cxx:18 Couldn't find image: %s\n", image_path);
		return;
	}
	else
	{
		mySprite.image_w = TILE_WIDTH;
		mySprite.image_h = TILE_HEIGHT;
		mySprite.boundingBox = Sprite::BoundingBox(5, mySprite.image_w - 5, 8, mySprite.image_h - 8);
	}
}


void Snail::draw(BITMAP* screen)
{
	int sourceX = 16 * TILE_WIDTH;
	int sourceY = 5 * TILE_HEIGHT;
	Coord position = myPosition;
	
	masked_blit(mySpriteSheet, screen, sourceX, sourceY, 
		position.x, position.y, mySprite.image_w, mySprite.image_h);
}
