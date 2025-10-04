#pragma once
#include <glm/glm.hpp>
#include "ShaderClass.h"
#define GLM_ENABLE_EXPERIMENTAL
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>
#include<glm/gtx/vector_angle.hpp>



class Camera
{
	Shader shader=Shader("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag");
public :
	glm::vec3 Position;
	glm::vec3 Orientation=glm::vec3(1.0f,1.0f,1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	 float height,width;
	 float Speed = 100.1f;
	 float sensitivity = 100.0f;
	explicit Camera(float height, float width, glm::vec3 position);
	explicit Camera()=default;
	void Matrix(float FOVdeg, float nearplane, float farplane, const char* view_matrix, const char* projection_matrix);
	void Inputs(GLFWwindow* window);
};

