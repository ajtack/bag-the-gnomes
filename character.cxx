#include "character.h"

Character::Character(int x_pos_, int y_pos_, Direction orientation) :
	x_pos(x_pos_),
	y_pos(y_pos_),
	direction(orientation)
{
	// Initialization List
}

void Character::move(int dx, int dy)
{
	this->x_pos += dx;
	this->y_pos += dy;
}

Character::Direction Character::randomDirection()
{
	return Direction(rand() % 8);
}
