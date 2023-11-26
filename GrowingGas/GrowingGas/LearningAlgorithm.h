#pragma once
#include "Pattern.h"

class GrowingGas;

class LearningAlgorithm
{
public:
	LearningAlgorithm( void );
	~LearningAlgorithm( void );

	void teach(const Position& pattern);
	void initialize(GrowingGas& net);
private:
	GrowingGas* _net;
	int _maxEdgeAge;
};
