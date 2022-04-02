#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "../Render/objectload.h"

class RenderTest : public CppUnit::TestFixture
{

CPPUNIT_TEST_SUITE(RenderTest);
CPPUNIT_TEST(testParseObjectFile);
CPPUNIT_TEST_SUITE_END();

private:
public:
	void setUp(){}
	void tearDown(){}
	void testParseObjectFile();
};
