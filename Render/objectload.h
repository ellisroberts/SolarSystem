#include <vector>
#include <string>

using namespace std;

namespace ObjectLoad
{
	constexpr unsigned int NUM_TRANGLE_VERTICES = 3;

	struct Vertex
	{
		float x;
		float y;
		float z;
		bool operator==(Vertex const& Other);
	};
	struct Text
	{
		float u;
		float v;
		bool operator==(Text const &Other);
	};
	struct Normal
	{
		float x;
		float y;
		float z;
		bool operator==(Normal const &Other);
	};

	//Get Buffer Data from the object file
	void GetBufferData(string const &ObjFile,
					   vector<Vertex> &Vertices,
					   vector<Text> &Textures,
					   vector<Normal> &Normals);
}
