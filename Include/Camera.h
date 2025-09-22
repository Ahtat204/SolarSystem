#pragma once
#include <glm/glm.hpp>
#include "ShaderClass.h"
#include "Window.h"

class Camera
{
	Shader shader=Shader("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag");
public :
	glm::vec3 Position;
	const glm::vec3 Orientation=glm::vec3(1.0f,1.0f,1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	 float height,width;
	 float Speed = 100.1f;
	 float sensitivity = 100.0f;
	explicit Camera(float height, float width, glm::vec3 position);
	explicit Camera()=default;
	void Matrix(float FOVdeg, float nearplane, float farplane, const char* view_matrix, const char* projection_matrix);
	void Inputs(GLFWwindow* window);
};

