#include"pch.h"
#include "Utilities.h"
#include"Planets.h"

glm::mat4 model = glm::mat4(1.0f);
glm::vec3 center = glm::vec3(3.0f, 3.0f, 3.0f);
glm::vec3 Cen = glm::vec3(3.0f, 1.0f, 1.0f);
glm::mat4 view = glm::lookAt(
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
    auto earth = Planets::Earth();
	auto sun = Planets::Sun();
	auto mars = Planets::Mars();
	auto mercury = Planets::Mercury();
	auto  venus = Planets::Venus();
    auto jupiter = Planets::Jupiter();
    auto saturn = Planets::Saturn();
    auto uranus = Planets::Uranus();
    while (!window->shouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->Matrix(45.0f, 0.1f, 100.0f, "view", "projection");
        input_manager.Setup(window->getWindow());
        earth.mesh->Draw(shaderProgram, earth.model, earth.center);
		sun.mesh->Draw(shaderProgram, sun.model, sun.center);
		mars.mesh->Draw(shaderProgram, mars.model, mars.center);
		mercury.mesh->Draw(shaderProgram, mercury.model, mercury.center);
        venus.mesh->Draw(shaderProgram, venus.model, venus.center);
		jupiter.mesh->Draw(shaderProgram, jupiter.model, jupiter.center);
        saturn.mesh->Draw(shaderProgram, saturn.model, saturn.center);
		uranus.mesh->Draw(shaderProgram, uranus.model, uranus.center);
		mercury.Move(glm::vec3(0.0f, 1.0f, 0.0f));
        earth.Move(glm::vec3(0.0f,1.0f,0.0f));
		sun.Move(glm::vec3(0.0f, 2.0f, 0.0f));
        mars.Move(glm::vec3(0.0f, 1.0f, 0.0f));
        venus.Move(glm::vec3(0.0f, 1.0f, 0.0f));
		jupiter.Move(glm::vec3(0.0f, 1.0f, 0.0f));
        saturn.Move(glm::vec3(0.0f, 1.0f, 0.0f));
		uranus.Move(glm::vec3(0.0f, 1.0f, 0.0f));
        window->swapBuffers();
        window->poolEvents();
    }
    shaderProgram.Delete();
    return 0;

}

