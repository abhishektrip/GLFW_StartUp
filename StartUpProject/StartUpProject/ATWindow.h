#pragma once
#include "GL\glew.h"
#include "GLFW\glfw3.h"
class ATWindow
{
public:
	ATWindow(int width, int height, const char * title);
	~ATWindow();
	void* getWindowHandle();
private:
	void* mWindow;
};

