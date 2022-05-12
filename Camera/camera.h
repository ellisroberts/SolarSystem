#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>

using namespace std;

class Camera
{
public:
	Camera() = default;
	Camera(glm::vec3 const& Pos,
		   glm::vec3 const& Dir,
		   glm::vec3 const& Up,
		   glm::vec3 const& Left) :
		   m_Pos {Pos},
		   m_Direction {Dir},
		   m_Up {Up},
		   m_Left {Left}
	{
	}
	Camera(Camera const& Other) :
		m_Pos {Other.m_Pos},
		m_Direction {Other.m_Direction},
		m_Up {Other.m_Up},
		m_Left {Other.m_Left}
	{
	}
	Camera& operator=(Camera const& Other);
	//Rotate the camera along pitch/yaw axis
	//Yaw would rotate around the "Up" axis
	//Pitch would rotate around the "Left" axis
	void Rotate(float DeltaPitch, float DeltaYaw);
	//Move camera along direction of desired axis
	void Move(glm::vec3 Dir);
	//Get Position of Camera in world space
	glm::vec3 GetPosition() {return m_Pos;}
	//Get Forward Direction vector of Camera
	glm::vec3 GetDirection() {return m_Direction;}
	//Get Up Vector
	glm::vec3 GetUp() {return m_Up;}
	//Get Left Vector
	glm::vec3 GetLeft() {return m_Left;}


private:
	//Position of camera in world space
	glm::vec3 m_Pos = {0, 0, 1};
	//Direction vector
	glm::vec3 m_Direction = {0, 0, -1};
	//Up Vector
	glm::vec3 m_Up = {0, 1, 0};
	//Left Vector
	glm::vec3 m_Left = {-1, 0, 0};
};
