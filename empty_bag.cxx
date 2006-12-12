/*!
 * \file empty_bag.cxx
 * \brief Implementation for the EmptyBag class.
 */
#include "empty_bag.hxx"
#include "coord.hxx"
#include "images.hxx"
#include "sprite.hxx"

BITMAP* EmptyBag::theirSpriteSheet = NULL;
int EmptyBag::theirSpriteX = GNOME_BAG_COL * TILE_WIDTH;
int EmptyBag::theirSpriteY = GNOME_BAG_ROW * TILE_HEIGHT;


EmptyBag::EmptyBag(MapPosition &position) :
	Entity(position)
{
	char* image_path = "./maps/tiles.bmp";
	if (!theirSpriteSheet)
	{
		theirSpriteSheet = load_bitmap(image_path, NULL);
	}
		
	if (!theirSpriteSheet)
	{
		allegro_message("Snail.cxx:18 Couldn't find image: %s\n", image_path);
		return;
	}
	else
	{
		mySprite.image_w = TILE_WIDTH;
		mySprite.image_h = TILE_HEIGHT;
		mySprite.boundingBox = Sprite::BoundingBox(0, 0, 0, 0);
	}
}


void EmptyBag::draw(BITMAP* screen)
{
	Coord position = myPosition.getCoordinates();
	
	masked_blit(theirSpriteSheet, screen, theirSpriteX, theirSpriteY, 
		position.x, position.y, mySprite.image_w, mySprite.image_h);
}
