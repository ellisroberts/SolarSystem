#include "objectload.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

bool ObjectLoad::Vertex::operator==(Vertex const &Other)
{
	return this->x == Other.x &&
		   this->y == Other.y &&
		   this->z == Other.z;
}

bool ObjectLoad::Text::operator==(Text const &Other)
{
	return this->u == Other.u &&
		   this->v == Other.v;
}

bool ObjectLoad::Normal::operator==(Normal const &Other)
{
	return this->x == Other.x &&
		   this->y == Other.y &&
		   this->z == Other.z;
}

void ObjectLoad::GetBufferData(string const &ObjFile,
				   vector<Vertex> &Vertices,
				   vector<Text> &Textures,
				   vector<Normal> &Normals)
{
	vector<Vertex> tempVertices;
	vector<Text> tempTextures;
	vector<Normal> tempNormals;
	char tmp[256];
	getcwd(tmp, 256);
	string directory(tmp);
	ifstream stream(directory.append(ObjFile));
	if (!stream)
	{
		cerr << "Could not open file" << directory<< endl;
	}
	while (!stream.eof())
	{
		string elem;
		stream >> elem;
		if (elem.compare("v") == 0)
		{
			Vertex vertex;
			stream >> vertex.x >> vertex.y >> vertex.z;
			tempVertices.push_back(vertex);
		}
		if (elem.compare("vt") == 0)
		{
			Text texture;
			stream >> texture.u >> texture.v;
			tempTextures.push_back(texture);
		}
		if (elem.compare("vn") == 0)
		{
			Normal norm;
			stream >> norm.x >> norm.y >> norm.z;
			tempNormals.push_back(norm);
		}
		if (elem.compare("f") == 0)
		{
			for (unsigned int index = 0; index < NUM_TRANGLE_VERTICES; index++)
			{
				unsigned int indexVert, indexText, indexNorm;
				stream >> indexVert;
				stream.ignore(1);
				stream >> indexText;
				stream.ignore(1);
				stream >> indexNorm;
				//Exception checking for out of bounds indexing for vectors
				Vertices.push_back(tempVertices[indexVert - 1]);
				Textures.push_back(tempTextures[indexText - 1]);
				Normals.push_back(tempNormals[indexNorm - 1]);
			}
		}
	}
}
