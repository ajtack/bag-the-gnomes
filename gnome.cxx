#include "gnome.hxx"
#include <allegro.h>


BITMAP* Gnome::theirSpriteSheet = NULL;


Gnome::Gnome(MapPosition position, Direction orientation) :
	Character(position, orientation)
{
	char* image_path = "./sprites/gnome_sheet.bmp";
	if (!theirSpriteSheet)
	{
		theirSpriteSheet = load_bitmap(image_path, NULL);
	}
	
	if (!theirSpriteSheet)
	{
		allegro_message("Gnome.cxx:18 Couldn't find image: %s\n", image_path);
		return;
	}
	else
	{
		// Magic Number 4 assumes 4 frames of animation; assumed throughout.
		mySprite.image_w = theirSpriteSheet->w / 4;
		mySprite.image_h = theirSpriteSheet->h / 4;
		mySprite.boundingBox = Sprite::BoundingBox(5, mySprite.image_w - 5, 5, mySprite.image_h - 5);
		
		mySprite.frame = 0;
		mySprite.frameTotal = 4;
		mySprite.frameDelay = 5;
		mySprite.frameDelayCount = 0;
		mySprite.speed = 3;
	}
}


void Gnome::draw(BITMAP* screen)
{
	int sourceX = mySprite.frame * mySprite.image_w;
	int sourceY = mySprite.direction * mySprite.image_h;
	Coord position = myPosition;
	
	masked_blit(theirSpriteSheet, screen, sourceX, sourceY, 
		position.x, position.y, mySprite.image_w, mySprite.image_h);
}


bool Gnome::canPass(Tile::TerrainType terrain)
{
	if (terrain == Tile::StoneWall)
		return false;
	else
		return true;
}
