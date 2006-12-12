/*!
 * \file gardener.hxx
 * \brief Declares the Gardener class.
 */
#ifndef __BG_GARDENER_CLASS__
#define __BG_GARDENER_CLASS__

#include "character.hxx"
#include <allegro.h>

class Gnome;

#define GARDENER_SPEED 5
#define GARDENER_FRAME_DELAY 3

/*!
 * \class Gardener
 * \brief A Gardener character; the main player.
 * 
 * \author Andres J. Tack
 */
class Gardener : public Character
{
public:
	/*!
	 * \brief Creates a gardener with the default speed of 3 pixels per frame.
	 * 
	 * \param position is the initial position of the gardener on a map.
	 * \param dir_ is the initial orientation of the gardener.
	 */
	Gardener(MapPosition position, Direction dir_ = SOUTH);
	
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	virtual void draw(BITMAP* screen);
	
	/*!
	 * \brief Sets the speed of the gardener, which is fixed, either
	 * to be on or off.
	 * 
	 * \param speed_ is the toggle to stop (0) or to move (anything else)
	 */
	void setSpeed(int speed_);
	
	/*!
	 * \brief Bags the given gnome.
	 * 
	 * \param gnome is the gnome being bagged here.
	 */
	void bag(Gnome* gnome);
	
	/*!
	 * \brief Counts how many bags the gardener has left.
	 * 
	 * \return The sum of bags the gardener has remaining.
	 */
	int getBagsLeft() const;
	
	/*!
	 * \brief Tells you whether this gnome can be bagged at this instant
	 * 
	 * \param gnome The gnome to try to bag.
	 * 
	 * \return true if a gnome can be bagged at this moment in the game. false otherwise.
	 */
	bool canBag(Gnome* gnome) const;
	
protected:
	BITMAP* mySpriteSheet;	/*!< Sprite sheet used for Gardener animation */
	
	int myBagsLeft;	/*!< Number of bags this gardener has left. */
};

#endif
