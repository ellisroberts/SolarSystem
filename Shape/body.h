#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <string>

using namespace std;

class Body
{
public:
	Body() = default;
	Body(glm::vec3 const& Pos,
		 glm::vec3 const &Velocity,
		 glm::vec3 const &Acceleration,
		 float const Mass) :
		 m_Pos {Pos},
		 m_Velocity {Velocity},
		 m_Acceleration {Acceleration},
		 m_Mass {Mass}
	{
	}
	~Body() = default;
	Body(Body const& Other):
		 m_Pos {Other.m_Pos},
		 m_Velocity {Other.m_Velocity},
		 m_Acceleration {Other.m_Acceleration},
		 m_Mass {Other.m_Mass}
	{
	}

	Body& operator=(Body const& Other) = delete;
	static float GetGravitationalConstant()
	{
		return m_GravitationalConstant;
	}
	float GetMass()
	{
		return m_Mass;
	}
	glm::vec3 GetPosition()
	{
		return m_Pos;
	}
	glm::vec3 GetVelocity()
	{
		return m_Velocity;
	}
	glm::vec3 GetAcceleration()
	{
		return m_Acceleration;
	}
	//Reposition Body in world space
	void SetPosition(glm::vec3 const &Position)
	{
		m_Pos = Position;
	}
	//Set velocity
	void SetVelocity(glm::vec3 const &Velocity)
	{
		m_Velocity = Velocity;
	}
	//Set Acceleration
	void SetAcceleration(glm::vec3 const &Acceleration)
	{
		m_Acceleration = Acceleration;
	}

	//TBD : This function updates vectors based on gravitational attraction
	//Need to make sure update is always synchronized with frame rate, must be agnostic to opengl context/instance
	void UpdateOrientation();


private:
	//Position of the planet in world space
	glm::vec3 m_Pos = {0.0, 0.0, 0.0};
	//Velocity vector of the planet
	glm::vec3 m_Velocity = {0.0, 0.0, 0.0};
	//Acceleration of the planet
	glm::vec3 m_Acceleration = {0.0, 0.0, 0.0};
	//Mass of planet
	float const m_Mass = 0.0;
	static constexpr float m_GravitationalConstant = 10000.0;
};
