#pragma once

#include <vector>
#include <boost/array.hpp>


typedef boost::array<double,2> Position ;
typedef Position Pattern;

class Unit
{
public:
	Unit(void);
	Unit(Position pos);
	~Unit(void);
private:
	Position _position;
};
