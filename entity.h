#ifndef __BG_ENTITY_CLASS__
#define __BG_ENTITY_CLASS__

#include <allegro.h>

class Entity
{
public:
	/*!
	 * \brief Draws the entity to the given bitmap screen.
	 * 
	 * \param screen is where the entity will be drawn to.
	 */
	virtual void draw(BITMAP* screen) = 0;
};

#endif
