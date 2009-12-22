#pragma once

#include <list>
#include "Unit.h"
#include "LearningAlgorithm.h"

class GrowingGas
{
public:
	GrowingGas(void);
	~GrowingGas(void);
	int numUnits(void) {return _units.size(); }
private:
	LearningAlgorithm _algo;
	std::list<Unit> _units;
};
