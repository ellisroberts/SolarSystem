#include "camera.h"
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>

#include <glm/gtc/constants.hpp>
#include <glm/gtx/rotate_vector.hpp>

Camera& Camera::operator=(Camera const& Other)
{
	m_Pos = Other.m_Pos;
	m_Direction = Other.m_Direction;
	m_Up = Other.m_Up;
	m_Left = Other.m_Left;
	return *this;
}

//Rotate the camera along pitch/yaw axis
void Camera::Rotate(float DeltaPitch, float DeltaYaw)
{
	if (DeltaPitch)
	{
		m_Direction = glm::rotate(m_Direction, glm::radians(DeltaPitch), m_Left);
		m_Up = glm::rotate(m_Up, glm::radians(DeltaPitch), m_Left);
	}
	if (DeltaYaw)
	{
		m_Direction = glm::rotate(m_Direction, glm::radians(DeltaYaw), m_Up);
		m_Left = glm::rotate(m_Left, glm::radians(DeltaYaw), m_Up);
	}
}

//Move camera along direction of desired axis
void Camera::Move(glm::vec3 Dir)
{
	m_Pos += Dir;
}

