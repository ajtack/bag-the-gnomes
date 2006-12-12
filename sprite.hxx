/*!
 * \file sprite.hxx
 * \brief Declares the Sprite and Sprite::BoundingBox classes.
 */
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "coord.hxx"

/*!
 * \brief Directions that entities can face.
 */
enum Direction
{
	SOUTH,
	WEST,
	EAST,
	NORTH
};

/*!
 * \class Sprite
 * \brief Wraps around a drawn sprite, including the bounding box.
 *
 * \author: Andres J. Tack
 */
class Sprite
{
public:
	
	/*!
	 * \name Image Dimensions
	 * \brief The height and width of the image used to draw the sprite.
	 */
	//@{
	int image_w;
	int image_h;
	//@}
	
	int speed;	/*!< The speed in pixels/moving frame */
	Direction direction;	/*!< The heading of the sprite. */
	
	int frame;	/*!< The current frame of animation. */
	int frameTotal;	/*!< The total frames of animation available. */
	
	int frameDelay;	/*!< The number of frames to delay before animating. */
	int frameDelayCount;	/*!< A counter for delaying frames. */
	
	
	/*!
	 * \brief Constructs a Sprite with no bounding box.  This sprite cannot
	 * be collided-with.
	 */
	Sprite();


	/*!
	 * \brief Wraps around four points of a bounding box, used for
	 * collision-detection with the included methods.
	 * 
	 * Contrary to what you might think, all insets are from the
	 * top-left corner of the sprite.  inset-right > inset-left, and
	 * similarly inset-bottom > inset-top.
	 */
	class BoundingBox
	{
	public:
		/*!
		 * \name Relative Offset Positions
		 * \brief These distances are relative offsets from an absolute
		 * position of the sprite, which can be injected to the
		 * BoundingBox::isCollidingWith() method at the last minute.
		 */
		//@{
		ManhattanDistance offsetTopLeft;
		ManhattanDistance offsetTopRight;
		ManhattanDistance offsetBottomLeft;
		ManhattanDistance offsetBottomRight;
		//@}
		
		/*!
		 * \brief Constructes a bounding box with the given offsets from the
		 * absolute position of the sprite.
		 */
		BoundingBox(int offsetLeft, int offsetRight, int offsetTop, int offsetBottom);
		
		/*!
		 * \brief Checks for collisions with another bounding box by
		 * injecting a current position.
		 * 
		 * \param him is the bounding box of the other sprite.
		 * \param myPos is the absolute position of this bounding box
		 * \param hisPos is the absolute position of "him"'s bounding box
		 * 
		 * \return True if a collision exists between these two bounding
		 * boxes.  False otherwise.
		 */
		bool isCollidingWith(const BoundingBox* him, const Coord &myPos, const Coord &hisPos) const;
		
	} boundingBox;
	
	
	/*!
	 * \brief Constructs a sprite with a bounding box that may be collided-with.
	 * 
	 * \param bounds will be copied and used as the bounding box for this
	 * sprite.
	 */
	Sprite(const BoundingBox &bounds);
};

#endif
