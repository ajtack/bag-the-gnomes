#include "square_tile.h"
#include <stdlib.h>


SquareTile::SquareTile(TerrainType terrain)	: Tile(terrain)	{
	// Clear all neighbors
	for (int n = 0; n < 8; n++)
		this->myNeighbors[n] = NULL;
}


SquareTile::~SquareTile()	{
	// Remove neighbor status to each neighbor
	for (int n = 0; n < 8; n++)	{
		if (this->myNeighbors[n] != NULL)
			this->myNeighbors[n]->forgetNeighbor((SquareTile::Direction) n);
	}
}


void SquareTile::recordNeighbor(SquareTile::Direction direction, 
                                SquareTile::Neighbor* neighbor)	{
	this->myNeighbors[direction] = neighbor;
	
	// Reciprocate the relationship with the neighbor tile.
	if (neighbor != NULL)	{
		Direction opposite_direction = (Direction) ((direction + 4) % 8);
		neighbor->myNeighbors[opposite_direction] = this;
	}
}


void SquareTile::forgetNeighbor(SquareTile::Direction direction)	{
	this->myNeighbors[direction] = NULL;
}


bool SquareTile::neighborHasSameType(SquareTile::Direction direction) const	{
	Neighbor* neighbor = this->myNeighbors[direction];
	
	if (neighbor != NULL)
		return ( neighbor->getTerrainType() == this->getTerrainType() );
	else
		return true;
}


char SquareTile::serializeNeighbors() const	{
	char result = 0x0;		// We will store our final result here.
	
	// Note: We rely on the continuous distribution of enum values in
	// the class.  A change in the declaration of the enumeration will
	// *absolutely* require revisiting this function.
	static SquareTile::Direction firstDir = SquareTile::NORTHWEST;
	static SquareTile::Direction lastDir = SquareTile::WEST;
	
	Neighbor* n;		// Used as a temporary for a neighbor
	for (int bit = firstDir; bit <= lastDir; ++bit)	{
		n = this->myNeighbors[bit];
		
		// If no neighbor specified, skip this one, otherwise shift the
		// correct bit value into our result.
		if (n == NULL)
			continue;
		else
			result |= (this->getTerrainType() != n->getTerrainType()) << bit;
	}
	
	return result;
}
