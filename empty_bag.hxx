/*!
 * \file empty_bag.hxx
 * \brief Declares the EmptyBag class.
 */
#ifndef __EMPTY_BAG_HXX__
#define __EMPTY_BAG_HXX__

#include "entity.hxx"
#include "sprite.hxx"

/*!
 * \class EmptyBag
 * \brief A sign of a failed attempt to bag a gnome.  Empty bags cannot be
 * recovered once they are set down.
 * 
 * \author Andres J. Tack
 */
class EmptyBag : public Entity
{
public:
	/*!
	 * \brief Constructs an empty bag at the given map location.
	 * 
	 * \param position is where the bag is.
	 */
	EmptyBag(MapPosition &position);
	
	
	void draw(BITMAP* screen);
	
protected:
	Sprite mySprite;	/*!< The graphic illustrating the bag. */
	
	static BITMAP* theirSpriteSheet;	/*!< Where this entity is drawn from */
	
	/*!
	 * \name Sprite Source Pixel Location
	 * \brief These identify where the sprite is on the sheet.
	 */
	//@{
	static int theirSpriteX;
	static int theirSpriteY;
	//@}
};

#endif /* __EMPTY_BAG_HXX__ */
