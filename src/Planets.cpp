#include"Planets.h"

void Planets::Earth::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(0.5f), pivot);
}

void Planets::Mercury::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(0.3f), pivot);
}

void Planets::Sun::Move(glm::vec3 pivot)
{
	if (pivot == center) return;

}

void Planets::Mars::Move(glm::vec3 pivot)
{

	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(1.0f), pivot);
}
