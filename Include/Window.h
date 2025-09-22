#pragma once


#include <string>

#include <GLFW/glfw3.h>

class Window
{
public:
	explicit Window();
	explicit Window(int width, int height, std::string title);
	~Window();
	void Config();

	bool shouldClose() const;
	void poolEvents() const;
	void swapBuffers() const;
	GLFWwindow* getHandle() const { return window; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	 
private:
	/// 
	GLFWwindow* window;
	int width, height;

	void initGLFW(std::string title);
public:
	GLFWwindow* getWindow() { return window; }

};


