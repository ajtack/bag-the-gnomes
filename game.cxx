#include "game.hxx"

#include "character.hxx"
#include "empty_bag.hxx"
#include "gardener.hxx"
#include "gnome.hxx"
#include "map.hxx"
#include "snail.hxx"
#include "sprite.hxx"

#include <allegro.h>
#include <iostream>
#include <vector>

Game::Game(BITMAP* screen, Map* map)
{
	myScreen = screen;
	myMap = map;
	
	int middleX = myScreen->w / 2;
	int middleY = myScreen->h / 2;
	
	MapPosition gardenerPosition(myMap, Coord(middleX, middleY));
	myPlayer = new Gardener(gardenerPosition, SOUTH);
	
	srand(time(NULL));
}


Game::~Game()
{
	std::vector<Gnome*>::iterator enemy;
	for (enemy = myEnemies.begin(); enemy != myEnemies.end(); enemy++)
		delete (*enemy);
		
	std::vector<EmptyBag*>::iterator sack;
	for (sack = myEmptyBags.begin(); sack != myEmptyBags.end(); sack++)
		delete (*sack);
	
	std::list<GnomeFood*>::iterator morsel;
	for (morsel = myHuntedFood.begin(); morsel != myHuntedFood.end(); morsel++)
		delete (*morsel);
	for (morsel = mySafeFood.begin(); morsel != mySafeFood.end(); morsel++)
		delete (*morsel);
}


void Game::loop()
{
	if (foodShouldAppear())
		createFood();
		
	if (gnomeShouldAppear())
		createGnome();
	
	move_gnomes();
	move_player();
	
	draw();
}


bool Game::foodShouldAppear()
{
	return rand() % 1000 < theGnomeFoodRandomVariable;
}


bool Game::gnomeShouldAppear()
{
	if (!mySafeFood.empty())
		return rand() % 1000 < theGnomeRandomVariable;
	else
		return false;
}


void Game::createFood()
{
 	MapPosition foodPosition = MapPosition::randomOn(myMap);
	
	// Currently, we only eat snails
	mySafeFood.push_back(new Snail(foodPosition));
}


void Game::createGnome()
{
	if (mySafeFood.empty())
		return;
	
	MapPosition position = MapPosition(myMap, myMap->getRandomHole());
	Direction direction = Character::randomDirection();
	GnomeFood* food = mySafeFood.front();
	
	myEnemies.push_back(new Gnome(position, direction, food));
	
	mySafeFood.pop_front();
	myHuntedFood.push_back(food);
}


void Game::gnomeIsHome(int gnomeIndex)
{
	// Keep score?
}


void Game::move_player()
{
	if (key[KEY_UP])	{
		myPlayer->setDirection(NORTH);
		myPlayer->setSpeed(1);
	}
	else if (key[KEY_DOWN])	{
		myPlayer->setDirection(SOUTH);
		myPlayer->setSpeed(1);
	}
	else if (key[KEY_RIGHT])	{
		myPlayer->setDirection(EAST);
		myPlayer->setSpeed(1);
	}
	else if (key[KEY_LEFT])	{
		myPlayer->setDirection(WEST);
		myPlayer->setSpeed(1);
	}
	else	{
		myPlayer->setSpeed(0);
	}
	
	// Check for player collisions with gnomes.
	bool player_had_collision = false;
	std::vector<Gnome*>::iterator gnome;
	for (gnome = myEnemies.begin(); gnome != myEnemies.end(); gnome++)
	{
		if (myPlayer->collidesWith(*gnome))
		{
			player_had_collision = true;
			break;
		}
	}
	
	if (key[KEY_SPACE])
		tryBagging();
	else if (!player_had_collision)
		myPlayer->update();
}


void Game::move_gnomes()
{
	std::vector<Gnome*>::iterator gnome;
	for (gnome = myEnemies.begin(); gnome != myEnemies.end(); gnome++)
		(*gnome)->update();
}


void Game::tryBagging()
{
	bool bagged = false;	// Check for success
	Coord *attemptLoc;
	
	std::vector<Gnome*>::iterator gnome;
	for (gnome = myEnemies.begin(); gnome != myEnemies.end(); gnome++)
	{
		if (myPlayer->canBag(*gnome))	{
			myPlayer->bag(*gnome);
			bagged = true;
		}
	}
	
	if (!bagged)
	{
		myPlayer->bag(NULL);
		MapPosition position = myPlayer->getPosition();
		myEmptyBags.push_back(new EmptyBag(position));
	}
}


void Game::draw()
{
	// Create a new buffer (double-buffering)
	BITMAP* screen_buffer = create_bitmap(myScreen->w, myScreen->h);
	clear_bitmap(screen_buffer);
	
	myMap->blit(screen_buffer);
	
	//
	// Draw bags first, food, enemies, player last.
	//
	
	std::vector<EmptyBag*>::iterator sack;
	for (sack = myEmptyBags.begin(); sack != myEmptyBags.end(); sack++)
		(*sack)->draw(screen_buffer);
	
	std::list<GnomeFood*>::iterator morsel;
	for (morsel = myHuntedFood.begin(); morsel != myHuntedFood.end(); morsel++)
		(*morsel)->draw(screen_buffer);
	
	std::vector<Gnome*>::iterator enemy;
	for (enemy = myEnemies.begin(); enemy != myEnemies.end(); enemy++)
		(*enemy)->draw(screen_buffer);

	myPlayer->draw(screen_buffer);
	
	// Copy new buffer to screen
	blit(screen_buffer, screen, 0, 0, 0, 0, myScreen->w, myScreen->h);
	destroy_bitmap(screen_buffer);
}
