#pragma once
#include "patternset.h"
#include <vector>

struct Pixel
{
	unsigned char red{0};
	unsigned char green{0};
	unsigned char blue{0};
};

class ImageData2D 
	:public PatternSet
{
public:
	ImageData2D();
	virtual ~ImageData2D(void);
	virtual size_t size();
	virtual const Pattern getAt(size_t index); // not image specific ... interface
	void createFromPixelArray(Pixel* firstPixel, int width, int height);

	static const int redIndex	= 0;
	static const int greenIndex = 1;
	static const int blueIndex	= 2;

private:
	std::vector<Pixel> _imageData;
	int _width{0};
	int _height{0};
};
