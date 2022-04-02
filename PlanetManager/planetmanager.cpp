#include "EventTest.h"

#include <iostream>
#include <stdexcept>

EventTest::EventTest(EventTest &&Other)
{
	m_Planets = std::move(Other.m_Planets);
	Other.m_Planets.clear();
}

EventTest& EventTest::operator=(EventTest &&Other)
{
	m_Planets = std::move(Other.m_Planets);
	Other.m_Planets.clear();
	return *this;
}

void EventTest::AddPlanet(string const& ObjFileName, glm::vec3 Position, glm::vec3 Velocity, glm::vec3 Acceleration, float Mass)
{
	m_Planets.emplace_back(ObjFileName, Position, Velocity, Acceleration, Mass);
}

void EventTest::SetElementPosition(unsigned int Index, glm::vec3& Position)
{
	if (Index >= m_Planets.size())
	{
		throw std::out_of_range("Index is beyond the range of element!");
	}
	m_Planets[Index].SetPosition(Position);
}
