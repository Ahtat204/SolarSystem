#include "Camera.h"

Camera::Camera(uint16_t height, uint16_t width, glm::vec3 position) :Position(position), height(height), width(width)
{

}

void Camera::Matrix(float FOVdeg, float nearplane, float farplane, Shader& shader, const char* uniform)
{
}

