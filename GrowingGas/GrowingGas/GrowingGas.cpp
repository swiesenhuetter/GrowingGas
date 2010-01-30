#include "StdAfx.h"
#include "GrowingGas.h"
#include "PatternSet.h"
#pragma warning(disable:4127 4512 4100) // a constant in an if in boost header file and...
#include <boost/random.hpp>
#pragma warning(default:4127 4512 4100)

GrowingGas::GrowingGas(PatternSet& trainingPatterns)
:_trainingPatterns(trainingPatterns)
{
	boost::mt19937 rng;                 // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator
	boost::uniform_int<> dist(0,_trainingPatterns.size());	// distribution that maps to 1..numPatterns
										// see random number distributions
	boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(rng, dist);	// glues randomness with mapping
	int index = die();
	double x = _trainingPatterns.getAt(index).position[Pattern::horizontal];
	double y = _trainingPatterns.getAt(index).position[Pattern::vertical];
	Position p1 = {x,y};
	index = die();
	x = _trainingPatterns.getAt(index).position[Pattern::horizontal];
	y = _trainingPatterns.getAt(index).position[Pattern::vertical];
	Position p2 = {x,y};
	Unit u1(p1);
	Unit u2(p2);
	addUnit(u1);
	addUnit(u2);
}

GrowingGas::~GrowingGas(void)
{
}

void GrowingGas::learnRandomPattern ( void )
{
	boost::mt19937 rng;                 // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator
	boost::uniform_int<> dist(0,_trainingPatterns.size());	// distribution that maps to 1..numPatterns
										// see random number distributions
	boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(rng, dist);	// glues randomness with mapping
	int index = die();

	_algo.teach(_trainingPatterns.getAt(index));

}

boost::array<Unit*,2> GrowingGas::get2BestMatchingUnits( const Position& pattern)
{
	boost::array<Unit*,2> best2 = {0,0};
	std::list<Unit>::iterator it;
	for(it = _units.begin(); it != _units.end(); ++it)
	{
		if (best2[0])
		{
			double currentBestDistance = best2[0]->euclideanDistance(pattern);
			double thisUnitsDistance = it->euclideanDistance(pattern);
			if (thisUnitsDistance < currentBestDistance)
			{
				best2[0] = &(*it);
			}
		}
	}
	return best2;
}
