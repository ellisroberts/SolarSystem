#include "body.h"
#include <vector>

Body::Body(string const& ObjFile,
		   glm::vec3 const& Pos,
		   glm::vec3 const &Velocity,
		   glm::vec3 const &Acceleration,
		   float const Mass)
	 :m_Pos {Pos},
	  m_Velocity {Velocity},
	  m_Acceleration {Acceleration},
	  m_Mass {Mass}
{
//	vector<Vertex> vertices;
//	vector<Text> textures;
//	vector<Normal> normals;
//	GetBufferData(ObjFile, vertices, textures, normals);
//
//	//Throw exception if vertices, textures, and normals not equal in size
//	m_NumVertices = vertices.size();
//	if ((m_NumVertices != textures.size()) || (m_NumVertices != normals.size()))
//	{
//		cerr << "Object file not properly formed" << endl;
//	}

//	//Generate Vertex Array Object
//	glGenVertexArrays(1, &m_VAO);
//	glBindVertexArray(m_VAO);
//
//	//Bind the vertex vbo
//	glGenBuffers(1, &m_VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
//	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<void *> (0));
//	glEnableVertexAttribArray(0);
//
//	//Bind the texture vbo
//	glGenBuffers(1, &m_TextureVBO);
//	glBindBuffer(GL_ARRAY_BUFFER, m_TextureVBO);
//	glBufferData(GL_ARRAY_BUFFER, textures.size() * sizeof(Text), textures.data(), GL_STATIC_DRAW);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Text), static_cast<void *> (0));
//	glEnableVertexAttribArray(1);
//
//	//Bind the normal vbo
//	glGenBuffers(1, &m_NormalVBO);
//	glBindBuffer(GL_ARRAY_BUFFER, m_NormalVBO);
//	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Normal), normals.data(), GL_STATIC_DRAW);
//	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Normal), static_cast<void *> (0));
//	glEnableVertexAttribArray(2);
//
//	//Unbind vertex buffer and vertex array object
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
}

Body::Body(Body &&Other)
{
	m_VBO = Other.m_VBO;
	m_TextureVBO = Other.m_TextureVBO;
	m_NormalVBO = Other.m_NormalVBO;
	m_VAO = Other.m_VAO;
	m_NumVertices = Other.m_NumVertices;
	m_Pos = Other.m_Pos;
	m_Velocity = Other.m_Velocity;
	m_Acceleration = Other.m_Acceleration;

	Other.m_VAO = 0;
	Other.m_VBO = 0;
	Other.m_TextureVBO = 0;
	Other.m_NormalVBO = 0;
}
Body& Body::operator=(Body &&Other)
{
	m_VBO = Other.m_VBO;
	m_TextureVBO = Other.m_TextureVBO;
	m_NormalVBO = Other.m_NormalVBO;
	m_VAO = Other.m_VAO;
	m_NumVertices = Other.m_NumVertices;
	m_Pos = Other.m_Pos;
	m_Velocity = Other.m_Velocity;
	m_Acceleration = Other.m_Acceleration;

	Other.m_VAO = 0;
	Other.m_VBO = 0;
	Other.m_TextureVBO = 0;
	Other.m_NormalVBO = 0;

	return *this;
}

Body::~Body()
{
	if (m_VAO)
	{
		glDeleteVertexArrays(1, &m_VAO);
	}
	if (m_VBO)
	{
		glDeleteBuffers(1, &m_VBO);
	}
	if (m_TextureVBO)
	{
		glDeleteBuffers(1, &m_TextureVBO);
	}
	if (m_NormalVBO)
	{
		glDeleteBuffers(1, &m_NormalVBO);
	}
}
