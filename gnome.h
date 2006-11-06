#ifndef __BG_GNOME_CLASS__
#define __BG_GNOME_CLASS__

#include "character.h"

class Gnome : public Character
{
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	void draw(BITMAP* screen);
};

#endif
