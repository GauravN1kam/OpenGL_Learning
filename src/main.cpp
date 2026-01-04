#include "config.h"
#include <OpenGL/gl.h>
#include <cmath>

void DrawCirlce(float red, float green, float blue) {
  const int steps = 100;

  float xPrev = 0.f;
  float yPrev = 1.f;
  float radius = 1.f;
  const float angle = 3.1415 * 2 / steps;

  for (int i = 0; i <= steps; i++) {
    float newX = radius * sin(angle * i);
    float newY = -radius * cos(angle * i);

    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(newX, newY, 0.f);
    glVertex3f(xPrev, yPrev, 0.f);
    glEnd();

    xPrev = newX;
    yPrev = newY;
  }
}

int main() {
  GLFWwindow *window;

  if (!glfwInit()) {
    return -1;
  }
  window = glfwCreateWindow(800, 800, "First Window", NULL, NULL);

  glfwMakeContextCurrent(window);
  glMatrixMode(GL_MODELVIEW);
  glScalef(0.1f, 0.1f, 1);

  float angle = 0;
  float angleMoon = 0.f;
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);

    angle += 1.0;
    DrawCirlce(1, 1, 0);
    {
      glPushMatrix();
      glRotatef(angle, 0, 0, 1);
      glTranslatef(0, 5, 0);
      glScalef(0.6f, 0.6f, 1.f);
      DrawCirlce(0, 0.3f, 1.0f);
      {
        glPushMatrix();
        glRotatef(angleMoon, 0, 0, 1);
        glTranslatef(0, 3.f, 0);
        glScalef(0.6, 0.6, 0);
        DrawCirlce(0.4, 0.4, 0.4);
        glPopMatrix();

        angleMoon += 1.8f;
      }
      glPopMatrix();
    }

    glfwSwapBuffers(window);
  }
}
