#include "Mesh.h"
#include <glm/gtc/type_ptr.inl>

Mesh::Mesh(const std::vector<float>&vertices, const std::string & texturePath)
{
    vertexCount = static_cast<GLsizei>(vertices.size() / 3);

    vao = std::make_unique<VAO>();
    vbo = std::make_unique<VBO>(vertices.data(), vertices.size() * sizeof(float));
    texture = std::make_unique<Texture>(texturePath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);

    vao->Bind();
    vao->LinkVBO(*vbo, 0);  // assumes shader location=0 for aPos
    vao->Unbind();
    vbo->Unbind();
}

void Mesh::Draw(Shader& shader, const glm::mat4& model, const glm::mat4& view, const glm::mat4& projection,
    const glm::vec3& center)
{
    shader.Activate();
    vao->Bind();
    texture->Bind();

    texture->texUnit(shader, "sphereTexture", 0);

    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniform3fv(glGetUniformLocation(shader.ID, "center"), 1, glm::value_ptr(center));

    glDrawArrays(GL_POINTS, 0, vertexCount);


}

//to use it with the Camera class
void Mesh::Draw(Shader& shader, const glm::mat4& model, const glm::vec3 center)
{
    shader.Activate();
    vao->Bind();
    texture->Bind();
    texture->texUnit(shader, "sphereTexture", 0);
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniform3fv(glGetUniformLocation(shader.ID, "center"), 1, glm::value_ptr(center));
    glDrawArrays(GL_POINTS, 0, vertexCount);
}

void Mesh::Delete()
{
    vao->Delete();
    vbo->Delete();
    texture->Delete();
}