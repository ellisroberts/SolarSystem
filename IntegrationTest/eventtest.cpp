#include "eventtest.h"

#include "../EventGenerator/eventgenerator.h"


#include <vector>

bool EventTest::testMouseButtonClickMove(EventTest &const Planets, Camera &InCamera)
{
	bool result = false;
	EventGenerator::MouseClick();
	EventGenerator::HoldW(2);
	EventGenerator::MoveCursor(-1, -1);
	auto planets = Planets.m_Planets;
	if ((planets.size() == 1) && (glm::all(glm::epsilonEqual(planets.front().GetPosition(), InCamera.GetPosition() + InCamera.GetDirection(), m_Epsilon))))
	{
		result = true;
	}
	return result;
}

void EventTest::testMouseButtonClickMoveReleaseMoveAgain(EventTest &const Planets, Camera &InCamera)
{
	bool result = false;
	EventGenerator::MouseClick();
	EventGenerator::HoldW(2);
	EventGenerator::MoveCursor(-1, -1);
	EventGenerator::MouseRelease();
	auto cameraPos = InCamera.GetPosition();
	auto cameraDir = InCamera.GetDrection();
	EventGenerator::MoveCursor(1,1);
	auto &planets = Planets.m_Planets;
	if ((planets.size() == 1) && glm::all(glm::epsilonEqual(planets.front().GetPosition(), cameraPos + cameraDir, m_Epsilon)))
	{
		result = true;
	}
	return result;
}

void EventTest::testMouseClickMoveMouseClickAgain(EventTest &const Planets, Camera &InCamera)
{
	bool result = false;
	EventGenerator::MouseClick();
	EventGenerator::MouseRelease();
	auto position1 = InCamera.GetPosition() + InCamera.GetDirection();
	EventGenerator::HoldW(2);
	EventGenerator::MoveCursor(-1, -1);
	EventGenerator::MouseRelease();
	auto position2 = InCamera.GetPosition() + InCamera.GetDirection();
	auto &planets = m_OrbitingPlanets.m_Planets;
	if ((planets.size() == 2) && (glm::all(glm::epsilonEqual(planets.front().GetPosition(), position1, m_Epsilon))) &&
	   (glm::all(glm::epsilonEqual(planets.back().GetPosition(), position2, m_Epsilon))))
	{
		result = true;
	}
	return result;
}

bool EventTest::runAllTests(EventTest &const Planets, Camera &InCamera)
{
	bool result = true;
	if (!EventTest::testMouseButtonClickMove(Planets, InCamera))
	{
		cerr << "Test Mouse Button Click Move Failed" << endl;
		result = false;
		goto end;
	}
	if (!EventTest::testMouseButtonClickMoveReleaseMoveAgain(Planets, InCamera))
	{
		cerr << "Test Mouse Button Click Move Release Move Again Failed" << endl;
		result = false;
		goto end;
	}
	if (!EventTest::testMouseClickMoveMouseClickAgain(Planets, InCamera))
	{
		cerr << "Test Mouse Button Click Move Click Again Failed" << endl;
		result = false;
		goto end;
	}

end:
	return result;
}
