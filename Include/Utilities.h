#pragma once

#include <cmath>
#include <vector>
#include <stdexcept>
#include <glm/ext/scalar_constants.hpp>


		/*
		static void GenerateVertices(std::vector<float>& vertices, int stacks, int slices, float radius) {
			if (radius == 0.0f)
				throw std::runtime_error("Radius cannot be zero.");

			for (int i = 0; i <= stacks; ++i) {
				float theta = glm::pi<float>() * i / stacks;
				float y = cos(theta);
				float r = sin(theta);

				for (int j = 0; j < slices; ++j) {
					float phi = 2 * glm::pi<float>() * j / slices;
					float x = r * cos(phi);
					float z = r * sin(phi);

					vertices.push_back(x * radius);
					vertices.push_back(y * radius);
					vertices.push_back(z * radius);
				}
			}
		}
		*/

		static	void GenerateVertices(std::vector<float>& vertices)
		{
			constexpr auto PI = 3.14159265358979323846f;
			int stacks = 1500;
			int slices = 1500;


			for (int i = 0; i <= stacks; ++i)
			{
				float theta = PI * i / stacks;
				float y = cos(theta);
				float r = sin(theta);

				for (int j = 0; j <= slices; ++j)
				{
					float phi = 2 * PI * j / slices;
					float x = r * cos(phi);
					float z = r * sin(phi);
					vertices.push_back(x);
					vertices.push_back(y);
					vertices.push_back(z);
				}
			}
		}


		


	



