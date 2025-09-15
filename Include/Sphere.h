#pragma once
#include <vector>
#include <glad/glad.h>
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "VBO.h"

using namespace Constants;

/**
 * @class Sphere
 * @brief Base class representing a spherical planet-like object.
 *
 * The Sphere class is responsible for generating a 3D sphere geometry
 * and holding its properties, such as radius, center position, rotation,
 * and associated texture. It uses a Mesh internally for rendering.
 *
 * Typical usage:
 * @code
 * auto earth = std::make_shared<Sphere>("Earth");
 * earth->setRadius(2.0f);
 * earth->set_center(glm::vec3(0.0f, 0.0f, 0.0f));
 * earth->set_texturefile("resources/Earth.jpg");
 * @endcode
 */
class Sphere
{
    /// Number of subdivisions along the latitude (X axis).
    static constexpr uint16_t stacks = 1000;

    /// Number of subdivisions along the longitude (Y axis).
    static constexpr uint16_t slices = 1000;

protected:
    /// Model transformation matrix for the sphere.
    glm::mat4 model = glm::mat4(1.0f);

    /// Path to the texture file applied to the sphere.
    const char* texturefile = "resources/Earth.jpg";

    /// Axis of rotation for the sphere.
    glm::vec3 rotationAxis;

    /// Rotation speed of the sphere (in arbitrary units).
    float rotationSpeed = 2.0f;

    /// Center position of the sphere in world space.
    glm::vec3 center = glm::vec3(1.0f, 1.0f, 1.0f);

    /// Radius of the sphere.
    float radius = 1.0f;

    /// Vertex data (positions).
    std::vector<float> Vertices;

    /// Mesh representation used for rendering the sphere.
    std::shared_ptr<Mesh> mesh;

public:
	~Sphere();
	const char* name;
	 float getRadius()const {return radius;}
	Sphere() = default;
	explicit Sphere(const char*  name);
	void setRadius(const float r) { radius = r; }
	void Render(Shader shader);
	void SetCenter(glm::vec3);
	void setTexture(const char* texturefile);
	void SetupUniforms();
private:
    /**
     * @brief Generate vertex data for the sphere based on stacks and slices.
     * @param vertices Output vector that stores the generated vertex data.
     *
     * This function computes the sphere geometry by subdividing
     * it into `stacks` (latitude) and `slices` (longitude).
     */
    void GenerateVertices(std::vector<float>& vertices);
    Shader shaderProgram;
};

