#pragma once
#include"pch.h"
#include "Planet.h"
class Mesh;//forward declaration to avoid circular dependency and reduce compilation time


class Earth :public Planet
{
public:
	void Move() override;
	explicit Earth(glm::vec3 c);
	void Draw() override;


	
	
};

