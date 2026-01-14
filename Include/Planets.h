#pragma once
#define GLM_ENABLE_EXPERIMENTAL 
#include <glm/gtx/transform.hpp>
#include"pch.h"

namespace Planets
{
	class Earth
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Earth(float r = 0.5f, glm::vec3 c = glm::vec3(14.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/Earth.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};

	class Mercury
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Mercury(float r = 0.5f, glm::vec3 c = glm::vec3(10.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/mercury.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};

	class Mars
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Mars(float r = 0.8f, glm::vec3 c = glm::vec3(17.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/Mars.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};


	class Venus
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Venus(float r = 0.8f, glm::vec3 c = glm::vec3(12.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/Venus.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};

	class Sun
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Sun(float r = 1.5f, glm::vec3 c = glm::vec3(0.0f, 0.0f, 1.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/Sun.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};
}
