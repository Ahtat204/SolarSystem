#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>

#include "Texture.h"
#include "VAO.h"
#include "VBO.h"


/**
 * base class of all planets
 */
class Sphere
{
protected:
	const char* texturefile;
	glm::vec3 rotationAxis;
	float rotationSpeed;
	glm::vec3 center;
	float radius;
public:
	~Sphere();
	const char* name;
	 float getRadius()const {return radius;}
	Sphere() = default;
	explicit Sphere(const char*  name);
	void setRadius(const float r) { radius = r; }
	void Render(Shader shader);
	void SetCenter(glm::vec3);
	void setTexture(const char* texturefile);
	void SetupUniforms();
private:
	Shader shaderProgram;
	Texture texture;
	VAO VAO1;
	VBO VBO1;
	static constexpr int16_t stacks = 2000;//around the x axis
	static constexpr int16_t slices = 2000;//around the y axis
	static constexpr int16_t totalVertices = (stacks + 1) * (slices + 1);
};
