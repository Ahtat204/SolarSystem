#include <stdexcept>
#include<glad/glad.h>
#include<GLFW/glfw3.h>


int main()
{

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
   
   

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glViewport(0, 0, 1000, 500);
        glClearColor(0.0f, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
       

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}