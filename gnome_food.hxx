/*!
 * \class GnomeFood
 * \brief Delightful goodies upon which a Gnome may prefer to snack.
 * 
 * GnomeFood is the game element that draws Gnomes out of their holes,
 * as otherwise they would hide safely away from the farmer.
 * 
 * \author Andres J. Tack
 */
#ifndef __GNOME_FOOD_HXX__
#define __GNOME_FOOD_HXX__

#include "entity.hxx"
#include "map_position.hxx"
#include "sprite.hxx"

class GnomeFood : public Entity
{
public:
	/*!
	 * \brief Initializes a tasty gnome food to a not-captured status.
	 * 
	 * \param position is where the gnome food should appear.
	 */
	GnomeFood(MapPosition &position);
	
	/*!
	 * \brief Tells whether this bit of food has been stolen.
	 */
	inline virtual bool hasBeenStolen() const	{
		return myHasBeenStolen;
	}
	
	/*!
	 * \brief Sets this food item to a particular "stolen" status.
	 * 
	 * \param is the new "stolen or not stolen" state of the food.
	 */
	inline virtual void setIsStolen(bool stolen)	{
		myHasBeenStolen = stolen;
	}
	
	/*!
	 * \brief Tells whether this scrumptious iota is being hunted.
	 */
	inline virtual bool isBeingHunted() const	{
		return myIsBeingHunted;
	}
	
	/*!
	 * \brief Records whether this dilectable dish is being hunted.
	 * 
	 * \param hunted will be recorded for this purpose.
	 */
	inline virtual void setIsBeingHunted(bool hunted)	{
		myIsBeingHunted = hunted;
	}
	
protected:
	Sprite mySprite;	/*!< The inanimate sprite used to draw the food. */
	
	/*!
	 * Describes whether a gnome has taken this food from its 
	 * resting place.
	 */
	bool myHasBeenStolen;
	
	/*!
	 * Describes whether a gnome is currently chasing after this
	 * tasty morsel.
	 */
	bool myIsBeingHunted;
};

#endif /* __GNOME_FOOD_HXX__ */

