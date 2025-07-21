#include <iostream>
#include <stdexcept>
#include <__msvc_ostream.hpp>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

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

const char* fragmentShaderSource = R"(
#version 430 core

in vec3 worldPos;
out vec4 color;

uniform vec3 camPos;
uniform vec3 sphereCenter;

vec3 sphereIntersect(vec3 c, vec3 ro, vec3 p) {
    vec3 rd = vec3(normalize(p - ro));
    vec3 u = vec3(ro - c); // ro relative to c

    float a = dot(rd, rd);
    float b = 2.0 * dot(u, rd);
    float cc = dot(u, u) - 1.0;

    float discriminant = b * b - 4 * a * cc;

    // no intersection
    if (discriminant < 0.0) {
        return vec3(0.0);
    }

    float t1 = (-b + sqrt(discriminant)) / (2.0 * a);
    float t2 = (-b - sqrt(discriminant)) / (2.0 * a);
    float t = min(t1, t2);
    vec3 intersection = ro + vec3(t * rd);

    return intersection;
}

void main() {
    vec3 sp = sphereIntersect(sphereCenter, camPos, worldPos);
    if (sp == vec3(0.0)) {
        discard;
    }
    color = vec4(abs(sp), 1.0);
}
)";




GLfloat vertices[] = {
	// Positions
     -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,
    -1.0f,  1.0f, 0.0f };


float identity[16] = {
     1,0,0,0,
     0,1,0,0,
     0,0,1,0,
     0,0,0,1
};




int main()
{

    GLenum err;
    

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 500, "Solar System", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    gladLoadGL();
   
   


    GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexshader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexshader);


    GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentshader);
    GLuint shaderProgram = glCreateProgram();


    glAttachShader(shaderProgram, vertexshader);
    glAttachShader(shaderProgram, fragmentshader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexshader);
    glDeleteShader(fragmentshader);


    int success;
    char infoLog[512];

    glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexshader, 512, NULL, infoLog);
        std::cerr << "Vertex Shader Compilation Failed:\n" << infoLog << std::endl;
    }

    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cerr << "Fragment Shader Compilation Failed:\n" << infoLog << std::endl;
    }

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "Shader Program Linking Failed:\n" << infoLog << std::endl;
    }


    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


    GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLint projLoc = glGetUniformLocation(shaderProgram, "perspective");
    GLint camLoc = glGetUniformLocation(shaderProgram, "camPos");
    GLint sphereLoc = glGetUniformLocation(shaderProgram, "sphereCenter");











    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        while ((err = glGetError()) != GL_NO_ERROR)
            std::cout << "OpenGL error: " << err << std::endl;


        glViewport(0, 0, 1000, 500);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);


        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, identity);
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, identity);
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, identity);
        glUniform3f(camLoc, 0.0f, 0.0f, 3.0f);         // Eye at z = 3
        glUniform3f(sphereLoc, 0.0f, 0.0f, 0.0f);




		glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);


        
        glfwSwapBuffers(window);
       

        /* Poll for and process events */
        glfwPollEvents();
    }
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}