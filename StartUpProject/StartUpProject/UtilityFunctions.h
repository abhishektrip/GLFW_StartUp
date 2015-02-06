#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace UtilityFunctions
{
	GLuint loadShaders(const char* vertexShaderPath, const char* fragmentShaderPath);
	void error_callback(int error, const char* description);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
}


