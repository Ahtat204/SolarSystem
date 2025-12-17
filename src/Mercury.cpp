#include "Mercury.h"

void Mercury::Move(glm::vec3 pivot)
{
	if (pivot == center) return;
	model = glm::rotate(model, glm::radians(1.0f), pivot);
}