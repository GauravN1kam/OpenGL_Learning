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

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}
