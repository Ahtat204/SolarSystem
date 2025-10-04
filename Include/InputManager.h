#pragma once

#include <memory>

#include "Camera.h"
#include "Window.h"

class InputManager
{
	std::shared_ptr<Camera> camera;
	bool firstClick = true;
public:
	explicit InputManager(std::shared_ptr<Camera> camera);
	void Setup(GLFWwindow* window);

};

