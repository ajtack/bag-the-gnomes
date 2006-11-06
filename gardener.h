#ifndef __BG_GARDENER_CLASS__
#define __BG_GARDENER_CLASS__

#include "character.h"

class Gardener : public Character
{
public:
	Gardener(int x_pos_, int y_pos_, Character::Direction orientation = SOUTH);
	
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	void draw(BITMAP* screen);
};

#endif
