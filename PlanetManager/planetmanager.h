#pragma once
#include <string>
#include <vector>

#include "../Shape/body.h"

using namespace std;

class EventTest
{
public:
	EventTest() = default;
	~EventTest() = default;
	EventTest(EventTest &&Other);
	EventTest& operator=(EventTest &&Other);

	void AddPlanet(string const& ObjFileName, glm::vec3 Position, glm::vec3 Velocity, glm::vec3 Acceleration, float Mass);
	void Draw();
	void SetElementPosition(unsigned int Index, glm::vec3& Position);

	friend class EventTestTest;
private:
	vector<Body> m_Planets = {};
};
