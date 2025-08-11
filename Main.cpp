#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

constexpr float PI = 3.14159265358979323846f;

// Vertex Shader
const char* vertexShaderSource = R"(
#version 430 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform int stacks;
uniform int slices;
uniform float radius;

out vec3 worldPos;

void main() {
    int vertexID = gl_VertexID;

    int stack = vertexID / (slices + 1);
    int slice = vertexID % (slices + 1);

    float phi = float(stack) / float(stacks) * 3.14159265359; // 0 -> PI
    float theta = float(slice) / float(slices) * 2.0 * 3.14159265359; // 0 -> 2PI

    float x = radius * sin(phi) * cos(theta);
    float y = radius * cos(phi);
    float z = radius * sin(phi) * sin(theta);

    vec4 wPos = model * vec4(x, y, z, 1.0);
    worldPos = wPos.xyz;
    gl_Position = projection * view * wPos;
}
)";

// Fragment Shader
const char* fragmentShaderSource = R"(
#version 430 core
in vec3 worldPos;
out vec4 FragColor;

void main() {
    FragColor = vec4(1.0, 1.0, 0.2, 1.0);
}
)";


int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(1000, 500, "GPU Sphere", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glEnable(GL_DEPTH_TEST);

    // Compile shaders
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Sphere resolution
    constexpr  int stacks = 10000;
    constexpr int slices = 10000;
     constexpr int16_t totalVertices = (stacks + 1) * (slices + 1);

    // Setup empty VAO/VBO (we’ll use gl_VertexID)
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, totalVertices * sizeof(float), nullptr, GL_STATIC_DRAW);

    // Uniform locations
     GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLint projLoc = glGetUniformLocation(shaderProgram, "projection");

    // Camera setup
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1000.0f / 500.0f, 0.1f, 100.0f);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        glUniform1i(glGetUniformLocation(shaderProgram, "stacks"), stacks);
        glUniform1i(glGetUniformLocation(shaderProgram, "slices"), slices);
        glUniform1f(glGetUniformLocation(shaderProgram, "radius"), 1.0f);

        glBindVertexArray(VAO);

        // Draw sphere in strips
        for (int i = 0; i < stacks; ++i) {
            glDrawArrays(GL_POINTS, i * (slices + 1), (slices + 1) * 2);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
}
