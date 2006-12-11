#include "gnome.hxx"
#include "gnome_food.hxx"
#include "images.hxx"
#include <allegro.h>


BITMAP* Gnome::theirSpriteSheet = NULL;
BITMAP* Gnome::theirBaggedSheet = NULL;
int Gnome::theirBaggedSpriteX = GNOME_BAG_COL * TILE_WIDTH;
int Gnome::theirBaggedSpriteY = GNOME_BAG_ROW * TILE_HEIGHT;


Gnome::Gnome(MapPosition position, Direction orientation, GnomeFood* target) :
	Character(position, orientation)
{
	myHuntedFood = target;
	target->setIsBeingHunted(true);
	
	// Load both images
	char* image_path = "./sprites/gnome_sheet.bmp";
	char* bagged_path = "./maps/tiles.bmp";
	
	if (!theirSpriteSheet)
		theirSpriteSheet = load_bitmap(image_path, NULL);
	if (!theirBaggedSheet)
		theirBaggedSheet = load_bitmap(bagged_path, NULL);
	
	if (!theirSpriteSheet)	{
		allegro_message("Gnome.cxx:18 Couldn't find image: %s\n", image_path);
		return;
	} else if (!theirBaggedSheet) {
		allegro_message("Gnome.cxx:18 Couldn't find image: %s\n", bagged_path);
		return;
	}
	else
	{
		// Magic Number 4 assumes 4 frames of animation; assumed throughout.
		mySprite.image_w = theirSpriteSheet->w / 4;
		mySprite.image_h = theirSpriteSheet->h / 4;
		mySprite.boundingBox = 
			Sprite::BoundingBox(5, mySprite.image_w - 5, 5, mySprite.image_h - 5);
		
		mySprite.frame = 0;
		mySprite.frameTotal = 4;
		mySprite.frameDelay = 5;
		mySprite.frameDelayCount = 0;
		mySprite.speed = 3;
	}
	
	myFreedom = true;
}


void Gnome::draw(BITMAP* screen)
{
	Coord position = myPosition;
	int sourceX, sourceY;
	
	if (myFreedom)	{
		sourceX = mySprite.frame * mySprite.image_w;
		sourceY = mySprite.direction * mySprite.image_h;
		
		masked_blit(theirSpriteSheet, screen, sourceX, sourceY, 
			position.x, position.y, mySprite.image_w, mySprite.image_h);
	} else {
		sourceX = theirBaggedSpriteX;
		sourceY = theirBaggedSpriteY;
		
		masked_blit(theirBaggedSheet, screen, sourceX, sourceY, 
			position.x, position.y, mySprite.image_w, mySprite.image_h);
	}
}


void Gnome::update()
{
	if (myFreedom)
		Character::update();
}


bool Gnome::canPass(Tile::TerrainType terrain)
{
	if (terrain == Tile::StoneWall)
		return false;
	else
		return true;
}


void Gnome::bag()
{
	myFreedom = false;
	mySprite.boundingBox = Sprite::BoundingBox(0, 0, 0, 0);	// Can walk all over this gnome.
}
