#pragma once

#include <cmath>
#include <array>

typedef std::array<double,2> Position ;

struct Pattern
{
	Pattern(Position pos) : position(pos) {}

	Position position;

	Pattern operator+(Pattern other) const;
	Pattern operator-(Pattern other) const;
	Pattern operator*(double factor) const;

};


inline double euklideanDistance(const Position& p1, const Position& p2)
{
	double dist = 0.0;
	auto it1 = p1.cbegin();
	auto it2 = p2.cbegin();
	for ( ; it1 != p1.cend() && it2 != p2.cend(); ++it1,++it2)
	{
		dist += (*it1-*it2) * (*it1-*it2); 	
	}
	dist = sqrt(dist);
	return dist;
}
