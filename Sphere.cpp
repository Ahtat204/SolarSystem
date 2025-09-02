#include"Sphere.h"
#include <glm/gtc/type_ptr.hpp>

#include "ShaderClass.h"

Sphere::~Sphere()
{
    shaderProgram.Delete();
    VAO1.Delete();
    texture.Unbind();
    texture.Delete();
}


Sphere::Sphere(const char* name): shaderProgram("ressources/Shaders/Sphere.vert", "ressources/Shaders/Sphere.frag"), texture(texturefile, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE), VBO1(totalVertices)
{
	this->name = name;
    glEnable(GL_DEPTH_TEST);
    VAO1.Bind();
    VAO1.LinkVBO(VBO1, 0);
    VBO1.Unbind();
    VBO1.Unbind();
    texture.Bind();
    SetupUniforms();
    SetCenter(center);
}

void Sphere::Render(Shader shader)
{
    shader.Activate();
    VAO1.Bind();
    for (auto i = 0; i < stacks; ++i) {
        glDrawArrays(GL_POINTS, i * (slices + 1), (slices + 1) * 2);
    }
}

void Sphere::SetCenter(glm::vec3 center)
{
  
    glUniform3fv(glGetUniformLocation(shaderProgram.ID, "center"), 1, glm::value_ptr(center));
}

void Sphere::setTexture(const char* texturefile)
{
    texture.texUnit(shaderProgram,"sphereTexture",0);
}

void Sphere::SetupUniforms()
{
    /*const GLint modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
    const  GLint viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
    const GLint projLoc = glGetUniformLocation(shaderProgram.ID, "projection");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(Model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(Projection));*/
    glUniform1i(glGetUniformLocation(shaderProgram.ID, "stacks"), stacks);
    glUniform1i(glGetUniformLocation(shaderProgram.ID, "slices"), slices);

}

