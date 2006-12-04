#include "bag_the_gnome.h"
#include "map_position.h"

MapPosition::MapPosition(const Map* context) :
	myCoordinates(0, 0)
{
	myMap = context;
}


MapPosition::MapPosition(const Map* context, Coord coords) :
	myCoordinates(coords.x, coords.y)
{
	myMap = context;
}


MapPosition::MapPosition(const MapPosition &original) :
	myCoordinates(original.myCoordinates.x, original.myCoordinates.y)
{
	myMap = original.myMap;
	myCoordinates = original.myCoordinates;
}


Coord MapPosition::getCoordinates() const
{
	return myCoordinates;
}


Tile::TerrainType MapPosition::detectTerrain() const
{
	const Tile* tileUnderMe = myMap->tileAtPixelCoordinates(myCoordinates);
	
	if (tileUnderMe == NULL)
		return theDefaultTerrainType;
	else
		return tileUnderMe->getTerrainType();
}


void MapPosition::setCoordinates(Coord newCoords)
{
	myCoordinates = newCoords;
}


Coord MapPosition::operator = (const Coord &assignee)
{
	myCoordinates = assignee;
}


MapPosition::operator Coord ()
{
	return myCoordinates;
}
