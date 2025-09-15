#include"Sphere.h"
#include <glm/gtc/type_ptr.hpp>

void Sphere::GenerateVertices(std::vector<float>& vertices)
{
	for (auto i = 0; i <= stacks; ++i) {
<<<<<<< HEAD
	  const float theta = glm::pi<float>() * i / stacks;
		const float y = cos(theta);
		float r = sin(theta);
		for (int j = 0; j <= slices; ++j) {
			float phi = 2 * glm::pi<float>() * j / slices;
=======
	  const float theta = PI * i / stacks;
		const float y = cos(theta);
		float r = sin(theta);
		for (int j = 0; j <= slices; ++j) {
			float phi = 2 * PI * j / slices;
>>>>>>> a35d1250122855209d459d57d0c06dcc0a641963
			float x = r * cos(phi);
			float z = r * sin(phi);
			vertices.push_back(x * radius);
			vertices.push_back(y * radius);
			vertices.push_back(z * radius);
		}
	}
}

Sphere::Sphere(const char* name): shaderProgram("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag")
{
	this->name = name;
	GenerateVertices(Vertices);
	mesh = std::make_shared<Mesh>(Vertices, texturefile);
}

void Sphere::set_center(const glm::vec3& Center)
{
	center = Center;
}

void Sphere::Create()
{
	mesh->Draw(shaderProgram, model, center);
}





void Sphere::set_texturefile(const char* texturefile)
{
	this->texturefile = texturefile;
}
