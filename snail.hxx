/*!
 * \class Snail
 * \brief Perhaps the most delicious of all GnomeFoods, the Snail is
 * a highly sought-after food item by gnomes.
 * 
 * \author Andres J. Tack
 */
#ifndef __SNAIL_HXX__
#define __SNAIL_HXX__

#include "gnome_food.hxx"
#include "map_position.hxx"

class Snail : public GnomeFood
{
public:
	/*!
	 * \brief Creates a soon-to-be-eaten snail at the given location.
	 * 
	 * \param position is the location of the snail.  The Snail is stationary.
	 */
	Snail(MapPosition &position);
	
	void draw(BITMAP* screen);
	
private:
	static BITMAP* mySpriteSheet;	/*!< The sprite sheet wherefrom a snail is drawn. */
};

#endif /* __SNAIL_HXX__ */
