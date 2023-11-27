#pragma once
#include "Pattern.h"

class GrowingGas;
class Unit;

class LearningAlgorithm
{
public:
	LearningAlgorithm(void);
	~LearningAlgorithm(void);

	void move_neigbourhood(const Position& pattern, Unit* center);

	double teach(const Position& pattern);
	void initialize(GrowingGas& net);
private:
	GrowingGas* _net{ nullptr };
	int _maxEdgeAge{ 50 };

	double e_b{ 0.2 };
	double e_n{ 0.006 };
	double alpha{ 0.5 };
	double d{ 0.995 };
};
