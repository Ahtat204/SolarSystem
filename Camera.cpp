#include "Camera.h"
#include<glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(int8_t height, int8_t width, glm::vec3 position):shader("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag")
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}


void Camera::Matrix(float FOVdeg, float nearplane, float farplane, const char* view_matrix, const char* projection_matrix)
{

	const  GLint viewLoc = glGetUniformLocation(shader.ID, "view");
	const GLint projLoc = glGetUniformLocation(shader.ID, "projection");
	glm::mat4 view = glm::lookAt(
    	glm::vec3(1.0f, 0.0f, 6.0f),
	    glm::vec3(0.0f, 1.0f, 0.0f),
	    glm::vec3(0.0f, 1.0f, 0.0f)
	);
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 500.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::Inputs(GLFWwindow* window)
{
}
