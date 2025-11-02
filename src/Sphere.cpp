#include"Sphere.h"
#include <glm/gtc/type_ptr.hpp>

void Sphere::GenerateVertices(std::vector<float>& vertices)
{
	for (auto i = 0; i <= stacks; ++i) {
	  const float theta = glm::pi<float>() * i / stacks;
		const float y = cos(theta);
		float r = sin(theta);
		for (int j = 0; j <= slices; ++j) {
			float phi = 2 * glm::pi<float>() * j / slices;
			float x = r * cos(phi);
			float z = r * sin(phi);
			vertices.push_back(x * radius);
			vertices.push_back(y * radius);
			vertices.push_back(z * radius);
		}
	}
}

void Sphere::setTexture(const char* path)
{
}

Sphere::Sphere(const char* name,float rad,glm::vec3 cen,glm::mat4 mod): shaderProgram("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag"),radius(rad),model(mod),center(cen)
{
	this->name = name;
	GenerateVertices(Vertices);
	mesh = std::make_shared<Mesh>(Vertices, texturefile);
}


