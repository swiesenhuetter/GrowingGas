#pragma once

#include <cmath>
#include <array>

typedef std::array<double,2> Position ;
typedef std::array<double,3> OutputValue;

struct Pattern
{
	Position position;
	OutputValue output;

	static const int horizontal	= 0;
	static const int vertical = 1;
};


inline double euklideanDistance(const Position& p1, const Position& p2)
{
	double dist = 0;
	Position::const_iterator it1 = p1.begin();
	Position::const_iterator it2 = p2.begin();
	for ( ; it1 != p1.end() && it2 != p2.end(); ++it1,++it2)
	{
		dist += (*it1-*it2) * (*it1-*it2); 	
	}
	dist = sqrt(dist);
	return dist;
}
