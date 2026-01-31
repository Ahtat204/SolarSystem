#include"Planets.h"

void earth::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(0.5f), pivot);
}

void mercury::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(0.3f), pivot);
}

void sun::Move(glm::vec3 pivot) const
{
	if (pivot == center) return;

}

void mars::Move(glm::vec3 pivot)
{

	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(1.0f), pivot);
}

void venus::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(0.35f), pivot);
}
void jupiter::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(1.0f), pivot);
}

void saturn::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(1.1f), pivot);
}

