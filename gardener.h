/*!
 * \file gardener.h
 * \brief Declares the gardener class and supporting structures/definitions.
 *
 * \par Overview
 * The contents of this file will grant you the behaviors of your main
 * character.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_GARDENER_CLASS__
#define __BG_GARDENER_CLASS__

#include "character.h"
#include <allegro.h>

#define GARDENER_SPEED 5

/*!
 * \brief A Gardener character; the main player.
 */
class Gardener : public Character
{
public:
	/*!
	 * \brief Creates a gardener with the default speed of 3 pixels per frame.
	 * 
	 * \param x_pos_ is the initial X position of the gardener.
	 * \param y_pos_ is the initial Y position of the gardener.
	 * \param dir_ is the initial orientation of the gardener.
	 */
	Gardener(struct Coord position, Direction dir_ = SOUTH);
	
	/*!
	 * \sa
	 * Entity::draw(BITMAP*)
	 */
	void draw(BITMAP* screen);
	
	/*!
	 * \brief Sets the speed of the gardener, which is fixed, either
	 * to be on or off.
	 * 
	 * \param speed_ is the toggle to stop (0) or to move (anything else)
	 */
	void setSpeed(int speed_);
	
	/*!
	 * \sa
	 * Character::update()
	 */
	void update();
	
protected:
	BITMAP* mySpriteSheet;
};

#endif
