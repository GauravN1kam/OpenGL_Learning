#include "config.h"

int main() {
  GLFWwindow *window;
  if (!glfwInit()) {
    std::cout << "Init error";
    return -1;
  }

  window = glfwCreateWindow(800, 800, "Hello", 0, 0);

  if (!window) {
    std::cout << "Window creation failed";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.6f, 0);
    glColor3f(0.0f, 1.f, 0.f);
    glVertex3f(0.0f, 0.5f, 0);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.6f, -0.6f, 0);

    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-0.9, 0.8, 0);
    glVertex3f(0.9, 0.8, 0);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}
