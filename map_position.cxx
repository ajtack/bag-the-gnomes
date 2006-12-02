#include "bag_the_gnome.h"
#include "map_position.h"

MapPosition::MapPosition(const Map* context)
{
	myMap = context;
	myCoordinates = (Coord) {0, 0};
}


MapPosition::MapPosition(const Map* context, Coord coords)
{
	myMap = context;
	myCoordinates = coords;
}


inline Coord MapPosition::getCoordinates() const
{
	return myCoordinates;
}


inline int MapPosition::getX() const
{
	return myCoordinates.x;
}


inline int MapPosition::getY() const
{
	return myCoordinates.y;
}


Tile::TerrainType MapPosition::detectTerrain() const
{
	const Tile* tileUnderMe = myMap->tileAtPixelCoordinates(myCoordinates);
	
	if (tileUnderMe == NULL)
		return theDefaultTerrainType;
	else
		return tileUnderMe->getTerrainType();
}


inline void MapPosition::setCoordinates(Coord newCoords)
{
	myCoordinates = newCoords;
}


inline Coord MapPosition::operator = (const Coord &assignee)
{
	myCoordinates = assignee;
}
