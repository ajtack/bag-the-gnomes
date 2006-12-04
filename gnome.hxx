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
	friend class Gardener;
	
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
	
	virtual void draw(BITMAP* screen);
	
	virtual void update();
	
	/*!
	 * \sa
	 * Character::canPass(Tile::TerrainType)
	 */
	virtual bool canPass(Tile::TerrainType terrain);
	
	/*!
	 * \brief Sets this gnome to "bagged" state.
	 */
	virtual void bag();

protected:
	/*!
	 * \name Sprite Sheets
	 * \brief These are the large images whence gnome images are gathered.
	 */
	//@{
	static BITMAP* theirSpriteSheet;	/*!< Used for gnome animation */
	static BITMAP* theirBaggedSheet;	/*!< Used for bagged gnomes */
	//@}
	
	/*!
	 * \name Bagged Sprite Pource Pixels
	 * \brief Used only when a gnome is bagged.
	 */
	//@{
	static int theirBaggedSpriteX;
	static int theirBaggedSpriteY;
	//@}
	
	bool myFreedom;	/*!< Tracks whether this gnome is bagged or free */
};

#endif
