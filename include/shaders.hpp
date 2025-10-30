#ifndef SHADERS_HPP
#define SHADERS_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
extern const char* vertexShaderSource;
extern const char* fragmentShaderSource;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
unsigned int compileShader(GLenum type, const char* source);
unsigned int createShaderProgram();

#endif