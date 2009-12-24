#include "StdAfx.h"
#include "ImageData2D.h"

ImageData2D::ImageData2D()
{
}

ImageData2D::~ImageData2D(void)
{
}

int ImageData2D::size(void)
{
	return _imageData.size();
}

const Pattern ImageData2D::getAt(int index)
{
	int x = index % _width;
	int y = index / _width;
	Pattern pPos;
	pPos.position[0] = x;
	pPos.position[1] = y;
	pPos.output[redIndex]	= _imageData[index].red;
	pPos.output[greenIndex]	= _imageData[index].green;
	pPos.output[blueIndex]	= _imageData[index].blue;
	return pPos;
}

void ImageData2D::createFromFixelArray(pixel* firstPixel, int width, int height)
{
	_width = width;
	_height = height;
	int numPixel = _height*_width;
	_imageData.resize(numPixel);											//allocate
	for (int i=0; i < numPixel; ++i)
	{
		_imageData[i] = firstPixel[i];										// copy from image memory
	}
}
