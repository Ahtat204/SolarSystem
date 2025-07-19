#pragma once
#include <vector>

class Sphere
{
public:

private:

	float radius;
	int sectorcount, stackcount, upAxis;
	bool smooth;
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> texCoords;
	std::vector<unsigned int > indices;
	std::vector<unsigned int > lineIndices;
   
};

