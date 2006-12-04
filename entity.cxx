#include "entity.h"
#include "coord.h"

Entity::Entity(MapPosition position) :
	myPosition(position)
{
	// Initializer list
}


MapPosition Entity::getPosition() const
{
	return myPosition;
}


void Entity::move(int dx, int dy)
{
	Coord newCoord = myPosition;
	
	newCoord.x += dx;
	newCoord.y += dy;
	
	myPosition = newCoord;
}