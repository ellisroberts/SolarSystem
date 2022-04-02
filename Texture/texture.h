#pragma once

#include <GL/glew.h>
#include <string>

using namespace std;

class Texture
{
public:
	Texture(string const& TextFile){}
	Texture(Texture&& Other){}
	Texture& operator=(Texture&& Other);
	~Texture(){}
	//Bind the texture to make it active
	void bind(){}

private:
	GLuint m_TextureId = 0;
	GLuint m_TextureUnit = 0;
	static GLuint m_CurrentTextureUnit;
};
