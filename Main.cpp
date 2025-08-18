#include <iostream>
#include"ShaderClass.h"
#include"Window.h"
#include "VAO.h"
#include "VBO.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


constexpr  int stacks = 1000;
constexpr int slices = 1000;
constexpr int16_t totalVertices = (stacks + 3) * (slices + 3);

int main() {
	Window window(1000, 500, "Solar System");
    glEnable(GL_DEPTH_TEST);
	Shader shaderProgram("Sphere.vert", "Sphere.frag");
    VAO VAO1;
    VAO1.Bind();
	VBO VBO1(totalVertices);
    VAO1.LinkVBO(VBO1, 0);
	VBO1.Unbind();
    VAO1.Unbind();
    // Uniform locations
     const GLint modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
    const  GLint viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
    const GLint projLoc = glGetUniformLocation(shaderProgram.ID, "projection");
    // Camera setup
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 500.0f, 0.1f, 100.0f);
    // Render loop
    while (!window.shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shaderProgram.Activate();
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform1i(glGetUniformLocation(shaderProgram.ID, "stacks"), stacks);
        glUniform1i(glGetUniformLocation(shaderProgram.ID, "slices"), slices);
        glUniform1f(glGetUniformLocation(shaderProgram.ID, "radius"), 0.5f);
        VAO1.Bind();
        // Draw sphere in strips
        for (int i = 0; i < stacks; ++i) {
            glDrawArrays(GL_POINTS, i * (slices + 1), (slices + 1) * 2);
        }
        window.swapBuffers();
        window.poolEvents();
    }

    VAO1.Delete();
	VBO1.Delete();
	shaderProgram.Delete();
	window.~Window();
}


 