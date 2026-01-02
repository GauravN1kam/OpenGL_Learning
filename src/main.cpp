#include "config.h"
#include "triangle_mesh.h"
unsigned int make_module(const std::string &filepath, unsigned int module_type);
unsigned int make_shader(const std::string &vertex_filepath,
                         const std::string &fragment_filepath);
int main() {
  GLFWwindow *window;

  if (!glfwInit()) {
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  window = glfwCreateWindow(640, 480, "First Window", NULL, NULL);

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
    return -1;
  }
  glClearColor(0.25f, 0.50f, 0.75f, 1.0f);

  unsigned int shader =
      make_shader("../shaders/vertex.txt", "../shaders/fragment.txt");

  // Used to offset the View
  // int w, h;
  // glfwGetFramebufferSize(window, &w, &h);
  // glViewport(100, 100, 200, 200);

  TriangleMesh *triangle = new TriangleMesh();
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader);
    triangle->draw();
    glfwSwapBuffers(window);
  }
  glDeleteShader(shader);
  glfwTerminate();
}

unsigned int make_module(const std::string &filepath,
                         unsigned int module_type) {
  std::ifstream file;
  std::stringstream buffereLines;
  std::string line;

  file.open(filepath);

  while (std::getline(file, line)) {
    buffereLines << line << "\n";
  }
  std::string shaderSource = buffereLines.str();
  const char *shaderSrc = shaderSource.c_str();
  buffereLines.str("");
  file.close();

  unsigned int shaderModule = glCreateShader(module_type);
  glShaderSource(shaderModule, 1, &shaderSrc, NULL);
  glCompileShader(shaderModule);

  int sucess;
  glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &sucess);

  if (!sucess) {
    char errorLog[1024];

    glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);

    std::cout << "Shader Module compilation error: \n" << errorLog << std::endl;
  }
  return shaderModule;
}

unsigned int make_shader(const std::string &vertex_filepath,
                         const std::string &fragment_filepath) {
  std::vector<unsigned int> modules;
  modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));
  modules.push_back(make_module(fragment_filepath, GL_FRAGMENT_SHADER));

  unsigned int shader = glCreateProgram();
  for (unsigned int shaderModule : modules) {
    glAttachShader(shader, shaderModule);
  }
  glLinkProgram(shader);

  int sucess;
  glGetProgramiv(shader, GL_LINK_STATUS, &sucess);
  if (!sucess) {
    char errorLog[1024];

    glGetProgramInfoLog(shader, 1024, NULL, errorLog);

    std::cout << "Shader Linking error: \n" << errorLog << std::endl;
  }
  for (unsigned int shaderModule : modules) {
    glDeleteShader(shaderModule);
  }
  return shader;
}
