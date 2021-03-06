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

static class TestDescription_PatternTestSuite_testGrowingGasCreate : public CxxTest::RealTestDescription {
public:
 TestDescription_PatternTestSuite_testGrowingGasCreate() : CxxTest::RealTestDescription( Tests_PatternTestSuite, suiteDescription_PatternTestSuite, 61, "testGrowingGasCreate" ) {}
 void runTest() { if ( suite_PatternTestSuite ) suite_PatternTestSuite->testGrowingGasCreate(); }
} testDescription_PatternTestSuite_testGrowingGasCreate;

static class TestDescription_PatternTestSuite_testTwoBest : public CxxTest::RealTestDescription {
public:
 TestDescription_PatternTestSuite_testTwoBest() : CxxTest::RealTestDescription( Tests_PatternTestSuite, suiteDescription_PatternTestSuite, 68, "testTwoBest" ) {}
 void runTest() { if ( suite_PatternTestSuite ) suite_PatternTestSuite->testTwoBest(); }
} testDescription_PatternTestSuite_testTwoBest;

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "GNGTest.h", 88, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_testUnitLink : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testUnitLink() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 92, "testUnitLink" ) {}
 void runTest() { suite_MyTestSuite.testUnitLink(); }
} testDescription_MyTestSuite_testUnitLink;

static class TestDescription_MyTestSuite_testFixArray : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testFixArray() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 119, "testFixArray" ) {}
 void runTest() { suite_MyTestSuite.testFixArray(); }
} testDescription_MyTestSuite_testFixArray;

static class TestDescription_MyTestSuite_testImageData2D : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testImageData2D() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 126, "testImageData2D" ) {}
 void runTest() { suite_MyTestSuite.testImageData2D(); }
} testDescription_MyTestSuite_testImageData2D;

static class TestDescription_MyTestSuite_testDistance : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testDistance() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 132, "testDistance" ) {}
 void runTest() { suite_MyTestSuite.testDistance(); }
} testDescription_MyTestSuite_testDistance;

#include <cxxtest/Root.cpp>
