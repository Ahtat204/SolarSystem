#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>       // for sin, cos
#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr float PI = 3.14159265358979323846f;

// Vertex Shader source code
const char* vertexShaderSource = R"(
#version 430 core

layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;

out vec3 worldPos;

void main() {
    vec4 wPos = model * vec4(aPos, 1.0);
    worldPos = vec3(wPos);
    gl_Position = perspective * view * wPos;
}
)";

// Fragment Shader source code
const char* fragmentShaderSource = R"(
#version 430 core

in vec3 worldPos;
out vec4 color;

uniform vec3 camPos;
uniform vec3 sphereCenter;

void main() {
    color = vec4(1.0, 0.3, 0.2, 1.0); // Simple red-orange color
}
)";

int main() {
    // Initialize GLFW
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(1000, 500, "Solar System", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();

    // ---- Generate sphere vertices ----
    std::vector<float> Vertices;
    int stacks = 2400;
    int slices = 2400;
    float radius = 1.0f;

    for (int i = 0; i <= stacks; ++i) {
        float theta = PI * i / stacks;
        float y = cos(theta);
        float r = sin(theta);

        for (int j = 0; j <= slices; ++j) {
            float phi = 2 * PI * j / slices;
            float x = r * cos(phi);
            float z = r * sin(phi);
            Vertices.push_back(x * radius);
            Vertices.push_back(y * radius);
            Vertices.push_back(z * radius);
        }
    }

    // ---- Compile shaders ----
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

    int success;
    char infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "Vertex Shader Compilation Failed:\n" << infoLog << std::endl;
    }

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "Fragment Shader Compilation Failed:\n" << infoLog << std::endl;
    }

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "Shader Program Linking Failed:\n" << infoLog << std::endl;
    }

    /*
	 * shaderProgram is now ready to use.
     */
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // ---- Setup VAO and VBO ----
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(float), Vertices.data(), GL_STATIC_DRAW);

    // layout(location = 0) => aPos
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // ---- Uniforms ----
    float identity[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };

    GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLint projLoc = glGetUniformLocation(shaderProgram, "perspective");
    GLint camLoc = glGetUniformLocation(shaderProgram, "camPos");
    GLint sphereLoc = glGetUniformLocation(shaderProgram, "sphereCenter");

    // ---- Render loop ----
    while (!glfwWindowShouldClose(window)) {
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR)
            std::cout << "OpenGL error: " << err << std::endl;

        glViewport(0, 0, 1000, 500);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, identity);
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, identity);
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, identity);
        glUniform3f(camLoc, 0.0f, 0.0f, 3.0f);
        glUniform3f(sphereLoc, 0.0f, 0.0f, 0.0f);

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, Vertices.size() / 3);  // you can change to GL_TRIANGLES later

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ---- Cleanup ----
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();

    return 0;
}
