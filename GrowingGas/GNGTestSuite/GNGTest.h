// MyTestSuite.h
#include <cxxtest/TestSuite.h>
#include "GrowingGas.h"
#include "Unit.h"
#include "ImageData2D.h"

#include <wx\wx.h>


class PatternTestSuite : public CxxTest::TestSuite
{
public:

	static PatternTestSuite *createSuite( void ) 
	{
		return new PatternTestSuite(4);
	}
	static void destroySuite( PatternTestSuite *suite ) 
	{
		delete suite;
	}

	PatternTestSuite( int width )		
		:_square(width,width,true)		// a black square
	{
	}

	void setUp( void )					// white diagonal
	{
		const int redChannel	= 0xff;
		const int greenChannel	= 0xff;
		const int blueChannel	= 0xff;
		for (int i=0; i < _square.GetHeight() && i < _square.GetHeight(); ++i)
		{
			_square.SetRGB(i,i,redChannel,greenChannel,blueChannel);
		}

		Pixel *imageRGBData = reinterpret_cast<struct Pixel*> (_square.GetData());
		_squareData.createFromPixelArray(imageRGBData,_square.GetWidth(),_square.GetHeight());
	}

	void tearDown( void )
	{
	}

	void testNumberOfPixels ( void )
	{
		TS_ASSERT_EQUALS( _squareData.size() , 16);
	}

	void testWhiteDiagonal ( void )
	{
		TS_ASSERT_EQUALS( _squareData.getAt(0).output[2], 255);										// 1 0 0 0 (0..3)
		TS_ASSERT_EQUALS( _squareData.getAt(1).output[2], 0);										// 0 1 0 0 (4..7)
		TS_ASSERT_EQUALS( _squareData.getAt(5).output[2], 255);										// 0 0 1 0 (8..11)
		TS_ASSERT_EQUALS( _squareData.getAt(6).output[2] , 0);										// 0 0 0 1 (12..15)
		TS_ASSERT_EQUALS( _squareData.getAt(15).output[0], 255);
		TS_ASSERT_EQUALS( _squareData.getAt(14).output[0], 0);
	}

	void testGrowingGasCreate ( void )
	{
		GrowingGas gg(_squareData);
		int numberOfUnits = gg.numUnits();
		TS_ASSERT_EQUALS( numberOfUnits, 2 );
	}


private:
	wxImage _square;
	ImageData2D _squareData;
};

	void testImageData2D( void )
	{
		ImageData2D data;
		TS_ASSERT_EQUALS( data.size() , 0 );
	}

};