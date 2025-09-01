#pragma once
#include <glm/vec3.hpp>

#include "ShaderClass.h"

class Camera
{
private :
	glm::vec3 Position;
	glm::vec3 Orientation=glm::vec3(0.0f,0.0f,-1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	const  uint16_t height,width;
	static constexpr auto speed = 0.1f;
	float sensitivity = 100.0f;
public:
	glm::vec3 position() const
	{
		return Position;
	}
	glm::vec3 orientation() const
	{
		return Orientation;
	}
	glm::vec3 up() const
	{
		return Up;
	}
	uint16_t height1() const
	{
		return height;
	}
	uint16_t width1() const
	{
		return width;
	}
	auto speed1() const
	{
		return speed;
	}
	float sensitivity1() const
	{
		return sensitivity;
	}
	explicit Camera(uint16_t height, uint16_t width, glm::vec3 position);
	explicit Camera()=default;
	void Matrix(float FOVdeg, float nearplane, float farplane, Shader& shader, const char* uniform);
	void Inputs();
};

