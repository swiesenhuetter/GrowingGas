// MyTestSuite.h
#include <cxxtest/TestSuite.h>
#include "GrowingGas.h"
#include "Unit.h"
#include "ImageData2D.h"

class MyTestSuite : public CxxTest::TestSuite
{
public:
	void testUnitMove ( void )
	{
		Position pos1 = {1.0, 1.0};
		Unit u1(pos1);
		TS_ASSERT(1);
	}

	void testGrowingGasCreate ( void )
	{
		GrowingGas gg;
		int numberOfUnits = gg.numUnits();
		TS_ASSERT_EQUALS( numberOfUnits, 2 );
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
	}
};