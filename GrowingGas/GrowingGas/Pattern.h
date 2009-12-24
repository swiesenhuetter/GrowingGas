#pragma once

#include <boost/array.hpp>

typedef boost::array<double,2> Position ;
typedef boost::array<double,3> OutputValue;

struct Pattern
{
	Position position;
	OutputValue output;

	static const int horizontal	= 0;
	static const int vertical = 1;
};



