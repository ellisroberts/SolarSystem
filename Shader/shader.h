#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

using namespace std;

class Shader
{
public:
	Shader(string const& VertexShaderFile,
		   string const& FragmentShaderFile);
	Shader(Shader&& Other) = delete;
	Shader& operator=(Shader&& Other) = delete;
	//Use the current shader in opengl context
	void use() const;
	//Get Uniform variable
	GLint GetUniform(string const& Name) const;
	//Set Uniform Variable
	void SetUniformMat4(GLuint Handle, glm::mat4 const& Matrix) const;
	~Shader();

private:
	GLuint m_ProgramId = 0;
	GLuint m_VertexShaderId = 0;
	GLuint m_FragmentShaderId = 0;
};
