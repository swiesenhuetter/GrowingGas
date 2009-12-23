#pragma once

#include "Pattern.h"

struct PatternSet
{
public:
	PatternSet(void){}
	virtual ~PatternSet(void){}
	virtual int size() = 0;
	virtual const Pattern getAt(int position) = 0;
};
