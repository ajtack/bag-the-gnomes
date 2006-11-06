#ifndef __BG_GNOME_CLASS__
#define __BG_GNOME_CLASS__

#include "character.h"

class Gnome : public Character
{
public:
	Gnome(int x_pos_, int y_pos_, Character::Direction orientation);
	
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	void draw(BITMAP* screen);
};

#endif
