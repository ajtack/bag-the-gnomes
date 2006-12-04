/*!
 * \class Game
 * \brief Encapsulates game state and provides facilities for executing game loops.
 *
 * \par Overview
 * Running an instance of "Bag the Gnomes" is as simple as instantiating this class
 * and calling Game::loop() at your desired interval.  Nothing is done to initialize
 * Allegro by anything in this class.  This must be done in the main routine, which the
 * Game class does not define.
 *
 * \author: Andres J. Tack
 */
#ifndef __BG_GAME_CLASS__
#define __BG_GAME_CLASS__

#include "character.h"
#include "gardener.h"
#include "map.h"

#include <allegro.h>
#include <vector>

class Game
{
private:
	Map* myMap;
	
	Gardener* player;
	std::vector<Character*> enemies;
	
	BITMAP* myScreen;
	
public:
	/*!
	 * \brief Initializes a working game.  This is the only initialization
	 * necessary to run the game loop.
	 * 
	 * Note that the "game" exists only as long as one common "level".
	 * Pass a different map for different levels.
	 * 
	 * \pre Allegro must be initialized.
	 * 
	 * \param screen is where game elements will be drawn
	 * \param map is the file from which map data will be
	 */
	Game(BITMAP* screen, Map* map);
	
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
