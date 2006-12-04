#include "game.hxx"

#include "character.hxx"
#include "gardener.hxx"
#include "gnome.hxx"
#include "map.hxx"
#include "snail.hxx"
#include "sprite.hxx"

#include <allegro.h>
#include <vector>

Game::Game(BITMAP* screen, Map* map)
{
	myScreen = screen;
	myMap = map;
	
	int middleX = myScreen->w / 2;
	int middleY = myScreen->h / 2;
	
	MapPosition gardenerPosition(myMap, Coord(middleX, middleY));
	player = new Gardener(gardenerPosition, SOUTH);
	enemies.clear();
	
	srand(time(NULL));
}


Game::~Game()
{
	std::vector<Gnome*>::iterator enemy;
	for (enemy = enemies.begin(); enemy != enemies.end(); enemy++)
		delete (*enemy);

	enemies.clear();
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
	return rand() % 1000 < theGnomeRandomVariable;
}


void Game::createFood()
{
 	MapPosition foodPosition = MapPosition::randomOn(myMap);
	
	// Currently, we only eat snails
	food.push_back(new Snail(foodPosition));
}


void Game::createGnome()
{
	MapPosition position = MapPosition(myMap, myMap->getRandomHole());
	enemies.push_back(new Gnome(position, Character::randomDirection()));
}


void Game::gnomeIsHome(int gnomeIndex)
{
	// Keep score?
}


void Game::move_player()
{
	if (key[KEY_UP])
	{
		player->setDirection(NORTH);
		player->setSpeed(1);
	}
	else if (key[KEY_DOWN])
	{
		player->setDirection(SOUTH);
		player->setSpeed(1);
	}
	else if (key[KEY_RIGHT])
	{
		player->setDirection(EAST);
		player->setSpeed(1);
	}
	else if (key[KEY_LEFT])
	{
		player->setDirection(WEST);
		player->setSpeed(1);
	}
	else
	{
		player->setSpeed(0);
	}
	
	// Check for player collisions with gnomes.
	bool player_had_collision = false;
	std::vector<Gnome*>::iterator gnome;
	for (gnome = enemies.begin(); gnome != enemies.end(); gnome++)
	{
		if (player->collidesWith(*gnome))
		{
			player_had_collision = true;
			break;
		}
	}
	
	if (!player_had_collision)
		player->update();
}


void Game::move_gnomes()
{
	std::vector<Gnome*>::iterator gnome;
	for (gnome = enemies.begin(); gnome != enemies.end(); gnome++)
		(*gnome)->update();
}


void Game::draw()
{
	// Create a new buffer
	BITMAP* screen_buffer = create_bitmap(myScreen->w, myScreen->h);
	clear_bitmap(screen_buffer);
	
	// Blit the map
	myMap->blit(screen_buffer);
	
	//
	// Draw food first, enemies next, player last.
	//
	
	std::vector<GnomeFood*>::iterator morsel;
	for (morsel = food.begin(); morsel != food.end(); morsel++)
		(*morsel)->draw(screen_buffer);
	
	std::vector<Gnome*>::iterator enemy;
	for (enemy = enemies.begin(); enemy != enemies.end(); enemy++)
		(*enemy)->draw(screen_buffer);

	player->draw(screen_buffer);
	
	// Copy new buffer to screen
	blit(screen_buffer, screen, 0, 0, 0, 0, myScreen->w, myScreen->h);
	destroy_bitmap(screen_buffer);
}
