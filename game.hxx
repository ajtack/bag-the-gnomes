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

class EmptyBag;
class Gnome;
class Gardener;
class GnomeFood;
class Map;

#include <allegro.h>
#include <list>
#include <vector>

static const int theGnomeFoodRandomVariable = 15;
static const int theGnomeRandomVariable = 12;

class Game
{
private:
	Map* myMap;
	
	Gardener* myPlayer;
	std::vector<Gnome*> myEnemies;
	std::list<GnomeFood*> myHuntedFood;
	std::list<GnomeFood*> mySafeFood;
	std::vector<EmptyBag*> myEmptyBags;
	
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
	 * \brief Determines by random variables whether a food item should
	 * appear on the screen.
	 * 
	 * \return true if random determination says a snail should be
	 * placed on screen, false otherwise.
	 */
	static bool foodShouldAppear();
	
	/*!
	 * \brief Determines by random variables whether a gnome should appear
	 * to chase after food.
	 * 
	 * \bug At this point, the random variable appears not to function.  As
	 * soon as a snail appears, a gnome appears also.
	 * 
	 * \return true if random determination says a gnome should appear.
	 */
	bool gnomeShouldAppear();
	
	/*!
	 * \brief Selects a food item and places it on the map.  Also adds it to the
	 * internal list of food items.
	 */
	void createFood();
	
	/*!
	 * \brief Creates a gnome on the map!  He is hungry!
	 */
	void createGnome();
	
	/*!
	 * \brief Tallies up score results from a gnome making it home
	 * with a snail!
	 * 
	 * \param gnomeIndex the gnome that made it home.
	 */
	void gnomeIsHome(int gnomeIndex);
	
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
	
	
	/*!
	 * \brief Let the player attempt to bag a gnome.
	 */
	void tryBagging();
};

#endif
