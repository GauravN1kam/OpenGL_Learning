#include "config.h"
#include <cmath>

void CreateSinWave() {
  float offsets[100];
  offsets[0] = 0.0f;
  for (int i = 1; i < 100; i++) {
    offsets[i] = offsets[i - 1] + 0.01;
  }
  float Xoffsets[100];
  Xoffsets[0] = 0.0f;
  for (int i = 1; i < 100; i++) {
    Xoffsets[i] = Xoffsets[i - 1] + 0.01;
  }
  glBegin(GL_POINTS);
  for (int i = 0; i < 100; i++) {
  }

  glEnd();
}

int SinWavemain() {
  GLFWwindow *window;

  if (!glfwInit()) {
    return -1;
  }
  window = glfwCreateWindow(800, 800, "First Window", NULL, NULL);
  glfwMakeContextCurrent(window);

  float offsets[1000];
  offsets[0] = -1.f;

  float Xoffsets[1000];
  Xoffsets[0] = -1.f;

  for (int i = 1; i < 1000; i++) {
    Xoffsets[i] = Xoffsets[i - 1] + 0.002;
  }

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    glColor3f(1.f, 1.f, 1.f);

    offsets[0] += 0.001f;
    for (int i = 1; i < 1000; i++) {
      offsets[i] = offsets[i - 1] + 0.01;
    }

    glPointSize(2.0f);
    glBegin(GL_POINTS);

    for (int i = 0; i < 1000; i++) {
      glVertex3f(Xoffsets[i], 0.5 * sin(offsets[i]), 0);
    }
    glEnd();

    glBegin(GL_POINTS);

    for (int i = 0; i < 1000; i++) {
      glVertex3f(Xoffsets[i], 0.5 * cos(offsets[i]), 0);
    }
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(-1, 0, 0);
    glVertex3f(1, 0, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(0, 0, -1);
    glVertex3f(0, 0, 1);
    glEnd();

    glfwSwapBuffers(window);
  }
