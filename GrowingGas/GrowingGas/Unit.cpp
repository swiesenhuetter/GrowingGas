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

void Unit::link(Unit& newNeighbour)
{
	std::list<Unit*>::iterator found = std::find(_neighbours.begin(),_neighbours.end(),&newNeighbour);
	if (found == _neighbours.end())
	{
		_neighbours.push_back(&newNeighbour);
	}
	std::list<Unit*>::iterator foundBackLink = std::find(newNeighbour._neighbours.begin(),newNeighbour._neighbours.end(),this);
	if (foundBackLink == newNeighbour._neighbours.end())
	{
		newNeighbour._neighbours.push_back(this);
	}
	// how to test this ??
}

void Unit::unlink(Unit& exNeighbour)
{
	std::list<Unit*>::iterator found = std::find(_neighbours.begin(),_neighbours.end(),&exNeighbour);
	if(found != _neighbours.end())
	{
		// remove
	}
	// smilar to link ?
}
