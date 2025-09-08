#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "VAO.h"
#include "VBO.h"
#include "Texture.h"
#include "ShaderClass.h"

/**
 * @class Mesh
 * @brief Encapsulates the geometry, texture, and rendering logic for a 3D object.
 *
 * The Mesh class owns a VAO (Vertex Array Object), a VBO (Vertex Buffer Object),
 * and an optional Texture. It provides methods to render the geometry using
 * a given Shader and transformation matrices.
 *
 * Typical usage:
 * @code
 * std::vector<float> vertices = { /* interleaved positions, normals, UVs * / };
 * Mesh mesh(vertices, "resources/texture.jpg");
 *
 * Shader shader("vertex.glsl", "fragment.glsl");
 *
 * glm::mat4 model = glm::mat4(1.0f);
 * glm::mat4 view = camera.GetViewMatrix();
 * glm::mat4 projection = glm::perspective(...);
 *
 * mesh.Draw(shader, model, view, projection, glm::vec3(0.0f, 0.0f, 0.0f));
 * @endcode
 */
class Mesh {
public:
    /**
     * @brief Construct a new Mesh.
     *
     * @param vertices A vector of vertex data (positions, normals, UVs).
     *        The layout of vertex data must match the attributes expected by the Shader.
     * @param texturePath Path to the texture image file.
     */
    Mesh(const std::vector<float>& vertices, const std::string& texturePath);

    /**
     * @brief Draw the mesh with full transformation matrices.
     *
     * @param shader Reference to the Shader to use for rendering.
     * @param model Model matrix for object transformations (scale, rotation, translation).
     * @param view View matrix from the camera.
     * @param projection Projection matrix (perspective or orthographic).
     * @param center Center position of the object (used for lighting or transformations).
     */
    void Draw(Shader& shader,
        const glm::mat4& model,
        const glm::mat4& view,
        const glm::mat4& projection,
        const glm::vec3& center);

    /**
     * @brief Draw the mesh with only a model transform.
     *
     * Useful for cases where the shader does not require view/projection matrices.
     *
     * @param shader Reference to the Shader to use for rendering.
     * @param model Model matrix for object transformations.
     * @param center Center position of the object.
     */
    void Draw(Shader& shader,
        const glm::mat4& model,
        const glm::vec3 center);

    /**
     * @brief Free GPU resources associated with this Mesh.
     *
     * Deletes the VAO, VBO, and texture. After calling this,
     * the Mesh can no longer be drawn.
     */
    void Delete();

private:
    /// Vertex Array Object (stores attribute state).
    std::unique_ptr<VAO> vao;

    /// Vertex Buffer Object (stores vertex data on the GPU).
    std::unique_ptr<VBO> vbo;

    /// Texture applied to this mesh.
    std::unique_ptr<Texture> texture;

    /// Number of vertices in this mesh (used for glDrawArrays).
    GLsizei vertexCount;
};
