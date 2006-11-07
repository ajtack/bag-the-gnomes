#ifndef __BG_GARDENER_CLASS__
#define __BG_GARDENER_CLASS__

#include "character.h"

#include <allegro.h>

class Gardener : public Character
{
public:
	Gardener(int x_pos_, int y_pos_, Character::Direction orientation = SOUTH);
	
	~Gardener();
	
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	void draw(BITMAP* screen);
	
private:
	BITMAP* mySprite;
};

#endif
