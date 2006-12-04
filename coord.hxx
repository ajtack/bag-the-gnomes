/*!
 * \class Coord
 * \brief An X,Y coordinate pair which supports manhattan arithmetic.
 * 
 * By manhattan arithmetic, we mean that the length of the path from
 * one point to another is a sum of the differences in each of X and Y.
 * 
 * \author Andres J. Tack
 */
#ifndef __COORD_H__
#define __COORD_H__


/*!
 * \brief Represents distance as an X,Y coordinate pair which may
 * be applied arithmetically to coordinates.
 * 
 * \author Andres J. Tack
 */
class ManhattanDistance
{
public:
	/*!
	 * \name Distance Pair
	 * \brief The x and y of the (x+y) manhattan distance sum.
	 */
	//@{
	int x;
	int y;
	//@}

	inline ManhattanDistance operator + (const ManhattanDistance &added);
	inline ManhattanDistance operator - (const ManhattanDistance &subtracted);
	
	inline bool operator > (const ManhattanDistance &lesser);
	inline bool operator < (const ManhattanDistance &greater);
};


class Coord
{
public:
	/*!
	 * \name Coordinates
	 * \brief The x and y of the (x,y) coordinate pair.
	 */
	//@{
	int x;
	int y;
	//@}
	
	/*!
	 * \brief Constructs a Coord with initial values for x and y.
	 * 
	 * \param x is the x value assigned.
	 * \param y is the y value assigned.
	 */
	Coord(int x, int y);
	
	/*!
	 * \brief Tests whether this coordinate is within the area
	 * bounded by the two given corners.
	 * 
	 * \param topLeft is the top-left corner of the bounding box.
	 * \param bottomRight is the bottom-right corner of the bounding box.
	 * 
	 * \return true if this point exists completely within the bounding
	 * box.  false otherwise.
	 */
	bool isInside(Coord &topLeft, Coord &bottomRight);
	
	
	inline Coord operator = (const Coord &assigned)	{
		this->x = assigned.x;
		this->y = assigned.y;
	}
	
	
	inline Coord operator + (const ManhattanDistance &added)	{
		return Coord( (x + added.x), (y + added.y) );
	}
	
	inline Coord operator - (const ManhattanDistance &subtracted)	{
		return Coord( (x - subtracted.x), (y - subtracted.y) );
	}
	
	
	inline Coord operator += (const ManhattanDistance &added)	{
		x += added.x;
		y += added.y;
		return *this;
	}
	
	inline Coord operator -= (const ManhattanDistance &subtracted)	{
		x -= subtracted.x;
		y -= subtracted.y;
		return *this;
	}
};


#endif /* __COORD_H__ */
