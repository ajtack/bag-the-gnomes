/*!
 * \file game.h
 * \brief Main "Bag the Gnomes" class which runs the game loop and controls state.
 *
 * \par Overview
 * Running an instance of "Bag the Gnomes" is as simple as instantiating this class
 * and calling Game::loop() at your desired interval.  Nothing is done to initialize
 * Allegro by anything in this file.  This must be done in the main routine, which the
 * Game class does not define.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_GAME_CLASS__
#define __BG_GAME_CLASS__

#include "character.h"
#include "gardener.h"
#include "square_map.h"

#include <allegro.h>
#include <vector>

/*!
 * \brief Encapsulates game state and provides facilities for 
 * executing game loops.
 */
class Game
{
private:
	SquareMap* myMap;
	
	Gardener* player;
	std::vector<Character*> enemies;
	
	BITMAP* myScreen;
	
public:
	/*!
	 * \brief Initializes a working game.  This is the only initialization
	 * necessary to run the game loop.
	 * 
	 * \pre Allegro must be initialized.
	 * 
	 * \param screen is where game elements will be drawn
	 */
	Game(BITMAP* screen);
	
	/*!
	 * \brief Deallocates all memory used for this game.
	 */
	~Game();
	
	/*!
	 * \brief Executes one iteration of the game loop.
	 * 
	 * This function will update the internal state of the game automatically,
	 * and also make all drawing calls to the screen.
	 * 
	 * The game loop will proceed at high speed, untimed.  Any timing should
	 * be handled outside of the Game object in use.
	 */
	void loop();
	
private:
	/*!
	 * \brief Draws all entities to the screen for this game.
	 */
	void draw();
	
	/*!
	 * \brief Accepts human keyboard input and moves the player
	 * in kind.
	 */
	void move_player();
	
	/*!
	 * \brief Applies Gnome-Movement algorithms to update gnome
	 * behavior.
	 */
	void move_gnomes();
};

#endif
