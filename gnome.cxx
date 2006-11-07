#include "gnome.h"

#include "character.h"

#include <allegro.h>

Gnome::Gnome(int x_pos_, int y_pos_, Character::Direction orientation) :
	Character(x_pos_, y_pos_, orientation)
{
	char* image_path = "./sprites/gnome.bmp";
	mySprite = load_bitmap(image_path, NULL);
	if (!mySprite)
	{
		allegro_message("Couldn't find image: %s\n", image_path);
		return;
	}
}


Gnome::~Gnome()
{
	destroy_bitmap(mySprite);
}


void Gnome::draw(BITMAP* screen)
{
	stretch_blit(mySprite, screen, 0, 0, mySprite->w, mySprite->h, x_pos, y_pos, 20, 20);
}
