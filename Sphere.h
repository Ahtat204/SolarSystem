#pragma once
#include <vector>
#include <glad/glad.h>

class Sphere
{
public:
	float getRadius(){return radius;}
	Sphere() = default;
	std::vector<GLfloat> GenerateVertices();

private:

	float radius;
	int sectorcount, stackcount, upAxis;
	bool smooth;
	std::vector<GLfloat> vertices;
	std::vector<GLfloat> normals;
	std::vector<float> texCoords;
	std::vector<unsigned int > indices;
	std::vector<unsigned int > lineIndices;
   
};

