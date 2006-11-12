#ifndef __BG_GARDENER_CLASS__
#define __BG_GARDENER_CLASS__

#include "character.h"
#include "sprite.h"
#include <allegro.h>

#define GARDENER_SPEED 5

class Gardener : public Character
{
public:
	/*
	 * \brief Creates a gardener with the default speed of 3 pixels per frame.
	 * 
	 * \param x_pos_ is the initial X position of the gardener.
	 * \param y_pos_ is the initial Y position of the gardener.
	 * \param dir_ is the initial orientation of the gardener.
	 */
	Gardener(int x_pos_, int y_pos_, Direction dir_ = SOUTH);
	
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
