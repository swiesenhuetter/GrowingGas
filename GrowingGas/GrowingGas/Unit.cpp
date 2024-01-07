#include "StdAfx.h"
#include "Unit.h"
#include <algorithm>

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
    if (isNeigbour(newNeighbour))
    {
        unlink(newNeighbour);
    }
    _edges.emplace_back(std::make_shared<Edge>(this, &newNeighbour));
    newNeighbour._edges.push_back(_edges.back());
    return _edges.back();
}

void Unit::unlink(Unit& exNeighbour)
{
    if (isNeigbour(exNeighbour))
    {
        auto it = _edges.begin();
        for (; it != _edges.end(); ++it)
        {
            Unit* firstUnit = (*it)->_u1;
            Unit* secondUnit = (*it)->_u2;
            if (firstUnit == &exNeighbour || secondUnit == &exNeighbour)
            {
                _edges.erase(it);
                break;
            }
        }
        auto it2 = exNeighbour._edges.begin();
        for (; it2 != exNeighbour._edges.end(); ++it2)
        {
            Unit* firstUnit = (*it2)->_u1;
            Unit* secondUnit = (*it2)->_u2;
            if (firstUnit == this || secondUnit == this)
            {
                exNeighbour._edges.erase(it2);
                break;
            }
        }
    }
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

void Unit::age_increment()
{
	std::for_each(_edges.begin(),_edges.end(),[](auto edge){edge->_age++;});
}
