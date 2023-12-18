#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>
#include <math.h>

const GLint WIDTH = 1600, HEIGHT = 1200;
const int NUM_SEGMENTS = 360;

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) {
    GLfloat twicePi = 2.0f * M_PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z); // Center of circle
    for (int i = 0; i <= NUM_SEGMENTS; i++) {
        glVertex3f(
            x + (radius * cos(i * twicePi / NUM_SEGMENTS)),
            y + (radius * sin(i * twicePi / NUM_SEGMENTS)),
            z
        );
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Cyan Circle", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Set the color to cyan
        glColor3f(0.0f, 1.0f, 1.0f);

        // Draw circle
        drawCircle(-0.5f, 0.0f, 0.0f, 0.5f);
        glColor3f(1.0f, 0.0f, 1.0f);
        drawCircle(0.5f, 0.0f, 0.0f, 0.5f);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
