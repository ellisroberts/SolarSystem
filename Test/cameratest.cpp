#include "cameratest.h"

#include <glm/gtc/constants.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/epsilon.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION(CameraTest);

void CameraTest::testGetPosition()
{
	Camera camera;
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetPosition(), glm::vec3(0, 0, 1), m_Epsilon)));
}
void CameraTest::testGetDirection()
{
	Camera camera;
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetDirection(), glm::vec3(0, 0, -1), m_Epsilon)));
}
void CameraTest::testGetUp()
{
	Camera camera;
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetUp(), glm::vec3(0, 1, 0), m_Epsilon)));
}

void CameraTest::testGetLeft()
{
	Camera camera;
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetLeft(), glm::vec3(-1, 0, 0), m_Epsilon)));
}

void CameraTest::testRotateYaw()
{
	Camera camera;
	camera.Rotate(0, 15);
	camera.Rotate(0, 30);
	camera.Rotate(0, -20);
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetDirection(), glm::vec3(-glm::sin(glm::radians(25.0)), 0 ,-glm::cos(glm::radians(25.0))), m_Epsilon)));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetLeft(), glm::vec3(-glm::cos(glm::radians(25.0)), 0 , glm::sin(glm::radians(25.0))), m_Epsilon)));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetUp(), glm::vec3(0, 1, 0), m_Epsilon)));
}
void CameraTest::testRotatePitch()
{
	Camera camera;
	camera.Rotate(15, 0);
	camera.Rotate(30, 0);
	camera.Rotate(-20, 0);
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetDirection(), glm::vec3(0, -glm::sin(glm::radians(25.0)), -glm::cos(glm::radians(25.0))), m_Epsilon)));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetLeft(), glm::vec3(-1, 0, 0), m_Epsilon)));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetUp(), glm::vec3(0, glm::cos(glm::radians(25.0)), -glm::sin(glm::radians(25.0))), m_Epsilon)));
}

void CameraTest::testRotatePitchYaw()
{
	Camera camera;
	camera.Rotate(45, 45);
	glm::vec3 dir = glm::vec3(-glm::sin(glm::quarter_pi<float>()),
				 	    	  -glm::cos(glm::quarter_pi<float>())*glm::sin(glm::quarter_pi<float>()),
							  -glm::cos(glm::quarter_pi<float>())*glm::cos(glm::quarter_pi<float>()));
	glm::vec3 left = glm::vec3(-glm::cos(glm::quarter_pi<float>()),
					    	   glm::sin(glm::quarter_pi<float>())*glm::sin(glm::quarter_pi<float>()),
							   glm::sin(glm::quarter_pi<float>())*glm::cos(glm::quarter_pi<float>()));
	glm::vec3 up = glm::vec3(0,
				   	   	     glm::sin(glm::quarter_pi<float>()),
							 -glm::cos(glm::quarter_pi<float>()));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetDirection(), dir, m_Epsilon)));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetLeft(), left, m_Epsilon)));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetUp(), up, m_Epsilon)));
}

void CameraTest::testMoveAlongDirection()
{
	Camera camera;
	camera.Move(glm::vec3(0, 0, 1));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetPosition(), glm::vec3(0, 0, 2), m_Epsilon)));
}
void CameraTest::testMoveUpDirection()
{
	Camera camera;
	camera.Move(glm::vec3(0, 1, 0));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetPosition(), glm::vec3(0, 1, 1), m_Epsilon)));
}
void CameraTest::testMoveRight()
{
	Camera camera;
	camera.Move(glm::vec3(1, 0, 0));
	CPPUNIT_ASSERT(glm::all(glm::epsilonEqual(camera.GetPosition(), glm::vec3(1, 0, 1), m_Epsilon)));
}
