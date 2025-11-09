#pragma once
#include"pch.h"
#include "Planet.h"
class Mesh;//forward declaration to avoid circular dependency and reduce compilation time


class Earth :public Planet
{
public:
	float radius = 6371.0f;
	void Move() override;

	explicit Earth() = default;
};

