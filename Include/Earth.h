#pragma once
#include <memory>
#include <vector>
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include"ShaderClass.h"
#include"Mesh.h"
class Mesh;


class Earth final
{
public:
	explicit Earth();
	const float radius = 6371.0f; // Earth's radius in kilometers
	glm::vec3 center;


private:
	const float stacks, slices = 1000;
	glm::mat4 model;
	Shader shaderclass;
	std::shared_ptr<Mesh> mesh;
	std::vector<float> vertices;
	const char* texureFilePath = "ressources/Textures/Earth.jpg";
};

