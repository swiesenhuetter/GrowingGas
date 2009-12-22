#include "StdAfx.h"
#include "GrowingGas.h"
#pragma warning(disable:4127 4512 4100) // a constant in an if in boost header file and...
#include <boost/random.hpp>
#pragma warning(default:4127 4512 4100)

GrowingGas::GrowingGas(void)
{
	boost::mt19937 rng;                 // produces randomness out of thin air
										// see pseudo-random number generators
	boost::uniform_int<> six(1,200);       // distribution that maps to 1..6
	//									// see random number distributions
	boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(rng, six);					// glues randomness with mapping
	int x = die();                      // simulate rolling a die
	int y = die();
	Position p1 = {x,y};
	x = die();
	y = die();
	Position p2 = {x,y};

	Unit u1(p1);
	Unit u2(p2);
	_units.push_back(u1);
	_units.push_back(u2);
}

GrowingGas::~GrowingGas(void)
{
}