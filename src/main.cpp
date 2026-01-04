#include "config.h"
#include <cmath>

void DrawCircle();

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

    // glBegin(GL_TRIANGLES);
    // glColor3f(1.0f, 0.f, 0.f);
    // glVertex3f(-0.6f, -0.6f, 0);
    // glColor3f(0.0f, 1.f, 0.f);
    // glVertex3f(0.0f, 0.5f, 0);
    // glColor3f(0.f, 0.f, 1.f);
    // glVertex3f(0.6f, -0.6f, 0);
    // glEnd();

    DrawCircle();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
}

void DrawCircle() {
  const int steps = 120;
  const float angle = 3.1415926 * 2.f / steps;

  float xPos = 0.f;
  float yPos = 0.f;
  float radius = 0.5f;

  float prevX = xPos;
  float prevY = yPos - radius;

  for (int i = 0; i <= steps; i++) {
    float newX = radius * sin(angle * i);
    float newY = -radius * cos(angle * i);

    glColor3f(0.5f, 0.2f, 0.7f);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(prevX, prevY, 0.f);
    glVertex3f(newX, newY, 0);
    glEnd();

    prevX = newX;
    prevY = newY;
  }
}
