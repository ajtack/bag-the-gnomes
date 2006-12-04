#include "coord.hxx"


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
