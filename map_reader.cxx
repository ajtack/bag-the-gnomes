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
		default:	// Default is "dirt"
		case 'd':
			type = Tile::Dirt;
			break;
		case 'g':
			type = Tile::Grass;
			break;
		case 'p':
			type = Tile::Plant;
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
		if (input.bad())
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
		printf("UH OH...\n");
		delete map;
		return NULL;
	}
	
	return map;
}
