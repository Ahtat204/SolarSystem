#pragma once
#define GLM_ENABLE_EXPERIMENTAL 
#include <glm/gtx/transform.hpp>
#include"pch.h"


class Mercury
{
public:

	float radius;
	glm::vec3 center;
	glm::mat4 model;
	std::shared_ptr<Mesh> mesh;
	explicit Mercury(float r = 0.5f, glm::vec3 c = glm::vec3(15.0f, 1.0f, 0.0f))
		:radius(r), center(c), model(glm::mat4(1.0f))
	{
		mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/mercury.jpg");
		model = glm::scale(model, glm::vec3(radius, radius, radius));

	}
	void Move(glm::vec3 pivot);


};

