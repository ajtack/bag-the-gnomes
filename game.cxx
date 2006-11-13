#include "game.h"

#include "character.h"
#include "gardener.h"
#include "gnome.h"

#include <allegro.h>
#include <iostream>
#include <vector>

Game::Game(BITMAP* screen)
{
	myScreen = screen;
	int middleX = myScreen->w / 2;
	int middleY = myScreen->h / 2;
	
	player = new Gardener(middleX, middleY);
	enemies.clear();
	
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Direction random = Character::randomDirection();
		Gnome* gnome = new Gnome(middleX, middleY, random);
		gnome->setSpeed(4);
		enemies.push_back(gnome);
	}
}


Game::~Game()
{
	std::vector<Character*>::iterator enemy;
	for (enemy = enemies.begin(); enemy != enemies.end(); enemy++)
		delete (*enemy);

	enemies.clear();
}


void Game::loop()
{
	move_player();
	move_gnomes();
	
	draw();
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
	
	player->update();
}


void Game::move_gnomes()
{
	std::vector<Character*>::iterator gnome;
	for (gnome = enemies.begin(); gnome != enemies.end(); gnome++)
		(*gnome)->update();
}


void Game::draw()
{
	// Create a new buffer
	BITMAP* screen_buffer = create_bitmap(myScreen->w, myScreen->h);
	clear_bitmap(screen_buffer);
	
	// Draw enemies first, player last.
	std::vector<Character*>::iterator enemy;
	for (enemy = enemies.begin(); enemy != enemies.end(); enemy++)
		(*enemy)->draw(screen_buffer);

	player->draw(screen_buffer);
	
	// Copy new buffer to screen
	blit(screen_buffer, screen, 0, 0, 0, 0, myScreen->w, myScreen->h);
	destroy_bitmap(screen_buffer);
}
