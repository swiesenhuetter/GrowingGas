#include "StdAfx.h"
#include "GrowingGas.h"
#include "PatternSet.h"
#include <random>
#include <iostream>



GrowingGas::GrowingGas(const std::vector<Position>& trainingPatterns) : _trainingPatterns(trainingPatterns)
{
    _algo.initialize(*this);
    Unit u1;
    Unit u2;
    addUnit(u1);
    addUnit(u2);
    learnRandomPattern();
}


void GrowingGas::apply(Position pos)
{
    _unit_errors.clear();
    for (auto& unit : _units)
    {
        _unit_errors.push_back(unit.euclideanDistance(pos));
    }
}

void GrowingGas::learnRandomPattern(void)
{
    std::random_device rd;
    std::mt19937 rng(rd());                 // see http://en.wikipedia.org/wiki/Mersenne_twister
    // boost pseudo-random number generator

    std::uniform_int_distribution<size_t> dist(0, _trainingPatterns.size() - 1);	// distribution that maps to 1..numPatterns
    // see random number distributions
    auto index = dist(rng);

    auto err = _algo.teach(_trainingPatterns[index]);

    std::cout << err << " [err]\n";

}

std::array<Unit*, 2> GrowingGas::get2BestMatchingUnits(const Position& pattern)
{
    if (_units.empty())
        return std::array<Unit*, 2> {nullptr, nullptr};

    std::array<Unit*, 2> best2{ &_units.front(), &_units.back()};

    double shortestDistance = best2[0]->euclideanDistance(pattern);
    double secondShortestDistance = shortestDistance;

    auto it = _units.begin();
    auto it_err = _unit_errors.begin();
    for (; it != _units.end() && it_err != _unit_errors.end(); ++it, ++it_err)
    {
        double thisUnitsDistance = *it_err;
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
