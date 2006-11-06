#include "game.h"

#include "character.h"
#include "gardener.h"

#include <allegro.h>
#include <iostream>
#include <vector>

Game::Game(BITMAP* screen)
{
	myScreen = screen;
	player = new Gardener(myScreen->w / 2, myScreen->h / 2);
	enemies.clear();
}


Game::~Game()
{
	std::vector<Character*> enemy;
	enemies.erase(enemy.begin(), enemy.end());
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
	// Does nothing for now!
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
}
