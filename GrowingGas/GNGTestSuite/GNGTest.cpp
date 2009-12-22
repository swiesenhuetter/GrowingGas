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

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "GNGTest.h", 7, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_testUnitMove : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testUnitMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 10, "testUnitMove" ) {}
 void runTest() { suite_MyTestSuite.testUnitMove(); }
} testDescription_MyTestSuite_testUnitMove;

static class TestDescription_MyTestSuite_testGrowingGasCreate : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testGrowingGasCreate() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 17, "testGrowingGasCreate" ) {}
 void runTest() { suite_MyTestSuite.testGrowingGasCreate(); }
} testDescription_MyTestSuite_testGrowingGasCreate;

static class TestDescription_MyTestSuite_testFixArray : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testFixArray() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 24, "testFixArray" ) {}
 void runTest() { suite_MyTestSuite.testFixArray(); }
} testDescription_MyTestSuite_testFixArray;

static class TestDescription_MyTestSuite_testImageData2D : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testImageData2D() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "testImageData2D" ) {}
 void runTest() { suite_MyTestSuite.testImageData2D(); }
} testDescription_MyTestSuite_testImageData2D;

#include <cxxtest/Root.cpp>
