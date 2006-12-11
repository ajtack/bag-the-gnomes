/*!
 * \file manhattandistance.hxx
 * \brief Declares the ManhattanDistance class.
 */
#ifndef __MANHATTAN_DISTANCE_HXX__
#define __MANHATTAN_DISTANCE_HXX__

/*!
 * \class ManhattanDistance
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

	/*!
	 * \brief Constructs a Manhattan Distance with the given components.
	 *
	 * \param x is the distance in x
	 * \param y is the distance in y
	 */
	ManhattanDistance(int x, int y);

	inline ManhattanDistance operator + (const ManhattanDistance &added) const
	{
		return ManhattanDistance(x + added.x, y + added.y);
	}
	
	inline ManhattanDistance operator - (const ManhattanDistance &subtracted) const
	{
		return ManhattanDistance(x - subtracted.x, y - subtracted.y);
	}
	
	inline bool operator > (const ManhattanDistance &lesser) const
	{
		return (this->x + this->y) > (lesser.x + lesser.y);
	}
	
	inline bool operator < (const ManhattanDistance &greater) const
	{
		return (this->x + this->y) < (greater.x + greater.y);
	}
};

#endif /* __MANHATTAN_DISTANCE_HXX__ */
