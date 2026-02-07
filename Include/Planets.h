#pragma once
#define GLM_ENABLE_EXPERIMENTAL 
#include <glm/gtx/transform.hpp>
#include"pch.h"

namespace Planets
{
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

		void Move(glm::vec3 pivot) const;
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
	class Jupiter
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Jupiter(float r = 1.7f, glm::vec3 c = glm::vec3(19.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/jupiter.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};
	class Saturn
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Saturn(float r = 1.7f, glm::vec3 c = glm::vec3(21.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/saturn.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};
	class Uranus
	{
	public:
		float radius;
		glm::vec3 center;
		glm::mat4 model;
		std::shared_ptr<Mesh> mesh;

		explicit Uranus(float r = 1.7f, glm::vec3 c = glm::vec3(23.0f, 1.0f, 0.0f))
			: radius(r), center(c), model(glm::mat4(1.0f))
		{
			mesh = std::make_shared<Mesh>(Mesh::globalVertices, "ressources/uranus.jpg");
			model = glm::scale(model, glm::vec3(radius, radius, radius));
		}

		void Move(glm::vec3 pivot);
	};
}

using venus = Planets::Venus;
using earth = Planets::Earth;
using mars = Planets::Mars;
using mercury = Planets::Mercury;
using sun = Planets::Sun;
using jupiter = Planets::Jupiter;
using saturn = Planets::Saturn;
using uranus = Planets::Uranus;
