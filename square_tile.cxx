#include "square_tile.hxx"
#include <stdlib.h>


int SquareTile::NumberOfDirections = 4;


SquareTile::SquareTile(TerrainType terrain)	: Tile(terrain)	{
	// Clear all neighbors
	for (int n = 0; n < NumberOfDirections; n++)
		this->myNeighbors[n] = NULL;
}


SquareTile::~SquareTile()
{
	// Remove neighbor status to each neighbor
	for (int n = 0; n < NumberOfDirections; n++)
	{
		if (this->myNeighbors[n] != NULL)
			this->myNeighbors[n]->forgetNeighbor((SquareTile::Direction) n);
	}
}


void SquareTile::recordNeighbor(SquareTile::Direction direction, 
                                SquareTile::Neighbor* neighbor)
{
	this->myNeighbors[direction] = neighbor;
	
	// Reciprocate the relationship with the neighbor tile.
	if (neighbor != NULL)
	{
		Direction opposite_direction = (Direction) 
			((direction + (NumberOfDirections / 2)) % NumberOfDirections);
		neighbor->myNeighbors[opposite_direction] = this;
	}
}


void SquareTile::forgetNeighbor(SquareTile::Direction direction)
{
	this->myNeighbors[direction] = NULL;
}


bool SquareTile::neighborHasSameType(SquareTile::Direction direction) const
{
	Neighbor* neighbor = this->myNeighbors[direction];
	
	if (neighbor != NULL)
		return ( neighbor->getTerrainType() == this->getTerrainType() );
	else
		return true;
}


char SquareTile::neighborCode() const
{
	char result = 0x0;		// We will store our final result here.
	
	// Note: We rely on the continuous distribution of enum values in
	// the class.  A change in the declaration of the enumeration will
	// *absolutely* require revisiting this function.
	
	Neighbor* n;
	
	for (int bit = 0; bit < NumberOfDirections; ++bit)
	{		
		if (!this->neighborHasSameType((Direction) bit))
		 	result |= 1 << bit;
	}
	
	return result;
}
