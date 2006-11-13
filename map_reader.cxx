/*!
 * \file map_reader.h
 * \brief Implements the MapReader class.
 *
 * \sa
 * map_reader.h
 *
 * \author: Andres J. Tack
 */
#include "map_reader.h"
#include "square_map.h"
#include "square_tile.h"
#include "tile.h"
#include <iostream>


/*!
 * \brief Converts an input character to the corresponding tile type.
 */
Tile::TerrainType convertToTileType(char c)	{
	Tile::TerrainType type;
	
	switch(c)	{
		case 'g':
			type = Tile::Grass;
			break;
		case 'd':
			type = Tile::Desert;
			break;
		case 'i':
			type = Tile::Ice;
			break;
		case 'j':
			type = Tile::Jungle;
			break;
		case 'p':
			type = Tile::Plain;
			break;
		case 's':
			type = Tile::Swamp;
			break;
		case 'r':
			type = Tile::Road;
			break;
		case 'w':
			type = Tile::Water;
			break;
		case 'h':
			type = Tile::Hotrock;
			break;
		case 'f':
			type = Tile::Forest;
			break;
		case 'm':
			type = Tile::Mountain;
			break;
		default:
			type = Tile::Grass;
			break;
	}
	
	return type;
}



SquareMap* MapReader::MakeSquareMap(std::istream & input)
{
	// Read the dimensions of the map and create a new instance.
	unsigned short int numRows, numCols;
	char* buffer = new char[20];
	
	input.getline(buffer, 20); 	// Get the number of rows
	numRows = atoi(buffer);
	input.getline(buffer, 20); 	// Get the number of columns
	numCols = atoi(buffer);
	
	SquareMap *map = new SquareMap(numRows, numCols);
	char* inputRow = new char[numCols + 2];	// Enough space for \n and \r\n
	
	for (int row = 0; row < numRows; row++)
	{	
		// Check to be sure the file hasn't ended prematurely=
		if (input.eof())
		{
			delete map;
			return NULL;
		}
		
		input.getline(inputRow, numCols + 2);
		
		// Create a tile for each column
		SquareTile* tile;
		Tile::TerrainType type;
		for(int col = 0; col < numCols; col++)
		{
			type = convertToTileType(inputRow[col]);
			tile = new SquareTile(type);
			
			map->addTileAtIndex(tile, row, col);
		}
	}
	
	// Check for possible file corruption
	if (!input.eof())
	{
		delete map;
		return NULL;
	}
	
	return map;
}
