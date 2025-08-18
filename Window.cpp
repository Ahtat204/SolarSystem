#include <glad/glad.h>
#include "Window.h"
#include <iostream>
#include <stdexcept>



Window::Window()
{
}

Window::Window(int width, int height, std::string title)
{
	this->width = width;
	this->height = height;
	initGLFW(title);
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(window);
}

void  Window::poolEvents() const
{
   glfwPollEvents();
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(window);
	
}

void Window::initGLFW(std::string title)
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    glEnable(GL_DEPTH_TEST);
}

