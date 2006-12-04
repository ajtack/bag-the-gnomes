/*!
 * \class Tile
 * \brief One graphic tile, theoretically part of a map or other 
 * aggregation of graphic tiles.
 * 
 * Every tile *must* define 
 * a terrain as a trait inherent to a tile. The only 
 * constructors provided support this innate 
 * characteristic of a Tile. The Terrain enumeration 
 * provides the terrain types which may define a Tile instance.
 *
 * \author Andres J. Tack
 */
#ifndef __TILE__
#define __TILE__


class Tile
{
public:

	/*!
	 * \brief Describes the type of Tile represented by this instance
	 * as a specific terrain.
	 */
	enum TerrainType	{
		Grass, Dirt, Plant, StoneWall, GnomeHole
	};
	
	
	/*!
	 * \brief Constructs a Tile with knowledge of its terrain type.
	 * 
	 * \param terrain is the terrain type of this tile
	 */
	Tile(TerrainType terrain);
	
	
	/*!
	 * \brief Retrieve the Terrain Type of this Tile.
	 * 
	 * \return the Terrain Type of this tile, no exceptions.
	 */
	TerrainType getTerrainType() const;
	
	
	/*!
	 * \brief Sets the terrain type of this tile to the given value.
	 * 
	 * \param newTerrain is the new terrain type for this tile.
	 */
	void setTerrainType(TerrainType newTerrain);
		
	
private:
	TerrainType myTerrainType;       /*!< The terrain type of this tile. */
};

#endif
