#include "gardener.h"
#include <allegro.h>


Gardener::Gardener(int x_pos_, int y_pos_, Character::Direction orientation) :
	Character(x_pos_, y_pos_, orientation)
{
	char* image_path = "./sprites/farmer.bmp";
	mySprite = load_bitmap(image_path, NULL);
	if (!mySprite)
	{
		allegro_message("Couldn't find image: %s\n", image_path);
		return;
	}
}


Gardener::~Gardener()
{
	destroy_bitmap(mySprite);
}


void Gardener::draw(BITMAP* screen)
{
	blit(mySprite, screen, 0, 0, x_pos, y_pos, mySprite->w, mySprite->h);
}
