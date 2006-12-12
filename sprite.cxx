/*!
 * \file sprite.cxx
 * \brief Implementation for the Sprite and Sprite::BoundingBox classes.
 */
#include "sprite.hxx"


Sprite::Sprite() :
	boundingBox(0, 0, 0, 0)
{
	// Initialization List
}


Sprite::Sprite(const BoundingBox &bounds) :
	boundingBox(bounds)
{
	// Initialization List
}


Sprite::BoundingBox::BoundingBox(int offsetLeft, int offsetRight, int offsetTop, int offsetBottom) :
	offsetTopLeft(offsetLeft, offsetTop),
	offsetTopRight(offsetRight, offsetTop),
	offsetBottomLeft(offsetLeft, offsetBottom),
	offsetBottomRight(offsetRight, offsetBottom)
{
	// Initialization list
}


bool Sprite::BoundingBox::isCollidingWith(const BoundingBox* him, const Coord &myPos, const Coord &hisPos) const
{
	Coord hisTopLeft =     hisPos + him->offsetTopLeft;
	Coord hisBottomRight = hisPos + him->offsetBottomRight;
	
	// Check my...
	// Top Left corner
	Coord myTopLeft = myPos + this->offsetTopLeft;
	if ( myTopLeft.isInside(hisTopLeft, hisBottomRight) )
		return true;
		
	// Top Right corner
	Coord myTopRight = myPos + this->offsetTopRight;
	if ( myTopRight.isInside(hisTopLeft, hisBottomRight) )
		return true;
	
	// Bottom Left corner
	Coord myBottomLeft = myPos + this->offsetBottomLeft;
	if ( myBottomLeft.isInside(hisTopLeft, hisBottomRight) )
		return true;
	
	// Bottom Right corner
	Coord myBottomRight = myPos + this->offsetBottomRight;
	if ( myBottomRight.isInside(hisTopLeft, hisBottomRight) )
		return true;
		
	// No collision?
	return false;
}
