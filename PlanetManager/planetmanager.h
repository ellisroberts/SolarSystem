#pragma once

#include "../Shape/body.h"

#include <string>
#include <vector>

using namespace std;

class PlanetManager
{
public:
	PlanetManager() = default;
	~PlanetManager() = default;
	PlanetManager(PlanetManager &&Other);
	PlanetManager& operator=(PlanetManager &&Other);

	//Add Planet with specified parameters to collection of planets
	void AddPlanet(glm::vec3 const& Position,
				   glm::vec3 const& Velocity,
				   glm::vec3 const& Acceleration,
				   float Mass);
	void Draw();
	vector<Body> GetPlanets() {return m_Planets;}
	//Set Position of requested planet specified by index
	void SetElementPosition(unsigned int Index, glm::vec3& Position);

private:
	vector<Body> m_Planets = {};
};
