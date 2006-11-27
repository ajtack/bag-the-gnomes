/*!
 * \file square_map.h
 * \brief Defines the public interface of the SquareMap class.
 *
 * \author: Andres J. Tack
 */
#ifndef __SQUARE_MAP_H__
#define __SQUARE_MAP_H__

#include <allegro.h>
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
	 * \brief Blits the map to the given bitmap.
	 * 
	 * This operation will be complex if the map has just changed.  Otherwise,
	 * results of the draw call are cached.
	 * 
	 * \param screen the bitmap image where this map will be blitted.
	 */
	void blit(BITMAP* screen);
	
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
	
	
private:
	typedef SquareTile** Row;	// Several Square Tiles make a row
	Row* myTiles;            	// Several Rows make a map.
	
	// Stored dimensions of the map
	int myNumRows;
	int myNumCols;

protected:
	/*!
	 * \brief Refreshes all tiles in the map buffer so it can be quickly 
	 * blitted to the screen.
	 */
	void refreshBuffer();

	static BITMAP* theirImageSource;
	BITMAP* myBuffer;           /*!< A temporary buffer to blit a map */
	bool myBufferNeedsRefresh;
};

#endif
