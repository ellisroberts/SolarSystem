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
	Body(string const& ObjFile,
		 glm::vec3 const& Pos,
		 glm::vec3 const &Velocity,
		 glm::vec3 const &Acceleration,
		 float const Mass);
	~Body();
	Body(Body &&Other);
	Body& operator=(Body &&Other);
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
private:
	GLuint m_VAO = 0;
	GLuint m_VBO = 0;
	GLuint m_TextureVBO = 0;
	GLuint m_NormalVBO = 0;
	//Number of vertices
	GLuint m_NumVertices = 0;
	//Position of the planet in world space
	glm::vec3 m_Pos = {0.0, 0.0, 0.0};
	//Velocity vector of the planet
	glm::vec3 m_Velocity = {0.0, 0.0, 0.0};
	//Acceleration of the planet
	glm::vec3 m_Acceleration = {0.0, 0.0, 0.0};
	//Mass of planet
	float m_Mass = 0.0;
	static constexpr float m_GravitationalConstant = 10000.0;
};
