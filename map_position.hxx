/*!
 * \class MapPosition
 * \brief Encapsulates information about an entity's position on a map.
 *
 * \author: Andres J. Tack
 */
#ifndef __MAP_POSITION_H__
#define __MAP_POSITION_H__

#include "coord.hxx"
#include "tile.hxx"
class Map;

class MapPosition
{
public:
	/*!
	 * \brief Establishes a map position at 0x0 in context of the 
	 * given map.
	 * 
	 * \param context the map where this may be located.
	 */
	MapPosition(const Map* context);
	
	/*!
	 * \brief Establishes a specific map position, including the context.
	 * 
	 * \param context the map where this position makes sense.
	 * \param coords the coordinate of the position.
	 */
	MapPosition(const Map* context, Coord coords);
	
	/*!
	 * \brief Constructs a MapPosition representing an exact copy of
	 * the given position, referring to the same map.
	 * 
	 * \param original is the position being copied.
	 */
	MapPosition(const MapPosition &original);
	
	/*!
	 * \brief Get the coordinates currently associated with this position.
	 * 
	 * \return A copy of the internal coordinate representation.
	 */
	Coord getCoordinates() const;
	
	/*!
	 * \brief Gets the terrain of the tile under this position.
	 * 
	 * \return the Tile::Terrain that this position is on.
	 */
	Tile::TerrainType detectTerrain() const;
	
	/*!
	 * \brief Gets the terrain under a specific offset from this position.
	 * 
	 * \param offset is the bounding box point that will be evaluated
	 * \return the terrain under the given offset from this position.
	 */
	Tile::TerrainType detectTerrainAtOffset(ManhattanDistance offset) const;
	
	/*!
	 * \brief Set the coordinates of this position.
	 * 
	 * \param newCoords the new coordinates.
	 */
	void setCoordinates(Coord newCoords);
	
	
	/*!
	 * \brief Selects a random set of coordinates well inside the map.
	 * 
	 * \return A random coordinate on the map.
	 */
	static MapPosition randomOn(Map* map);
	
	
	Coord operator = (const Coord &assignee);
	
	
	operator Coord ();
	
private:
	const Map* myMap;	/*!< The map where this position lies */
	Coord myCoordinates;	/*!< Coordinates of the position, in no particular units. */
};

#endif
