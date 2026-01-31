#include "Camera.h"
#include<glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Camera::Camera(float height,glm::vec3 eye, float width, glm::vec3 position):shader("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag")
{
	Position = position;
	this->height = height;
	this->width = width;
	this->eye = eye;
	
}


void Camera::Matrix(float FOVdeg, float nearplane, float farplane, const char* view_matrix, const char* projection_matrix)
{

	const  GLint viewLoc = glGetUniformLocation(shader.ID, "view");
	const GLint projLoc = glGetUniformLocation(shader.ID, "projection");
	
	glm::mat4 view = glm::lookAt(
		Position,
	    eye,
	    glm::vec3(0.0f, 1.0f, 0.0f)
	);
	glm::mat4 projection = glm::perspective(glm::radians(FOVdeg),float(height/width), nearplane, farplane);
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::Inputs(GLFWwindow* window)
{
}
