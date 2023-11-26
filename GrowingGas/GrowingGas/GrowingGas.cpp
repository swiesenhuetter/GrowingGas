#include "StdAfx.h"
#include "GrowingGas.h"
#include "PatternSet.h"
#include <random>



GrowingGas::GrowingGas(const std::vector<Position>& trainingPatterns) : _trainingPatterns(trainingPatterns)
{
	// initialize two units
	std::random_device rd;
	std::mt19937 rng(rd());             // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator
	std::uniform_int_distribution<size_t> dist(0,_trainingPatterns.size());	// distribution that maps to 1..numPatterns
										// see random number distributions

	size_t index1 = dist(rng);
	size_t index2 = dist(rng);
	;
	Position p1{ _trainingPatterns[index1] };
	Position p2{ _trainingPatterns[index2] };
	Unit u1(p1);
	Unit u2(p2);
	addUnit(u1);
	addUnit(u2);
}

void GrowingGas::learnRandomPattern( void )
{
	std::random_device rd;
	std::mt19937 rng(rd());                 // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator

	std::uniform_int_distribution<size_t> dist(0, _trainingPatterns.size());	// distribution that maps to 1..numPatterns
										// see random number distributions
	auto index = dist(rng);

	_algo.teach(_trainingPatterns[index]);

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
