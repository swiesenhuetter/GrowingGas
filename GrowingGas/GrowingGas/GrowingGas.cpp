#include "StdAfx.h"
#include "GrowingGas.h"
#include "PatternSet.h"
#include <random>

GrowingGas::GrowingGas(PatternSet& trainingPatterns)
:_trainingPatterns(trainingPatterns)
{
	std::random_device rd;
	std::mt19937 rng(rd());                 // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator
	std::uniform_int_distribution<> dist(0,_trainingPatterns.size());	// distribution that maps to 1..numPatterns
										// see random number distributions

	int index = dist(rng);
	double x = _trainingPatterns.getAt(index).position[Pattern::horizontal];
	double y = _trainingPatterns.getAt(index).position[Pattern::vertical];
	Position p1 = {x,y};
	index = dist(rng);
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
	std::random_device rd;
	std::mt19937 rng(rd());                 // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator

	std::uniform_int_distribution<> dist(0, _trainingPatterns.size());	// distribution that maps to 1..numPatterns
										// see random number distributions
	int index = dist(rng);

	_algo.teach(_trainingPatterns.getAt(index));

}

std::array<Unit*,2> GrowingGas::get2BestMatchingUnits( const Position& pattern)
{
	std::array<Unit*,2> best2 = {0,0};
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
