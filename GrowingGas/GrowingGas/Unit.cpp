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
	if (! isNeigbour(newNeighbour))
	{
		_neighbours.push_back(&newNeighbour);
	}
	if (! newNeighbour.isNeigbour(*this))
	{
		newNeighbour._neighbours.push_back(this);
	}
	return Edge(this,&newNeighbour);
}

void Unit::unlink(Unit& exNeighbour)
{
	if(isNeigbour(exNeighbour))
	{
		// remove
	}
	// smilar to link ?
}

bool Unit::isNeigbour(const Unit& other)
{
	bool unitInNeighbourhood = false;
	std::list<Unit*>::iterator found = std::find(_neighbours.begin(),_neighbours.end(),&other);
	if (found != _neighbours.end())
	{
		unitInNeighbourhood = true;
	}
	return unitInNeighbourhood;
}

bool Unit::isSingle( void )
{
	return _neighbours.empty();
}
