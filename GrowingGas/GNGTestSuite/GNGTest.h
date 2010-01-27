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

		pixel *imageRGBData = reinterpret_cast<struct pixel*> (_square.GetData());
		_squareData.createFromFixelArray(imageRGBData,_square.GetWidth(),_square.GetHeight());
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


class MyTestSuite : public CxxTest::TestSuite
{
public:

	void testUnitLink ( void )
	{
		Position pos1 = {1.0, 1.0};
		Position pos2 = {2.0, 2.0};
		Unit u1(pos1);
		Unit u2(pos2);
		Unit u3;
		u1.link(u2);
		TS_ASSERT(u1.isNeigbour(u2));
		TS_ASSERT(u2.isNeigbour(u1));
		TS_ASSERT(! u2.isNeigbour(u2));
		TS_ASSERT(! u1.isNeigbour(u1));
		TS_ASSERT(! u3.isNeigbour(u1));
		TS_ASSERT(! u3.isNeigbour(u2));
		TS_ASSERT(! u1.isNeigbour(u3));
		TS_ASSERT(! u2.isNeigbour(u3));

		TS_ASSERT(! u1.isSingle());
		TS_ASSERT(! u2.isSingle());
		TS_ASSERT(u3.isSingle());

		TS_ASSERT_EQUALS(u1.getNeighbours().size(), 1);
		TS_ASSERT_EQUALS(u2.getNeighbours().size(), 1);
		TS_ASSERT_EQUALS(u3.getNeighbours().size(), 0);

	}

	void testFixArray( void )
	{
		boost::array<int,7> fixArray = {1,2,3,4};
		TS_ASSERT_EQUALS( fixArray[3], 4 );
		TS_ASSERT_EQUALS( fixArray[4], 0 );
	}

	void testImageData2D( void )
	{
		ImageData2D data;
		TS_ASSERT_EQUALS( data.size() , 0 );
	}
};