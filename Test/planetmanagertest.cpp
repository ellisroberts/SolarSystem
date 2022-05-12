#include "planetmanagertest.h"

#include <exception>
#include <glm/glm.hpp>
#include <stdexcept>


CPPUNIT_TEST_SUITE_REGISTRATION(PlanetManagerTest);

void PlanetManagerTest::testAddPlanet()
{
	m_PlanetManager.AddPlanet({1.0,0,0}, {1.0,0,0}, {1.0,0,0}, 1.0);
	CPPUNIT_ASSERT(m_PlanetManager.GetPlanets().size() == 1);
}

void PlanetManagerTest::testSetPositionForRequestedIndex()
{
	m_PlanetManager.AddPlanet({1.0,0,0}, {1.0,0,0}, {1.0,0,0}, 1.0);
	glm::vec3 newPos = {2.0, 0, 0};
	m_PlanetManager.SetElementPosition(0, newPos);
	CPPUNIT_ASSERT(m_PlanetManager.GetPlanets()[0].GetPosition() == glm::vec3(2.0, 0.0, 0.0));
}
void PlanetManagerTest::testSetPositionThrowsException()
{
	bool exceptionThrown = false;
	try
	{
		glm::vec3 newPos = {2.0, 0, 0};
		m_PlanetManager.SetElementPosition(0, newPos);
	}
	catch (std::out_of_range &except)
	{
		exceptionThrown = true;
	}
	CPPUNIT_ASSERT(exceptionThrown == true);

}
void PlanetManagerTest::testPositionsUpdatedAfterOrbit()
{

}
