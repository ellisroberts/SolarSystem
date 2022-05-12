#pragma once
#include "../Camera/camera.h"
#include "../PlanetManager/planetmanager.h"

#include <X11/X.h>
#include <X11/Xlib.h>

#include <memory>

class SystemEventIntegrationTest
{
private:
	float const m_Epsilon = .00005;
	Display *m_Display;
	shared_ptr<Camera> m_pCamera;
	shared_ptr<PlanetManager> m_pPlanetManager;
public:
	SystemEventIntegrationTest(string const& DisplayName,
							   shared_ptr<Camera> pCamera,
							   shared_ptr<PlanetManager> pPlanetManager);
	~SystemEventIntegrationTest();
	bool testMouseButtonClickMove();
	bool testMouseButtonClickMoveReleaseMoveAgain();
	bool testMouseClickMoveMouseClickAgain();
	bool runAllTests();
};
