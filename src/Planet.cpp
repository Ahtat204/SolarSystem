#include"Planet.h"
#include <glm/gtc/type_ptr.hpp>

// void Planet::GenerateVertices(std::vector<float>& vertices)
// {
// 	for (auto i = 0; i <= stacks; ++i) {
// 	  const float theta = glm::pi<float>() * i / stacks;
// 		const float y = cos(theta);
// 		float r = sin(theta);
// 		for (int j = 0; j <= slices; ++j) {
// 			float phi = 2 * glm::pi<float>() * j / slices;
// 			float x = r * cos(phi);
// 			float z = r * sin(phi);
// 			if (radius == 0) throw std::runtime_error("Radius cannot be zero.");
// 			vertices.push_back(x * radius);
// 			vertices.push_back(y * radius);
// 			vertices.push_back(z * radius);
// 		}
// 	}
// }


void  Planet::GenerateVertices( std::vector<float>& vertices)
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

