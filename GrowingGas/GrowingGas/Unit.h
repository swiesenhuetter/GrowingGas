#pragma once

#include <list>
#include "Pattern.h"
#include "Edge.h"

class Unit
{
public:
	Unit(void);
	Unit(Position pos);
	~Unit(void);

	Edge link(Unit& newNeighbour);
	void unlink(Unit& exNeighbour);
	
	bool isNeigbour(const Unit& other);
	bool isSingle( void );
private:
	Position _position;
	std::list<Unit*> _neighbours;
};
