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
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "GNGTest.h", 6, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 9, "testAddition" ) {}
 void runTest() { suite_MyTestSuite.testAddition(); }
} testDescription_MyTestSuite_testAddition;

static class TestDescription_MyTestSuite_testUnitMove : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_testUnitMove() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "testUnitMove" ) {}
 void runTest() { suite_MyTestSuite.testUnitMove(); }
} testDescription_MyTestSuite_testUnitMove;

#include <cxxtest/Root.cpp>
