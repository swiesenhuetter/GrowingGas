/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ParenPrinter.h>

int main() {
 return CxxTest::ParenPrinter().run();
}
#include "GNGTest.h"

static PatternTestSuite *suite_PatternTestSuite = 0;

static CxxTest::List Tests_PatternTestSuite = { 0, 0 };
CxxTest::DynamicSuiteDescription<PatternTestSuite> suiteDescription_PatternTestSuite( "GNGTest.h", 10, "PatternTestSuite", Tests_PatternTestSuite, suite_PatternTestSuite, 14, 18 );

static class TestDescription_PatternTestSuite_testNumberOfPixels : public CxxTest::RealTestDescription {
public:
 TestDescription_PatternTestSuite_testNumberOfPixels() : CxxTest::RealTestDescription( Tests_PatternTestSuite, suiteDescription_PatternTestSuite, 46, "testNumberOfPixels" ) {}
 void runTest() { if ( suite_PatternTestSuite ) suite_PatternTestSuite->testNumberOfPixels(); }
} testDescription_PatternTestSuite_testNumberOfPixels;

static class TestDescription_PatternTestSuite_testWhiteDiagonal : public CxxTest::RealTestDescription {
public:
 TestDescription_PatternTestSuite_testWhiteDiagonal() : CxxTest::RealTestDescription( Tests_PatternTestSuite, suiteDescription_PatternTestSuite, 51, "testWhiteDiagonal" ) {}
 void runTest() { if ( suite_PatternTestSuite ) suite_PatternTestSuite->testWhiteDiagonal(); }
} testDescription_PatternTestSuite_testWhiteDiagonal;

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "GNGTest.h", 66, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_testUnitMove : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testUnitMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 69, "testUnitMove" ) {}
 void runTest() { suite_MyTestSuite.testUnitMove(); }
} testDescription_MyTestSuite_testUnitMove;

static class TestDescription_MyTestSuite_testGrowingGasCreate : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testGrowingGasCreate() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 76, "testGrowingGasCreate" ) {}
 void runTest() { suite_MyTestSuite.testGrowingGasCreate(); }
} testDescription_MyTestSuite_testGrowingGasCreate;

static class TestDescription_MyTestSuite_testFixArray : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testFixArray() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 83, "testFixArray" ) {}
 void runTest() { suite_MyTestSuite.testFixArray(); }
} testDescription_MyTestSuite_testFixArray;

static class TestDescription_MyTestSuite_testImageData2D : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testImageData2D() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 90, "testImageData2D" ) {}
 void runTest() { suite_MyTestSuite.testImageData2D(); }
} testDescription_MyTestSuite_testImageData2D;

#include <cxxtest/Root.cpp>
