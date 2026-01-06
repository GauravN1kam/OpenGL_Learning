#include "config.h"

int main() {
  GLFWwindow *window;

  if (!glfwInit()) {
    return -1;
  }
  window = glfwCreateWindow(800, 800, "First Window", NULL, NULL);
  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glBegin(GL_TRIANGLES);
    glEnd();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }
}
