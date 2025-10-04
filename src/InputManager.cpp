#include "InputManager.h"

#include <iso646.h>
#include <glm/ext/matrix_transform.hpp>

#include <glm/ext/quaternion_trigonometric.hpp>


InputManager::InputManager(std::shared_ptr<Camera> camera): camera(camera)
{
	
}

void InputManager::Setup(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		camera->Position += camera->Speed * camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera->Position += camera->Speed * -glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera->Position += camera->Speed * -camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera->Position += camera->Speed * glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		camera->Position += camera->Speed * camera->Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		camera->Position += camera->Speed * -camera->Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		camera->Speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		camera->Speed = 0.1f;
	}

	// Handles mouse inputs
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		// Hides mouse cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Prevents camera from jumping on the first click
		if (firstClick)
		{
			glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
			firstClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX;
		double mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = camera->sensitivity * (float)(mouseY - (camera->height / 2)) / camera->height;
		float rotY = camera->sensitivity * (float)(mouseX - (camera->width / 2)) / camera->width;

		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(camera->Orientation, glm::radians(-rotX), glm::normalize(glm::cross(camera->Orientation, camera->Up)));

		// Decides whether or not the next vertical Orientation is legal or not
		if (abs(glm::angle(newOrientation,camera-> Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			camera->Orientation = newOrientation;
		}

		// Rotates the Orientation left and right
		camera->Orientation = glm::rotate(camera->Orientation, glm::radians(-rotY), camera->Up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Makes sure the next time the camera looks around it doesn't jump
		firstClick = true;
	}

}
