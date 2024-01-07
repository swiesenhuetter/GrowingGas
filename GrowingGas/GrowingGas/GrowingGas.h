#pragma once
#include "Unit.h"
#include "Pattern.h"
#include "LearningAlgorithm.h"
#include <list>
#include <vector>
#include <memory>


class GrowingGas
{
public:
    GrowingGas(const std::vector<Position>& trainingPatterns);

    ~GrowingGas() = default;

    size_t numUnits(void) {
        return _units.size();
    }
    void addUnit(Unit newUnit) {
        _units.push_back(newUnit);
    }
    void learnRandomPattern( void );
    std::array<Unit*,2> get2BestMatchingUnits( const Position& pattern);

	friend class LearningAlgorithm;

private:
    LearningAlgorithm _algo;
    std::list<Unit> _units;
    std::list<std::shared_ptr<Edge>> _edges;

    const std::vector<Position>& _trainingPatterns;
    GrowingGas& operator=(const GrowingGas&) {}// forbidden because of non static reference data member

};
