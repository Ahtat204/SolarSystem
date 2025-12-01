#include "Earth.h"


//Shader Utilities::globalShader = Shader("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag");


void Earth::Move(glm::vec3 pivot)
{
	if (pivot==center) return;
	model = glm::rotate(model, glm::radians(1.0f), pivot);
}
