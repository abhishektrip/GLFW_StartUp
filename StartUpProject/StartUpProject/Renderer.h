#pragma once
#include "ATWindow.h"
#include "GraphicsCamera.h"
#include "ATScene.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	void setup(const char* windowTitle, int screenWidth, int screenHeight);
	void draw();

private:
	ATWindow* window;
	GraphicsCamera* camera; 
	ATScene* scene; 
	
};
