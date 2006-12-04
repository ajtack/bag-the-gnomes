/*!
 * \file tile.cpp
 * \brief Tile Class Implementation
 *
 * \author Andres J. Tack
 */
#include "tile.hxx"


Tile::Tile(TerrainType terrain)
{
	this->myTerrainType = terrain;
}


Tile::TerrainType Tile::getTerrainType() const
{
	return this->myTerrainType;
}


void Tile::setTerrainType(TerrainType newTerrain)
{
	this->myTerrainType = newTerrain;
}
