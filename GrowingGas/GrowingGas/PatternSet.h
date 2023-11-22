#pragma once

#include "Pattern.h"

struct PatternSet
{
public:
	PatternSet(void){}
	virtual ~PatternSet(void){}
	virtual size_t size() = 0;
	virtual const Pattern getAt(size_t position) = 0;
};
