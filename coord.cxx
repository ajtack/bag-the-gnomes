/*!
 * \file coord.cxx
 * \brief Implementation for the Coord class.
 */
#include "coord.hxx"


ManhattanDistance::ManhattanDistance(int x, int y)
{
	this->x = x;
	this->y = y;
}


Coord::Coord(int x, int y)
{
	this->x = x;
	this->y = y;
}


bool Coord::isInside(Coord &topLeft, Coord &bottomRight)
{
	if (    this->x > topLeft.x && this->x < bottomRight.x &&
	        this->y > topLeft.y && this->y < bottomRight.y      )
		return true;
	else
		return false;
}

std::istream & operator << (std::ostream & output, Coord const &coord)
{
	output << '(' << coord.x << ", " << coord.y << ')' << std::endl;
}
