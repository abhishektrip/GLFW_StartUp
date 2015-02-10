#include "Renderer.h"

int main()
{
	Renderer* test;
	test = new Renderer();
	test->setup( "My Window",640, 480);
	test->draw();
	delete test; 
	/*ATWindow* newWindow;

	newWindow = new ATWindow(640, 480, "My Window");
	glfwMakeContextCurrent((GLFWwindow*)newWindow->getWindowHandle());
	glfwSwapInterval(1);
	while (!glfwWindowShouldClose((GLFWwindow*)newWindow->getWindowHandle()))
	{
		glfwSwapBuffers((GLFWwindow*)newWindow->getWindowHandle());
		glfwPollEvents();
	}*/

	return 1;
}