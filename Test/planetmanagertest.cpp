#include "EventTesttest.h"

#include <exception>
#include <stdexcept>


CPPUNIT_TEST_SUITE_REGISTRATION(EventTestTest);

void EventTestTest::testAddPlanet()
{
	m_EventTest.AddPlanet("/../Render/sphere.obj", {1.0,0,0}, {1.0,0,0}, {1.0,0,0}, 1.0);
	CPPUNIT_ASSERT(m_EventTest.m_Planets.size() == 1);
}

void EventTestTest::testSetPositionForRequestedIndex()
{
	m_EventTest.AddPlanet("/../Render/sphere.obj", {1.0,0,0}, {1.0,0,0}, {1.0,0,0}, 1.0);
	glm::vec3 newPos = {2.0, 0, 0};
	m_EventTest.SetElementPosition(0, newPos);
	CPPUNIT_ASSERT(m_EventTest.m_Planets[0].GetPosition() == glm::vec3(2.0, 0.0, 0.0));
}
void EventTestTest::testSetPositionThrowsException()
{
	bool exceptionThrown = false;
	try
	{
		glm::vec3 newPos = {2.0, 0, 0};
		m_EventTest.SetElementPosition(0, newPos);
	}
	catch (std::out_of_range &except)
	{
		exceptionThrown = true;
	}
	CPPUNIT_ASSERT(exceptionThrown == true);

}
void EventTestTest::testPositionsUpdatedAfterOrbit()
{

}
