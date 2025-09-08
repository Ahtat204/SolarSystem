#pragma once
#include <glm/fwd.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "VBO.h"
#include "Mesh.h"


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
    /// Name identifier for the sphere (e.g., "Earth", "Mars").
    const char* name;

    /**
     * @brief Constructor for the Sphere class.
     * @param name Name identifier for the sphere.
     */
    explicit Sphere(const char* name);

    /**
     * @brief Set the file path of the sphere's texture.
     * @param texturefile Path to the texture file (e.g., "resources/Earth.jpg").
     */
    void set_texturefile(const char* texturefile);

    /**
     * @brief Get the current radius of the sphere.
     * @return Radius as a floating-point value.
     */
    [[nodiscard]] float getRadius() const { return radius; }

    /**
     * @brief Set the radius of the sphere.
     * @param r New radius value.
     */
    void setRadius(const float& r) { radius = r; }

    /**
     * @brief Set the center position of the sphere in world coordinates.
     * @param Center New center position as a glm::vec3.
     */
    void set_center(const glm::vec3& Center);

    void Create();

private:
    /**
     * @brief Generate vertex data for the sphere based on stacks and slices.
     * @param vertices Output vector that stores the generated vertex data.
     *
     * This function computes the sphere geometry by subdividing
     * it into `stacks` (latitude) and `slices` (longitude).
     */
    void GenerateVertices(std::vector<float>& vertices) const;
    Shader shaderProgram;
};

