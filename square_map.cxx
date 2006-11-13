/*!
 * \file square_map.cpp
 * \brief Square Map Implementation
 *
 * \author Andres J. Tack
 */
#include "square_map.h"
#include "square_tile.h"
#include <stdlib.h>


SquareMap::SquareMap(int rows_p, int cols_p)	{
	this->myNumRows = rows_p;
	this->myNumCols = cols_p;
	
	// Allocate pointers for the rows
	this->myTiles = new Row[rows_p];
	
	// For each row, construct an array of tiles per the 
	// number of columns
	for(int row = 0; row < myNumRows; row++)
		this->myTiles[row] = new SquareTile*[cols_p];
}


int SquareMap::getColumns() const	{
	return myNumCols;
}


int SquareMap::getRows() const	{
	return myNumRows;
}


void SquareMap::addTileAtIndex(SquareTile* tile, int row, int col)	{
	// Remove an existing tile
	if (myTiles[row][col] == NULL)
		delete myTiles[row][col];
		
	myTiles[row][col] = tile;
	
	// Assign neighbors appropriately
	if (row > 0)
		tile->recordNeighbor(SquareTile::NORTH, myTiles[row - 1][col]);
	if (col > 0)
		tile->recordNeighbor(SquareTile::WEST, myTiles[row][col - 1]);
	
	if (row < myNumRows - 1)
		tile->recordNeighbor(SquareTile::SOUTH, myTiles[row + 1][col]);
	if (col < myNumCols - 1)
		tile->recordNeighbor(SquareTile::EAST, myTiles[row][col + 1]);
		
	if (row > 0 && col > 0)
		tile->recordNeighbor(SquareTile::NORTHWEST, myTiles[row - 1][col - 1]);
	if (row > 0 && col < myNumCols - 1)
		tile->recordNeighbor(SquareTile::NORTHEAST, myTiles[row - 1][col + 1]);
		
	if (row < myNumRows - 1 && col > 0)
		tile->recordNeighbor(SquareTile::SOUTHWEST, myTiles[row + 1][col - 1]);
	if (row < myNumRows - 1 && col < myNumCols - 1)
		tile->recordNeighbor(SquareTile::SOUTHEAST, myTiles[row + 1][col + 1]);
}


void SquareMap::removeTileAtIndex(int row, int col)	{
	delete myTiles[row][col];
}


char* SquareMap::serializeNeighbors() const	{
	char* byteString = new char[myNumRows * myNumCols];
	int byteIndex = 0;
	
	// Expensive Operation!  Run through all the rows and all
	// the columns to get each tile's neighbor byte.
	for(int row = 0; row < myNumRows; row++)	{
		for(int col = 0; col < myNumCols; col++)	{
			if (myTiles[row][col] != NULL)
				byteString[byteIndex++] = myTiles[row][col]->serializeNeighbors();
			else
				byteString[byteIndex++] = 'x';
		}
	}
	
	return byteString;
}


char* SquareMap::serializeNeighbors(int * outputSize)	{
	if (outputSize != NULL)
		*outputSize = myNumRows * myNumCols;
	return this->serializeNeighbors();
}
