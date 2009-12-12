// MyTestSuite.h
#include <cxxtest/TestSuite.h>
#include "GrowingGas.h"
#include "Unit2D.h"

class MyTestSuite : public CxxTest::TestSuite
{
public:
	void testAddition( void )
	{
		TS_ASSERT( 1 + 1 > 3 );
		TS_ASSERT_EQUALS( 1 + 1, 2 );
	}

	void testUnitMove ( void )
	{
		Position2D pos1 = {1.0, 1.0};
		Unit2D u1(pos1);
	}
};