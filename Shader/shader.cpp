#include <unistd.h>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <iterator>
#include <vector>
#include "shader.h"

using namespace std;

namespace
{
	void GetShaderSource(string const& FileName, string &OutSrc)
	{
		char tmp[256];
		getcwd(tmp, 256);
		string directory(tmp);
		ifstream fs(directory.append(FileName));
		if (!fs)
		{
			cerr << "Could not open file" << directory << endl;
		}

		noskipws(fs);
		istream_iterator<char> begin {fs};
		istream_iterator<char> end {};
		while (begin != end)
		{
			OutSrc += *begin;
			begin++;
		}
		cout << OutSrc << endl;
	}

	GLint CompileShader(string const& ShaderSrc, GLuint ShaderType)
	{
		GLint isCompiled = GL_FALSE;
		GLuint shader = glCreateShader(ShaderType);
		auto buf = ShaderSrc.c_str();
		glShaderSource(shader, 1, &buf, nullptr);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
		if (!isCompiled)
		{
			GLint msgLength;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &msgLength);
			vector<GLchar> msg(msgLength);
			glGetShaderInfoLog(shader, msgLength, &msgLength, msg.data());
			glDeleteShader(shader);
			for (auto const& elem : msg)
			{
				cout << elem;
			}
			return -1;
		}
		return shader;
	}
}

Shader::Shader(string const& VertexShaderFile,
			   string const& FragmentShaderFile)
{
	string vertexShaderSrc;
	string fragShaderSrc;
	GLint isLinked = GL_FALSE;

	GetShaderSource(VertexShaderFile, vertexShaderSrc);
	GetShaderSource(FragmentShaderFile, fragShaderSrc);

	m_VertexShaderId = CompileShader(vertexShaderSrc, GL_VERTEX_SHADER);
	m_FragmentShaderId = CompileShader(fragShaderSrc, GL_FRAGMENT_SHADER);
	m_ProgramId = glCreateProgram();

	glAttachShader(m_ProgramId, m_VertexShaderId);
	glAttachShader(m_ProgramId, m_FragmentShaderId);

	glLinkProgram(m_ProgramId);
	glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint msgLength;
		glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &msgLength);
		vector<GLchar> msg(msgLength);
		glGetProgramInfoLog(m_ProgramId, msgLength, &msgLength, msg.data());
		for (auto const & elem : msg)
		{
			cout << elem;
		}
		glDeleteProgram(m_ProgramId);
		glDeleteShader(m_VertexShaderId);
		glDeleteShader(m_FragmentShaderId);
		m_ProgramId = 0;
		m_VertexShaderId = 0;
		m_FragmentShaderId = 0;
	}
}

GLint Shader::GetUniform(string const& Name) const
{
	return glGetUniformLocation(m_ProgramId, Name.c_str());
}

void Shader::SetUniformMat4(GLuint Handle, glm::mat4 const& Matrix) const
{
	glUniformMatrix4fv(Handle, 1, GL_FALSE, glm::value_ptr(Matrix));
}

Shader::~Shader()
{
	if (m_ProgramId)
	{
		glDeleteProgram(m_ProgramId);
	}
	if (m_VertexShaderId)
	{
		glDeleteShader(m_VertexShaderId);
	}
	if (m_FragmentShaderId)
	{
		glDeleteShader(m_FragmentShaderId);
	}
}

void Shader::use() const
{
	glUseProgram(m_ProgramId);
}
