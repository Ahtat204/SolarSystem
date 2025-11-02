#pragma once
#include <cmath>
#include <vector>
#include <glm/ext/scalar_constants.hpp>


struct Utilities
{
	static void GenerateVertices(std::vector<float>& vertices,int stacks,int slices,float radius)
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

};
