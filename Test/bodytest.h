#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "../Shape/body.h"

class BodyTest : public CppUnit::TestFixture
{

CPPUNIT_TEST_SUITE(BodyTest);
CPPUNIT_TEST(testGetMass);
CPPUNIT_TEST(testGetPosition);
CPPUNIT_TEST(testGetVelocity);
CPPUNIT_TEST(testGetAcceleration);
CPPUNIT_TEST(testSetPosition);
CPPUNIT_TEST(testSetVelocity);
CPPUNIT_TEST(testSetAcceleration);
CPPUNIT_TEST(testUpdateOrientation);
CPPUNIT_TEST_SUITE_END();

private:
	Body m_Body = Body("/../Render/sphere.obj", {1.0,0,0}, {1.0,0,0}, {1.0,0,0}, 1.0);
public:
	void setUp() {}
	void tearDown() {}
	void testGetMass();
	void testGetPosition();
	void testGetVelocity();
	void testGetAcceleration();
	void testSetPosition();
	void testSetVelocity();
	void testSetAcceleration();
	void testUpdateOrientation();
};
