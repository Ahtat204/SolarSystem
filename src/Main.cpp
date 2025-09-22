#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>       // for sin, cos
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"
#include "ShaderClass.h"
#include "VAO.h"
#include"Window.h"
#include "VBO.h"
#include"Constants.h"
#include "InputManager.h"
#include "Texture.h"
#include"Mesh.h"
#include "Sphere.h"


static void GenerateVertices(std::vector<float>& vertices)
{
    constexpr auto PI = 3.14159265358979323846f;
    int stacks = 1500;
    int slices = 1500;
    float radius = 0.8f;

    for (int i = 0; i <= stacks; ++i)
    {
        float theta = PI * i / stacks;
        float y = cos(theta);
        float r = sin(theta);

        for (int j = 0; j <= slices; ++j)
        {
            float phi = 2 * PI * j / slices;
            float x = r * cos(phi);
            float z = r * sin(phi);
            vertices.push_back(x * radius);
            vertices.push_back(y * radius);
            vertices.push_back(z * radius);
        }
    }
}

auto model = glm::mat4(1.0f);
auto center = glm::vec3(1.0f, 1.0f, 1.0f);
glm::vec3 Cen = glm::vec3(3.0f, 1.0f, 1.0f);
auto view = glm::lookAt(
    glm::vec3(1.0f, 1.0f, 8.0f),
    glm::vec3(1.0f, 1.0f, 0.0f),
    glm::vec3(0.0f, 1.0f, 0.0f)
);
glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 500.0f, 0.1f, 100.0f);


int main()
{
    std::vector<float> Vertices;
    GenerateVertices(Vertices);

    auto window = std::make_unique<Window>(2800, 1000, "Solar System");
    window->Config();
     auto camera = std::make_shared<Camera>(1000.0f, 500.0f, glm::vec3(1.0f, 0.0f, 6.0f));
	InputManager input_manager(camera);
    Shader shaderProgram("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag");
    Mesh sphere(Vertices, "ressources/Earth.jpg");
    Mesh earth(Vertices, "ressources/mercury.jpg");
    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->Matrix(45.0f, 0.1f, 100.0f, "view", "projection");
        input_manager.Setup(window->getWindow());
        sphere.Draw(shaderProgram, model, center);
        earth.Draw(shaderProgram, model, Cen);
        window->swapBuffers();
        window->poolEvents();
    }
    sphere.Delete();
	earth.Delete();
    shaderProgram.Delete();
    return 0;

}