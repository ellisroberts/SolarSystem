#include "Shader/shader.h"
#include "Camera/camera.h"
#include "IntegrationTest/systemeventintegrationtest.h"
#include "PlanetManager/planetmanager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/norm.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

#include <memory>

using namespace std;

namespace
{
	const GLuint HEIGHT = 800;
	const GLuint WIDTH = 600;
	struct WindowInput
	{
		shared_ptr<Camera> camera;
		shared_ptr<PlanetManager> planetManager;
	};
}

static void key_callback(GLFWwindow* window, GLint key, GLint scancode, GLint action, GLint mods)
{
}

static void cursor_position_callback(GLFWwindow* window, GLdouble xpos, GLdouble ypos)
{
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
}

int main(void)
{
	GLint ret = 0;
	WindowInput windowInput = {make_shared<Camera>(), make_shared<PlanetManager>()};
	SystemEventIntegrationTest eventTest("", windowInput.camera, windowInput.planetManager);
	if (!glfwInit()) {
        cout << "GLFW initialization failed!\n";
        glfwTerminate();
        return 1;
	}

	//Set version number
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Disable backwards compatibility and enable forward compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "window", nullptr, nullptr);
	if (!window) {
		cerr << "Window creation failed\n";
		glfwTerminate();
		//TODO: Throw Exception
	}

	//Capture cursor
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//Get Buffer Size information, buffer is what is being written to when drawing to the window
	int bufferWidth;
	int bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

	//Set current context in window created for glew to use
	glfwMakeContextCurrent(window);

	//Set Window size
	glViewport(0, 0, bufferWidth, bufferHeight);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		cout << "Could not initialize glew!\n";
		return -1;
	}

	//Set Callbacks
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	//Set user Pointer to Planet Manager class

	glfwSetWindowUserPointer(window, reinterpret_cast<void *>(&windowInput));

	//Run Tests before drawing anything
	if (!eventTest.runAllTests())
	{
		return 1;
	}
//
//	//Initialize perspective projection matrix
//	glm::mat4 perspective = glm::perspective(glm::radians(45.0f), static_cast<float> (WIDTH / HEIGHT), 0.1f, 100.0f);
//
//	//Initialize Sun/Shaders
//	Body sun("/Render/sphere.obj", glm::vec3{0,0,0}, glm::vec3{0,0,0}, glm::vec3{0,0,0}, 1.0);
//	Shader sunShader("/Shader/vertexFile.txt", "/Shader/fragmentSun.txt");
//	glm::mat4 sunModelMatrix = sun.ComputeModelMatrix();
//	sunShader.use();
//	sunShader.SetUniformMat4(sunShader.GetUniform("projection"), perspective);
//	sunShader.SetUniformMat4(sunShader.GetUniform("model"), sunModelMatrix);
//
//	//Initialize Planet Shaders
//	Shader planetShader("/Shader/planetVertexShader.txt", "/Shader/planetFragmentShader.txt");
//	planetShader.use();
//	planetShader.SetUniformMat4(planetShader.GetUniform("projection"), perspective);
//
//
//	while (!glfwWindowShouldClose(window)) {
//		//Set color to black
//		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		//Enable depth test
//		glEnable(GL_DEPTH_TEST);
//		//Clear the color buffer
//		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
//
//		//Get user input events
//		glfwPollEvents();
//
//		//Compute View Matrix
//		glm::mat4 viewMatrix = Camera::GetInstance()->ComputeViewMatrix();
//
//		sunShader.use();
//		sunShader.SetUniformMat4(sunShader.GetUniform("view"), viewMatrix);
//		sun.Draw(.001);
//
//		planetShader.use();
//		//Set the last planet to always align with the camera as it has not been released yet
//		if (!planetMgr.GetPlanets().empty())
//		{
//			if (ISLEFTMOUSEBUTTONPRESSED)
//			{
//				auto &planet = planetMgr.GetPlanets().back();
//				planet.SetPosition(Camera::GetInstance()->GetPosition() +
//														  Camera::GetInstance()->GetDirection()*DISTANCEINFRONTOFCAMERA);
//				PLANETVELOCITYSCALE += .1;
//			}
//		}
//		for (auto &planet : planetMgr.GetPlanets())
//		{
//			planetShader.SetUniformMat4(planetShader.GetUniform("view"), viewMatrix);
//			planetShader.SetUniformMat4(planetShader.GetUniform("model"), planet.ComputeModelMatrix());
//			planet.Draw(.001);
//			planet.SetAcceleration(sun.GetGravitationalConstant()*sun.GetMass() /
//								   (glm::length2(sun.GetPosition() - planet.GetPosition())) *
//								   glm::normalize(sun.GetPosition() - planet.GetPosition()));
//			cout << glm::length(sun.GetPosition() - planet.GetPosition()) << endl;
//			cout << glm::dot(glm::normalize(planet.GetVelocity()), glm::normalize(sun.GetPosition() - planet.GetPosition())) << endl;
//		}
//
//		//Double buffering
//		glfwSwapBuffers(window);
//	}

	return ret;
}
