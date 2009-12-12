#pragma once

#include <list>
#include "Unit.h"
#include "LearningAlgorithm.h"

class GrowingGas
{
public:
	GrowingGas(void);
	~GrowingGas(void);

private:
	LearningAlgorithm _algo;
	std::list<Unit> _units;
};
