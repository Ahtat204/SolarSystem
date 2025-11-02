#pragma once
#include <memory>
#include <vector>
#include <glad/glad.h>
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "VBO.h"
#include"ShaderClass.h"
#include"Mesh.h"

/**
 * @class Sphere
 * @brief Base class representing a spherical planet-like object.
 *
 * The Sphere class is responsible for generating a 3D sphere geometry
 * and holding its properties, such as radius, center position, rotation,
 * and associated texture. It uses a Mesh internally for rendering.
 *
 * Typical usage:
 * @code
 * auto earth = std::make_shared<Sphere>("Earth");
 * earth->setRadius(2.0f);
 * earth->set_center(glm::vec3(0.0f, 0.0f, 0.0f));
 * earth->set_texturefile("resources/Earth.jpg");
 * @endcode
 */
class Sphere
{

public:
	const char* name;
	const float radius;
	void setTexture(const char* path);
	explicit Sphere(const char*  name, float rad, glm::vec3 cen, glm::mat4 mod);
	
private:
	float stacks, slices = 1000;
	std::vector<float> Vertices;
    void GenerateVertices(std::vector<float>& vertices);
    Shader shaderProgram;
	std::shared_ptr<Mesh> mesh;
	const glm::vec3 center;
	const glm::mat4 model;
	const char* texturefile;
};

