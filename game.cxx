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
	
	for (int i = 0; i < 5; i++)
	{
		Character::Direction random = Character::randomDirection();
		enemies.push_back(new Gnome(middleX, middleY, random));
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
	int dx = 0, dy = 0;
	
	if (key[KEY_UP])
		dy = -1;
	else if (key[KEY_DOWN])
		dy = 1;
	
	if (key[KEY_RIGHT])
		dx = 1;
	else if (key[KEY_LEFT])
		dx = -1;
		
	player->move(dx, dy);
}


void Game::move_gnomes()
{
	std::vector<Character*>::iterator gnome;
	for (gnome = enemies.begin(); gnome != enemies.end(); gnome++)
	{
		int dx = (rand() % 8) - 4;
		int dy = (rand() % 8) - 4;
		
		(*gnome)->move(dx, dy);
	}
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
