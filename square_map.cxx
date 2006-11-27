/*!
 * \file square_map.cpp
 * \brief Square Map Implementation
 *
 * \author Andres J. Tack
 */
#include "images.h"
#include "square_map.h"
#include "square_tile.h"
#include <allegro.h>
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


void SquareMap::blit(BITMAP* screen)
{
	if (myBufferNeedsRefresh)
		refreshBuffer();
		
	// Blit the entire buffer to the screen
	::blit(myBuffer, screen, 0, 0, 0, 0, myBuffer->w, myBuffer->h);
}


void SquareMap::refreshBuffer()
{
	// Select the appropriate image to use for each tile and blit it individually
	// to a buffer.
	for(int rownum = 0; rownum < myNumRows; rownum++)
	{
		for (int colnum = 0; colnum < myNumCols; colnum++)
		{
			SquareTile* tile = myTiles[rownum][colnum];
			int tileX, tileY;	// Pixel location of the map tile
			
			// Find height of tile
			switch (tile->getTerrainType())
			{
				case Tile::Grass:
					tileY = TERRAIN_GRASS_ROW * TILE_HEIGHT;
					break;
				case Tile::Jungle:
					tileY = TERRAIN_PLANT_ROW * TILE_HEIGHT;
					break;
			}
			
			// Find offset of tile
			tileX = tile->neighborCode() * TILE_WIDTH;
		}
	}
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
}


void SquareMap::removeTileAtIndex(int row, int col)	{
	delete myTiles[row][col];
}
