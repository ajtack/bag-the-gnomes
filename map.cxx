#include "images.hxx"
#include "map.hxx"
#include "square_tile.hxx"
#include <allegro.h>
#include <stdlib.h>
#include <string.h>


BITMAP* Map::theirImageSource = NULL;


Map::Map(int rows_p, int cols_p)	{
	this->myNumRows = rows_p;
	this->myNumCols = cols_p;
	
	// Allocate pointers for the rows
	this->myTiles = new Row[rows_p];
	
	// For each row, construct an array of tiles per the 
	// number of columns
	for(int row = 0; row < myNumRows; row++)
	{
		this->myTiles[row] = new SquareTile*[myNumCols];
		memset(this->myTiles[row], NULL, myNumCols * sizeof(SquareTile*));
	}
		
	// Prepare the tiles image
	if (theirImageSource == NULL)
		theirImageSource = load_bitmap(TILE_IMAGE_PATH, NULL);
	myBuffer = create_bitmap(640, 480);
	refreshBuffer();
	myBufferNeedsRefresh = false;
}


void Map::blit(BITMAP* screen)
{
	if (myBufferNeedsRefresh)
		refreshBuffer();
		
	// Blit the entire buffer to the screen
	::blit(myBuffer, screen, 0, 0, 0, 0, myBuffer->w, myBuffer->h);
}


void Map::refreshBuffer()
{
	// Select the appropriate image to use for each tile and blit it individually
	// to a buffer.
	for(int rownum = 0; rownum < myNumRows; rownum++)
	{
		for (int colnum = 0; colnum < myNumCols; colnum++)
		{
			SquareTile* tile = myTiles[rownum][colnum];
			int imageX, imageY;	// Pixel location of the map tile
			
			// Find height of tile
			if (tile == NULL)
			{
				imageX = 0;
				imageY = TERRAIN_DIRT_ROW * TILE_HEIGHT;
			}
			else
			{
				imageX = tile->neighborCode() * TILE_WIDTH;
				
				switch (tile->getTerrainType())
				{
					case Tile::StoneWall:
						imageY = TERRAIN_STONE_WALL_ROW * TILE_HEIGHT;
						break;
					case Tile::Grass:
						imageY = TERRAIN_GRASS_ROW * TILE_HEIGHT;
						break;
					case Tile::Plant:
						imageY = TERRAIN_PLANT_ROW * TILE_HEIGHT;
						break;
					default:
					case Tile::Dirt:
						imageY = TERRAIN_DIRT_ROW * TILE_HEIGHT;
						break;
				}
			}
			
			// Blit the tile to the map.
			int destX = TILE_WIDTH * colnum;
			int destY = TILE_HEIGHT * rownum;
			::blit(theirImageSource, myBuffer, imageX, imageY, destX, destY, TILE_WIDTH, TILE_HEIGHT);
		}
	}
	
	myBufferNeedsRefresh = false;
}


int Map::getColumns() const
{
	return myNumCols;
}


int Map::getRows() const
{
	return myNumRows;
}


ManhattanDistance Map::getPixelDimensions() const
{
	return ManhattanDistance(myNumCols * TILE_WIDTH, myNumRows * TILE_HEIGHT);
}


const Tile* Map::tileAtPixelCoordinates(Coord coords) const
{
	int tileX = coords.x / TILE_WIDTH;
	int tileY = coords.y / TILE_HEIGHT;
	
	return myTiles[tileY][tileX];
}


void Map::addTileAtIndex(SquareTile* tile, int row, int col)	{
	// Remove an existing tile
	if (myTiles[row][col] != NULL)
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
		
	myBufferNeedsRefresh = true;
}


void Map::removeTileAtIndex(int row, int col)	{
	delete myTiles[row][col];
	myBufferNeedsRefresh = true;
}
