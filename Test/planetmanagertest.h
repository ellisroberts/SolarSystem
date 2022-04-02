#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "../EventTest/EventTest.h"

class EventTestTest : public CppUnit::TestFixture
{

CPPUNIT_TEST_SUITE(EventTestTest);
CPPUNIT_TEST(testAddPlanet);
CPPUNIT_TEST(testSetPositionForRequestedIndex);
CPPUNIT_TEST(testSetPositionThrowsException);
CPPUNIT_TEST(testPositionsUpdatedAfterOrbit);
CPPUNIT_TEST_SUITE_END();

private:
	EventTest m_EventTest;
public:
	void setUp() {}
	void tearDown() {}
	void testAddPlanet();
	void testSetPositionForRequestedIndex();
	void testSetPositionThrowsException();
	void testPositionsUpdatedAfterOrbit();
};
