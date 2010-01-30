#include "StdAfx.h"
#include "Unit.h"

Unit::Unit(void)
{
}

Unit::~Unit(void)
{
}

Unit::Unit(Position pos)
:_position(pos)
{
}

Edge Unit::link(Unit& newNeighbour)
{
	Edge newEdge(this,&newNeighbour);
	if (! isNeigbour(newNeighbour))
	{
		_edges.push_back(newEdge);
		newNeighbour._edges.push_back(newEdge);
	}
	return newEdge;
}

void Unit::unlink(Unit& exNeighbour)
{
	if(isNeigbour(exNeighbour))
	{
		// remove
	}
	// smilar to link ?
}

std::list<Unit*> Unit::getNeighbours(void)
{
	std::list<Unit*> neighbours;
	std::list<Edge>::iterator it = _edges.begin();
	for (;it != _edges.end() ; ++it)
	{
		Unit* firstUnit = it->_u1;
		if (firstUnit == this)
		{
			neighbours.push_back(it->_u2);
		}
		else
		{
			neighbours.push_back(firstUnit);
		}
	}
	return neighbours;
}


bool Unit::isNeigbour(const Unit& other)
{
	bool unitInNeighbourhood = false;
	std::list<Unit*> neighbours = getNeighbours();
	std::list<Unit*>::iterator found = std::find(neighbours.begin(),neighbours.end(),&other);
	if (found != neighbours.end())
	{
		unitInNeighbourhood = true;
	}
	return unitInNeighbourhood;
}

bool Unit::isSingle( void )
{
	return _edges.empty();
}

double Unit::euclideanDistance(const Position& pattern)
{
	double dist = 0;
	dist = ::euklideanDistance(_position,pattern);
	return dist;
}
