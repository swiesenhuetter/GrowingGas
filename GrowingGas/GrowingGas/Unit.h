#pragma once

#include <list>
#include "Pattern.h"
#include "Edge.h"
#include <memory>

class Unit
{
public:
	Unit(void);
	Unit(Position pos);
	~Unit(void);

	std::shared_ptr<Edge> link(Unit& newNeighbour);
	void unlink(Unit& exNeighbour);
	
	bool isNeigbour(const Unit& other);
	bool isSingle( void );
	std::list<Unit*> getNeighbours(void);
	double euclideanDistance(const Position& pattern);
	const Position& loc(void) const;
	
	void towards(const Pattern& pos, double fract);

private:
	Position _position{};
	std::list<std::shared_ptr<Edge>> _edges;
};
