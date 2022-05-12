#include "systemeventintegrationtest.h"

#include <glm/gtc/epsilon.hpp>
#include <iostream>
#include <vector>

//enable latin key codes
#define XK_LATIN1
#include <X11/keysymdef.h>

#include <X11/extensions/XTest.h>


using namespace std;

//NOTE: THIS MUST CHANGE WHEN WE ADD INDEPENDENT MOVEMENT BASED ON GRAVITATIONAL ATTRACTION TO THE PLANETS

SystemEventIntegrationTest::SystemEventIntegrationTest(string const& DisplayName,
					 	 	 	 	 	 	 	 	   shared_ptr<Camera> pCamera,
													   shared_ptr<PlanetManager> pPlanetManager) :
													   m_pCamera {pCamera},
													   m_pPlanetManager {pPlanetManager}
{
    m_Display = XOpenDisplay((DisplayName == "") ? NULL : DisplayName.c_str());
    if (!m_Display)
    {
    	//Throw Exception
    }
}

SystemEventIntegrationTest::~SystemEventIntegrationTest()
{
	XCloseDisplay(m_Display);
}

bool SystemEventIntegrationTest::testMouseButtonClickMove()
{
	bool result = false;
	XTestFakeButtonEvent(m_Display, Button1, true, CurrentTime);
	for (unsigned int i = 0; i < 10; i++)
	{
		XTestFakeKeyEvent(m_Display, XK_w, true, CurrentTime);
	}
	XTestFakeRelativeMotionEvent(m_Display, -1, -1, CurrentTime);
	auto planets = m_pPlanetManager->GetPlanets();
	if ((planets.size() == 1) && (glm::all(glm::epsilonEqual(planets.front().GetPosition(), m_pCamera->GetPosition() + m_pCamera->GetDirection(), m_Epsilon))))
	{
		result = true;
	}
	return result;
}

bool SystemEventIntegrationTest::testMouseButtonClickMoveReleaseMoveAgain()
{
	bool result = false;
	XTestFakeButtonEvent(m_Display, Button1, true, CurrentTime);
	for (unsigned int i = 0; i < 10; i++)
	{
		XTestFakeKeyEvent(m_Display, XK_w, true, CurrentTime);
	}
	XTestFakeRelativeMotionEvent(m_Display, -1, -1, CurrentTime);
	XTestFakeButtonEvent(m_Display, Button1, false, CurrentTime);
	auto cameraPos = m_pCamera->GetPosition();
	auto cameraDir = m_pCamera->GetDirection();
	XTestFakeRelativeMotionEvent(m_Display, -1, -1, CurrentTime);
	auto planets = m_pPlanetManager->GetPlanets();
	if ((planets.size() == 1) && glm::all(glm::epsilonEqual(planets.front().GetPosition(), cameraPos + cameraDir, m_Epsilon)))
	{
		result = true;
	}
	return result;
}

bool SystemEventIntegrationTest::testMouseClickMoveMouseClickAgain()
{
	bool result = false;
	XTestFakeButtonEvent(m_Display, Button1, true, CurrentTime);
	XTestFakeButtonEvent(m_Display, Button1, false, CurrentTime);
	auto position1 = m_pCamera->GetPosition() + m_pCamera->GetDirection();
	for (unsigned int i = 0; i < 10; i++)
	{
		XTestFakeKeyEvent(m_Display, XK_w, true, CurrentTime);
	}
	XTestFakeRelativeMotionEvent(m_Display, -1, -1, CurrentTime);
	XTestFakeButtonEvent(m_Display, Button1, false, CurrentTime);
	auto position2 = m_pCamera->GetPosition() + m_pCamera->GetDirection();
	auto planets = m_pPlanetManager->GetPlanets();
	if ((planets.size() == 2) && (glm::all(glm::epsilonEqual(planets.front().GetPosition(), position1, m_Epsilon))) &&
	   (glm::all(glm::epsilonEqual(planets.back().GetPosition(), position2, m_Epsilon))))
	{
		result = true;
	}
	return result;
}

bool SystemEventIntegrationTest::runAllTests()
{
	bool result = true;
	if (!SystemEventIntegrationTest::testMouseButtonClickMove())
	{
		cerr << "Test Mouse Button Click Move Failed" << endl;
		result = false;
		goto end;
	}
	if (!SystemEventIntegrationTest::testMouseButtonClickMoveReleaseMoveAgain())
	{
		cerr << "Test Mouse Button Click Move Release Move Again Failed" << endl;
		result = false;
		goto end;
	}
	if (!SystemEventIntegrationTest::testMouseClickMoveMouseClickAgain())
	{
		cerr << "Test Mouse Button Click Move Click Again Failed" << endl;
		result = false;
		goto end;
	}

end:
	return result;
}
