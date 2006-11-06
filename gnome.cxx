#include "gnome.h"

#include "character.h"

#include <allegro.h>

Gnome::Gnome(int x_pos_, int y_pos_, Character::Direction orientation) :
	Character(x_pos_, y_pos_, orientation)
{
	// Initialization List
}

void Gnome::draw(BITMAP* screen)
{
	char* image_path = "./sprites/gnome.bmp";
	BITMAP* image = load_bitmap(image_path, NULL);
	if (!image)
	{
		allegro_message("Couldn't find image: %s\n", image_path);
		return;
	}
	
	stretch_blit(image, screen, 0, 0, image->w, image->h, x_pos, y_pos, 20, 20);
	destroy_bitmap(image);
}
