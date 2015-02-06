#pragma once
#include "ATWindow.h"
#include "UtilityFunctions.h"

#include<iostream>

ATWindow::ATWindow(int width, int height, const char* title)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		std::cerr<<"Failed to initialize GLFW\n";
		exit(EXIT_FAILURE);
	}
	glfwSetErrorCallback(UtilityFunctions::error_callback);

	mWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!mWindow)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetKeyCallback((GLFWwindow*)mWindow, UtilityFunctions::key_callback);
}

void* ATWindow::getWindowHandle()
{
	return (mWindow) ? mWindow : NULL;
}
ATWindow::~ATWindow()
{
	glfwDestroyWindow((GLFWwindow*)mWindow);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
