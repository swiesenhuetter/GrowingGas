#pragma once
#include "patternset.h"
#include <vector>

struct pixel
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

class ImageData2D 
	:public PatternSet
{
public:
	ImageData2D();
	virtual ~ImageData2D(void);
	virtual int size();
	virtual const Pattern getAt(int index); // not image specific ... interface
	void createFromFixelArray(pixel* firstPixel, int width, int height);

	static const int redIndex	= 0;
	static const int greenIndex = 1;
	static const int blueIndex	= 2;

private:
	std::vector<pixel> _imageData;
	int _width;
	int _height;
};
