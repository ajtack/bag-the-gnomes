/*!
 * \file square_tile.h
 * \brief Defines the interface to the SquareTile class.
 *
 * \author: Andres J. Tack
 */
#ifndef __SQUARE_TILE_H__
#define __SQUARE_TILE_H__

#include "tile.h"

/*!
 * \brief A class representing a tile with eight neighbors.
 * 
 * The neighbors of this tile occur N, NE, E, SE, S, SW, W, and NW.
 * Neighbors are remembered in a very naive way: it only matters if
 * the neighbor is of the same terrain type or a different one.
 */
class SquareTile : public Tile
{
protected:	
	typedef SquareTile Neighbor;

public:

	/*!
	 * \brief Enumerates the directions in which a neighbor
	 * may occur.
	 */
	enum Direction	{
		WEST = 7,
		SOUTHWEST = 6,
		SOUTH = 5,
		SOUTHEAST = 4,
		EAST = 3,
		NORTHEAST = 2,
		NORTH = 1,
		NORTHWEST = 0
	};


	/*!
	 * \brief Constructs a SquareTile instance with a Terrain Type
	 * and no explicit neighbors.
	 */
	SquareTile(TerrainType terrain);

	/*!
	 * \brief Destroys the current instance and also removes itself
	 * from the neighbor lists of all neighboring SquareTiles.
	 */
	~SquareTile();

	/*!
	 * \brief Preserves a reference in this instance to a neighbor
	 * in the given direction.
	 * 
	 * This neighbor may be NULL, in which case this tile assumes NO 
	 * neighbor.  If the given neighbor is not a null pointer, this 
	 * tile will also make a call to the neighbor's "recordNeighbor" 
	 * method in the opposite direction.  By this method, a symmetric 
	 * neighbor relationship is created between two tiles.
	 * 
	 * \param direction is the direction relative to
	 *             this instance of the neighboring tile.
	 * \param neighbor is the tile which neighbors this
	 *             Tile and whose terrain type will be checked.
	 */
	void recordNeighbor(Direction direction, Neighbor* neighbor);


	/*!
	 * \brief Removes any reference to a neighbor in the given
	 * direction for the current instance.
	 */
	void forgetNeighbor(Direction direction);


	/*!
	 * \brief Returns whether the neighboring tile in the given
	 * direction is of the same type as this tile or not.
	 * 
	 * The default value for any neighbor that has not been
	 * explicitly attached is 'false', where we assume this
	 * instance is the only tile of its kind in the neighborhood.
	 * Default values will be reported as normal values,
	 * without any note that they may not be intentional
	 * or true.
	 * 
	 * \param direction is the direction of the neighbor whose 
	 *  sameness we wish to know.
	 * 
	 * \return true if this neighbor is of a different type or is unspecified.
	 *  false if this neighbor has the same terrain type.
	 */
	bool neighborHasSameType(Direction direction) const;


	/*!
	 * \brief Return an eight-bit char value (a byte) where each bit specifies
	 * that the neighbor at that position has (0) the same terrain
	 * or (1) not the same terrain as this instance.
	 * 
	 * The order of bits is as follows:
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
	 * \return an eight-bit character written per the properties of this tile.
	 */
	char serializeNeighbors() const;

private:
	Neighbor* myNeighbors[8];
};

#endif
