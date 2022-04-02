#pragma once
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include "../Camera/camera.h"

class CameraTest : public CppUnit::TestFixture
{

CPPUNIT_TEST_SUITE(CameraTest);
CPPUNIT_TEST(testGetPosition);
CPPUNIT_TEST(testGetDirection);
CPPUNIT_TEST(testGetUp);
CPPUNIT_TEST(testGetLeft);
CPPUNIT_TEST(testRotateYaw);
CPPUNIT_TEST(testRotatePitch);
CPPUNIT_TEST(testRotatePitchYaw);
CPPUNIT_TEST(testMoveAlongDirection);
CPPUNIT_TEST(testMoveUpDirection);
CPPUNIT_TEST(testMoveRight);
CPPUNIT_TEST_SUITE_END();

private:
	float const m_Epsilon = .00005;
public:
	void setUp() {}
	void tearDown() {}
	void testGetPosition();
	void testGetDirection();
	void testGetUp();
	void testGetLeft();
	void testRotateYaw();
	void testRotatePitch();
	void testRotatePitchYaw();
	void testMoveAlongDirection();
	void testMoveUpDirection();
	void testMoveRight();
};
