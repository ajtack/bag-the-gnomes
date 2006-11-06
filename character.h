#include "entity.h"

class Character : public Entity
{
public:
	Character(int x_pos_, int y_pos_, Direction orientation = SOUTH);
	
	virtual void draw(BITMAP* screen);
	
	enum Direction
	{
		NORTH,
		NORTHEAST,
		EAST,
		SOUTHEAST,
		SOUTH,
		SOUTHWEST,
		WEST,
		NORTHWEST
	};

	/*!
	 * \brief Moves the entity (but does not draw) by the indicated
	 * number of pixels.
	 * 
	 * \param dx is the change in X position
	 * \param dy is the change in Y position
	 */
	void move(int dx, int dy);

private:
	unsigned int x_pos;
	unsigned int y_pos;

	Direction direction;
	
	const unsigned int speed;
};
