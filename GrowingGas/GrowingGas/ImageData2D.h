#pragma once
#include "patternset.h"

class ImageData2D :
	public PatternSet
{
public:
	ImageData2D(void);
	virtual ~ImageData2D(void);
	virtual int size();
	virtual const Pattern* getAt(int position);

};
