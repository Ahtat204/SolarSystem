#include <iostream>
#include <stdexcept>
#include <vector>
#include "Earth.h"
#include "Mars.h"
#include "Mercury.h"
#include"pch.h"
#include "Utilities.h"


/*

void  GenerateVertices(std::vector<float>& vertices)
{
    constexpr auto PI = 3.14159265358979323846f;
    int stacks = 1500;
    int slices = 1500;


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
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
    }
}

*/
auto model = glm::mat4(1.0f);
auto center = glm::vec3(3.0f, 3.0f, 3.0f);
glm::vec3 Cen = glm::vec3(3.0f, 1.0f, 1.0f);
auto view = glm::lookAt(
    glm::vec3(1.0f, 1.0f, 8.0f),
    glm::vec3(1.0f, 1.0f, 0.0f),
    glm::vec3(0.0f, 1.0f, 0.0f)
);
glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 500.0f, 0.1f, 100.0f);
std::vector<float> Mesh::globalVertices = {};


int main()
{
	GenerateVertices(Mesh::globalVertices);
    auto window = std::make_unique<Window>(2800, 1000, "Solar System");
    window->Config();
	auto camera = std::make_shared<Camera>(1000.0f, 500.0f, glm::vec3(1.0f, 0.0f, 6.0f));
	InputManager input_manager(camera);
    Shader shaderProgram("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag");
    Earth earth = Earth();
    Sun sun = Sun();
    Mars mars = Mars();
	Mercury mercury = Mercury();
    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->Matrix(45.0f, 0.1f, 100.0f, "view", "projection");
        input_manager.Setup(window->getWindow());
        earth.mesh->Draw(shaderProgram, earth.model, earth.center);
		sun.mesh->Draw(shaderProgram, sun.model, sun.center);
		mars.mesh->Draw(shaderProgram, mars.model, mars.center);
		mercury.mesh->Draw(shaderProgram, mercury.model, mercury.center);
		mercury.Move(glm::vec3(0.0f, 1.0f, 0.0f));
        earth.Move(glm::vec3(0.0f,1.0f,0.0f));
		sun.Move(glm::vec3(0.0f, 2.0f, 0.0f));
        mars.Move(glm::vec3(0.0f, 1.0f, 0.0f));
       // Earth* earth_planet = new Earth(glm::vec3(1.0f, 1.0f, 1.0f));
      //  earth_planet->Draw();
        window->swapBuffers();
        window->poolEvents();
    }
    
    shaderProgram.Delete();
    
    return 0;

}

