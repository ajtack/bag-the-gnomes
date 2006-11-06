#include "gardener.h"
#include <allegro.h>


Gardener::Gardener(int x_pos_, int y_pos_, Character::Direction orientation) :
	Character(x_pos_, y_pos_, orientation)
{
	// Initializer List
}


void Gardener::draw(BITMAP* screen)
{
	char* image_path = "sprites/farmer.gif";
	BITMAP* image = load_bitmap(image_path, NULL);
	if (!image)
	{
		allegro_message("Couldn't find image: %s\n", image_path);
		return;
	}
	
	blit(image, screen, 0, 0, x_pos, y_pos, image->w, image->h);
}
