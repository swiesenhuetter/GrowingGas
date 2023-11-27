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
	std::list<Unit*> getNeighbours(void);
	double euclideanDistance(const Position& pattern);
	const Position& loc(void) const;
	
	void towards(const Pattern& pos, double fract);

private:
	Position _position{};
	std::list<Edge> _edges;
};
