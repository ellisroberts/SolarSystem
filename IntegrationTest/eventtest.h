#pragma once
#include "../Camera/camera.h"
#include "../PlanetManager/planetmanager.h"

class EventTest
{
private:
	static float const m_Epsilon = .00005;
public:
	static void testMouseButtonClickMove(EventTest &const Planets, Camera &InCamera);
	static void testMouseButtonClickMoveReleaseMoveAgain(EventTest &const Planets, Camera &InCamera);
	static void testMouseClickMoveMouseClickAgain(EventTest &const Planets, Camera &InCamera);
	static void runAllTests(EventTest &const Planets, Camera &InCamera);
};
