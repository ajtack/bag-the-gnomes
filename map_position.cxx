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


MapPosition::MapPosition(const MapPosition &original)
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
