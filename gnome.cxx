/*!
 * \file gnome.cxx
 * \brief Implementation for the Gnome class.
 *
 * \author: Andres J. Tack
 */
#include "gnome.h"
#include <allegro.h>


Gnome::Gnome(int x_pos_, int y_pos_, Direction orientation) :
	Character(x_pos_, y_pos_, orientation)
{
	char* image_path = "./sprites/gnome.bmp";
	mySpriteSheet = load_bitmap(image_path, NULL);
	if (!mySpriteSheet)
	{
		allegro_message("Couldn't find image: %s\n", image_path);
		return;
	}
}


Gnome::~Gnome()
{
	destroy_bitmap(mySpriteSheet);
}


void Gnome::draw(BITMAP* screen)
{
	stretch_blit(mySpriteSheet, screen, 0, 0, mySpriteSheet->w, mySpriteSheet->h, mySprite.x_pos, mySprite.y_pos, 20, 20);
}


void Gnome::update()
{
	
}
