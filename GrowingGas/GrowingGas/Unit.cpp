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

std::shared_ptr<Edge> Unit::link(Unit& newNeighbour)
{
	if (! isNeigbour(newNeighbour))
	{
		_edges.emplace_back(std::make_shared<Edge>(this,&newNeighbour));
		newNeighbour._edges.push_back(_edges.back());
		return _edges.back();
	}
	else
	{
		auto it = _edges.begin();
		for (; it != _edges.end(); ++it)
		{
			auto edge = *it;
			if (edge->_u1 == &newNeighbour || edge->_u2 == &newNeighbour)
				return edge;
		}
		return nullptr;
	}
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
	auto it = _edges.begin();
	for (;it != _edges.end() ; ++it)
	{
		Unit* firstUnit = (*it)->_u1;
		if (firstUnit == this)
		{
			neighbours.push_back((*it)->_u2);
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

const Position& Unit::loc(void) const
{
	return _position;
}

void Unit::towards(const Pattern& pat, double fract)
{
	auto new_pat = pat + Pattern(pat - _position) * fract;
	_position = new_pat.position;
}
