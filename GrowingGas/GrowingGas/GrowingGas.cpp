#include "StdAfx.h"
#include "GrowingGas.h"
#include "PatternSet.h"
#include <random>
#include <iostream>



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

	_algo.initialize(*this);
}

void GrowingGas::learnRandomPattern( void )
{
	std::random_device rd;
	std::mt19937 rng(rd());                 // see http://en.wikipedia.org/wiki/Mersenne_twister
										// boost pseudo-random number generator

	std::uniform_int_distribution<size_t> dist(0, _trainingPatterns.size()-1);	// distribution that maps to 1..numPatterns
										// see random number distributions
	auto index = dist(rng);

	auto err = _algo.teach(_trainingPatterns[index]);

	std::cout << err << "err \n";

}

std::array<Unit*,2> GrowingGas::get2BestMatchingUnits( const Position& pattern)
{
	if (_units.empty())
		return std::array<Unit*,2> {nullptr, nullptr};

	std::array<Unit*, 2> best2{ &_units.front(), &_units.front()};

	double shortestDistance = best2[0]->euclideanDistance(pattern);
	double secondShortestDistance = shortestDistance;

	std::list<Unit>::iterator it;
	for(it = _units.begin(); it != _units.end(); ++it)
	{
		double thisUnitsDistance = it->euclideanDistance(pattern);
		if (thisUnitsDistance < shortestDistance)
		{
			best2[1] = best2[0];
			secondShortestDistance = shortestDistance;
			best2[0] = &(*it);
			shortestDistance = thisUnitsDistance;
			
		}
		else if (thisUnitsDistance < secondShortestDistance)
		{
			best2[1] = &(*it);
			secondShortestDistance = thisUnitsDistance;
		}
	}
	return best2;
}
