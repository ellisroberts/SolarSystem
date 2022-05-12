#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "../PlanetManager/planetmanager.h"

class PlanetManagerTest : public CppUnit::TestFixture
{

CPPUNIT_TEST_SUITE(PlanetManagerTest);
CPPUNIT_TEST(testAddPlanet);
CPPUNIT_TEST(testSetPositionForRequestedIndex);
CPPUNIT_TEST(testSetPositionThrowsException);
CPPUNIT_TEST(testPositionsUpdatedAfterOrbit);
CPPUNIT_TEST_SUITE_END();

private:
	PlanetManager m_PlanetManager;
public:
	void setUp() {}
	void tearDown() {}
	void testAddPlanet();
	void testSetPositionForRequestedIndex();
	void testSetPositionThrowsException();
	void testPositionsUpdatedAfterOrbit();
};
