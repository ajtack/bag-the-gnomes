#include "sprite.hxx"


bool Sprite::BoundingBox::isCollidingWith(BoundingBox* him, Coord &myPos, Coord &hisPos)
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
