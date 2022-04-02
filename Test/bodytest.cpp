#include "bodytest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(BodyTest);

void BodyTest::testGetMass()
{
	CPPUNIT_ASSERT(m_Body.GetMass() == 1.0);
}
void BodyTest::testGetPosition()
{
	glm::vec3 initPos = {1.0, 0.0, 0.0};
	CPPUNIT_ASSERT(m_Body.GetPosition() == initPos);
}

void BodyTest::testGetVelocity()
{
	glm::vec3 initVel = {1.0, 0.0, 0.0};
	CPPUNIT_ASSERT(m_Body.GetVelocity() == initVel);
}

void BodyTest::testGetAcceleration()
{
	glm::vec3 initAccel = {1.0, 0.0, 0.0};
	CPPUNIT_ASSERT(m_Body.GetAcceleration() == initAccel);
}

void BodyTest::testSetPosition()
{
	glm::vec3 newPosition = {10.0, 3.0, -2.0};
	m_Body.SetPosition(newPosition);
	CPPUNIT_ASSERT(m_Body.GetPosition() == newPosition);
}

void BodyTest::testSetVelocity()
{
	glm::vec3 newVelocity= {10.0, 3.0, -2.0};
	m_Body.SetVelocity(newVelocity);
	CPPUNIT_ASSERT(m_Body.GetVelocity() == newVelocity);
}

void BodyTest::testSetAcceleration()
{
	glm::vec3 newAcceleration = {10.0, 3.0, -2.0};
	m_Body.SetAcceleration(newAcceleration);
	CPPUNIT_ASSERT(m_Body.GetAcceleration() == newAcceleration);
}

void BodyTest::testUpdateOrientation()
{

}
