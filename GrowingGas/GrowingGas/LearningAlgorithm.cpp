#include "StdAfx.h"
#include "LearningAlgorithm.h"
#include "GrowingGas.h"

LearningAlgorithm::LearningAlgorithm()
{
}

void LearningAlgorithm::initialize(GrowingGas& net)
{
	_net = &net;
}

LearningAlgorithm::~LearningAlgorithm(void)
{
}

void LearningAlgorithm::teach(const Position& pattern)
{
	pattern;
	// find best matching unit in _net (bmu)
	// move bmu towards pattern
	// find second best matching unit (sbmu)
	// move sbmu toward pattern
	// bmu.link(sbmu);
	// remove all edges older than _maxEdgeAge
	// remove all units without edges
}

