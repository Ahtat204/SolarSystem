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
#include "Utilities.h"

/**
 * @class Planet
 * @brief Base class representing a spherical planet-like object.
 *
 * The Planet class is responsible for generating a 3D sphere geometry
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
class Planet
{
public:
	glm::vec3 center;
	~Planet() = default;
protected:
	 float radius;
	
	virtual void Move()=0;
	explicit Planet(){
		
		mesh = std::make_shared<Mesh>(vertices, texureFilePath);
		model = glm::mat4(1.0f);
	}
	glm::mat4 model;

	const  float slices = 1000;
	const  float stacks = 1000;
	std::shared_ptr<Mesh> mesh;
	std::vector<float> vertices;
	std::string texureFilePath;
	
};

