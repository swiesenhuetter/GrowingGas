#pragma once

#include <vector>
#include <boost/array.hpp>


typedef boost::array<double,2> Position2D ;

class Unit2D
{
public:
	Unit2D(void);
	Unit2D(Position2D pos);
	~Unit2D(void);
private:
	Position2D _position;
};
