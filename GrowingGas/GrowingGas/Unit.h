#pragma once

#include <list>
#include "Pattern.h"

class Unit
{
public:
	Unit(void);
	Unit(Position pos);
	~Unit(void);

	void link(const Unit *newNeighbour);
	void unlink(const Unit *exNeighbour);
	
private:
	Position _position;
	std::list<Unit> _neighbours;
};
