/*!
 * \file gnome.h
 * \brief Declaration of the Gnome class, a character in the game.
 *
 * \par Overview
 * Gnomes walk in a line, and will scatter if they see a gnome in front
 * of them either a) scatter themselves or b) be bagged.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_GNOME_CLASS__
#define __BG_GNOME_CLASS__

#include "character.h"
#include <allegro.h>

/*!
 * \brief Character class for a Gnome character.  Behaviors are
 * generally equivalent to the behaviors of 
 */
class Gnome : public Character
{
public:
	/*!
	 * \brief Creates a gnome at the given position with a default speed
	 * of 2 pixels per frame.
	 * 
	 * \param x_pos_ is the starting X position of the gnome.
	 * \param y_pos_ is the starting Y position of the gnome.
	 * \param dir_ is the initial oreintation of the gnome.
	 */
	Gnome(MapPosition position, Direction dir_);
	
	/*!
	 * \brief Deallocates the space used for the gnome.
	 */
	~Gnome();
	
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	void draw(BITMAP* screen);

protected:
	BITMAP* mySpriteSheet;
};

#endif
