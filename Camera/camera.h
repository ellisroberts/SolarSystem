#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <memory>

using namespace std;

class Camera
{
public:
	Camera() = default;
	Camera(Camera&& Other) = delete;
	Camera& operator=(Camera& Other) = delete;
	//Rotate the camera along pitch/yaw axis
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
