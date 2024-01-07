#include "StdAfx.h"
#include "LearningAlgorithm.h"
#include "GrowingGas.h"
#include <cassert>


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

void LearningAlgorithm::move_neigbourhood(
	const Position& pattern,
	Unit* center)
{
	pattern; center;

}




double LearningAlgorithm::teach(const Position& pattern)
{
	auto res = _net->get2BestMatchingUnits(pattern);
	
	auto best_matching = res[0];
	auto second_best = res[1];

	if (!best_matching || !second_best)
	{
		assert(false);
	}

	best_matching->towards(pattern, e_b);
	second_best->towards(pattern, e_n);

	best_matching->age_increment();


	auto edge = best_matching->link(*second_best);
	if (edge) {
		_net->_edges.push_back(edge);
	}

	double err = best_matching->euclideanDistance(pattern);


	return err;


	// find best matching unit in _net (bmu)
	// move bmu towards pattern
	// find second best matching unit (sbmu)
	// move sbmu toward pattern
	// bmu.link(sbmu);
	// remove all edges older than _maxEdgeAge
	// remove all units without edges
}

