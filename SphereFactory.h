#pragma once
#include <memory>
#include <string>

class Sphere;

class SphereFactory
{
public:
	static std::unique_ptr<Sphere> create_planet(std::string name);
	SphereFactory() = default;
};
