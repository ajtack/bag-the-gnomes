/*!
 * \file square_map.h
 * \brief Defines the public interface of the SquareMap class.
 *
 * \author: Andres J. Tack
 */
#ifndef __SQUARE_MAP_H__
#define __SQUARE_MAP_H__

#include "square_tile.h"

/*!
 * \brief A map of square terrain tiles.
 */
class SquareMap
{
public:

	/*!
	 * \brief Constructs a SquareMap with the given dimensions
	 * and no tiles.
	 */
	SquareMap(int rows_p, int cols_p);
	
	/*!
	 * \brief Returns the width in columns of this map.
	 */
	int getColumns() const;
	
	/*!
	 * \brief Returns the height in rows of this map.
	 */
	int getRows() const;
	
	/*!
	 * \brief Adds a square tile to the map at the given row and
	 * column index.  Neighboring relationships are 
	 * established automatically.
	 * 
	 * If a tile already existed at the given index, it is
	 * safely destroyed and replaced with the given tile.
	 * 
	 * \param tile is a pointer to a tile being inserted.  No tile is
	 * inserted if this is NULL.
	 * \param row is the row at which to insert the tile.
	 * \param col is the column at which to insert the tile.
	 */
	void addTileAtIndex(SquareTile* tile, int row, int col);

	/*!
	 * \brief Removes the tile (if any) at the given row/col index.
	 * 
	 * All references to this tile in this Map will be exterminated.
	 * If there exists no tile at the given index, nothing
	 * is done.
	 * 
	 * \param row is the row at which to remove a tile.
	 * \param col is the column at which to remove a tile.
	 */
	void removeTileAtIndex(int row, int col);
	
	/*!
	 * \param Creates a bytestring representing the neighboring
	 * tiles for each index of this map.
	 * 
	 * Each tile corresponds to one bit in this output, indexed first
	 * by row, then by column.  The order of bits is as follows, where a
	 * 1 indicates that the neighbor is different; 0 indicates that the
	 * neighbor is the same.
	 * 
	 * BIT	NEIGHBOR
	 * ===	========
	 *  7	WEST
	 *  6	SOUTHWEST
	 *  5	SOUTH
	 *  4	SOUTHEAST
	 *  3	EAST
	 *  2	NORTHEAST
	 *  1	NORTH
	 *  0	NORTHWEST
	 * 
	 * \return a bytestring of length (W * H) of this map, per the
	 * neighboring tiles format.
	 */
	char* serializeNeighbors() const;
	
	/*!
	 * \brief Behaves exactly as SquareMap::serializeNeighbors(),
	 * but also writes the size of the output string to the given
	 * integer.
	 * 
	 * \param outputSize is the size of the character string output
	 * returned by this method.  If NULL, nothing is written to the 
	 * pointer but the bytestring is still returned.
	 * 
	 * \return a bytestring of length (W * H) of this map, per the
	 * neighboring tiles format.
	 */
	char* serializeNeighbors(int * outputSize);
	
	
private:
	typedef SquareTile** Row;	// Several Square Tiles make a row
	Row* myTiles;            	// Several Rows make a map.
	
	// Stored dimensions of the map
	int myNumRows;
	int myNumCols;
};

#endif
