#include "character.h"

void Character::move(int dx, int dy)
{
	this->x_pos += dx;
	this->y_pos += dy;
}
