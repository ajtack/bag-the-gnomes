/*!
 * \file coord.hxx
 * \brief Declares the Coord Class.
 */
#ifndef __COORD_HXX__
#define __COORD_HXX__

#include <iostream>
#include "manhattan_distance.hxx"

/*!
 * \class Coord
 * \brief An X,Y coordinate pair which supports manhattan arithmetic.
 * 
 * By manhattan arithmetic, we mean that the length of the path from
 * one point to another is a sum of the differences in each of X and Y.
 * 
 * \author Andres J. Tack
 */
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
	
	
	inline Coord operator = (const Coord &assigned)
	{
		this->x = assigned.x;
		this->y = assigned.y;
	}
	
	
	inline Coord operator + (const ManhattanDistance &added) const
	{
		return Coord( (x + added.x), (y + added.y) );
	}
	
	inline Coord operator - (const ManhattanDistance &subtracted) const
	{
		return Coord( (x - subtracted.x), (y - subtracted.y) );
	}
	
	
	inline Coord operator += (const ManhattanDistance &added)
	{
		x += added.x;
		y += added.y;
		return *this;
	}
	
	inline Coord operator -= (const ManhattanDistance &subtracted)
	{
		x -= subtracted.x;
		y -= subtracted.y;
		return *this;
	}
	
	friend std::istream & operator << (std::ostream & output, const Coord &coord);
};


#endif /* __COORD_H__ */
