#pragma once

#include <list>
#include "Unit2D.h"

template <int dim>
class GrowingGas
{
public:
	GrowingGas(void);
	~GrowingGas(void);
private:
	void LearningAlgorithm(void);
	std::list<Unit2D> _units;
};
