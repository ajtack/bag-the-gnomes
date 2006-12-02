/*!
 * \class Entity
 * \brief Any drawn "thing" on the screen implements this interface.
 * 
 * An entity is always located on a map.
 * 
 * \author Andres J. Tack
 */
#ifndef __BG_ENTITY_CLASS__
#define __BG_ENTITY_CLASS__

#include <allegro.h>
#include "map_position.h"

class Entity
{
public:
	/*!
	 * \brief Constructs an entity belonging to a particular map.
	 * 
	 * \param setMap The map where this entity lives.
	 */
	Entity(MapPosition position);
	
	/*!
	 * \brief Gets the position of this entity
	 * 
	 * \return A copy of this entity's position.
	 */
	MapPosition getPosition() const;
	
	/*!
	 * \brief Moves the entity (but does not draw) by the indicated
	 * number of pixels.
	 * 
	 * \param dx is the change in X position
	 * \param dy is the change in Y position
	 */
	void move(int dx, int dy);
	
	/*!
	 * \brief Draws the entity to the given bitmap screen.
	 * 
	 * \param screen is where the entity will be drawn to.
	 */
	virtual void draw(BITMAP* screen) = 0;
	
protected:
	MapPosition myPosition;	/*!< The map on which this Entity appears. */
};

#endif
