#include "planetmanager.h"

#include <iostream>
#include <stdexcept>

PlanetManager::PlanetManager(PlanetManager &&Other)
{
	m_Planets = std::move(Other.m_Planets);
	Other.m_Planets.clear();
}

PlanetManager& PlanetManager::operator=(PlanetManager &&Other)
{
	m_Planets = std::move(Other.m_Planets);
	Other.m_Planets.clear();
	return *this;
}

void PlanetManager::AddPlanet(glm::vec3 const& Position,
							  glm::vec3 const& Velocity,
							  glm::vec3 const& Acceleration,
							  float Mass)
{
	m_Planets.emplace_back(Position, Velocity, Acceleration, Mass);
}

void PlanetManager::SetElementPosition(unsigned int Index, glm::vec3& Position)
{
	if (Index >= m_Planets.size())
	{
		throw std::out_of_range("Index is beyond the range of element!");
	}
	m_Planets[Index].SetPosition(Position);
}
