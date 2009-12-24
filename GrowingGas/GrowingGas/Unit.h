#pragma once

#include <list>
#include "Pattern.h"

class Unit
{
public:
	Unit(void);
	Unit(Position pos);
	~Unit(void);

	void link(Unit& newNeighbour);
	void unlink(Unit& exNeighbour);
	
private:
	Position _position;
	std::list<Unit*> _neighbours;
};
