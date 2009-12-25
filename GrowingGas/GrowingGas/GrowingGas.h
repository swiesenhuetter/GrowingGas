#pragma once
#include "Unit.h"
#include "LearningAlgorithm.h"
#include <list>

struct PatternSet;

class GrowingGas
{
public:
	GrowingGas(PatternSet& trainingPatterns);
	~GrowingGas(void);
	int numUnits(void) {
		return _units.size();
	}
	void addUnit(Unit newUnit) {
		_units.push_back(newUnit);
	}


private:
	LearningAlgorithm _algo;
	std::list<Unit> _units;
	std::list<Edge> _edges;

	PatternSet& _trainingPatterns;
	GrowingGas& operator=(const GrowingGas&) {}// forbidden because of non static reference data member

	void learnRandomPattern( void );
};
