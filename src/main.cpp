#include "config.h"
#include <OpenGL/gl.h>
#include <cmath>

int main() {
  GLFWwindow *window;

  if (!glfwInit()) {
    return -1;
  }
  window = glfwCreateWindow(800, 800, "First Window", NULL, NULL);
  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glPointSize(0.5f);
    float xVal = 0.01;
    float yVal = 0;
    glColor3f(0.5f, 0.5f, 0.5f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);

    float x = 0.0f;
    for (int i = 0; i < 1000; i++) {
      float y = sin(x);
      glVertex2f(x, y);
      x += 0.01f;
    }

    glEnd();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }
}
