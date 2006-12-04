#include "entity.hxx"
#include "gnome_food.hxx"
#include "map_position.hxx"

GnomeFood::GnomeFood(MapPosition &position) :
	Entity(position)
{
	myHasBeenStolen = false;
}
