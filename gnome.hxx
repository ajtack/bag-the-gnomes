/*!
 * \class Gnome
 * \brief Character class for a Gnome character.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_GNOME_CLASS__
#define __BG_GNOME_CLASS__

#include "character.hxx"
#include <allegro.h>

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
	virtual void draw(BITMAP* screen);
	
	/*!
	 * \sa
	 * Character::canPass(Tile::TerrainType)
	 */
	virtual bool canPass(Tile::TerrainType terrain);

protected:
	BITMAP* mySpriteSheet;	/*!< Sprite sheet used for gnome animation */
};

#endif