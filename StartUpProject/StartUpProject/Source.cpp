#include "ATWindow.h"
class wrapperClass
{
public:
	wrapperClass(){};
	void setup()
	{
		window = new ATWindow(640, 480, "My Window");
	}
	void draw()
	{
		glfwMakeContextCurrent((GLFWwindow*)window->getWindowHandle());
		glfwSwapInterval(1);
		while (!glfwWindowShouldClose((GLFWwindow*)window->getWindowHandle()))
		{
			//Add Drawing functions here
			glfwSwapBuffers((GLFWwindow*)window->getWindowHandle());
			glfwPollEvents();
		}
	}
private:
	ATWindow* window;
};
int main()
{
	wrapperClass* test;
	test = new wrapperClass();
	test->setup();
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