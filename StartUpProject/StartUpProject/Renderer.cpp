#include "Renderer.h"
#define FEILD_OF_VIEW 45
#define NEAR_PLANE 1.0f
#define FAR_PLANE 100.0f


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::setup(const char* windowTitle, int screenWidth, int screenHeight)
{
	window = new ATWindow(screenWidth, screenHeight, windowTitle);
	camera = new GraphicsCamera();
	scene = new ATScene();

	//Initialize Glew
	glfwMakeContextCurrent((GLFWwindow*)window->getWindowHandle());
	glfwSwapInterval(1);

	glewExperimental = true; // Needed in core profile 
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	/* Setup Camera Parameters*/
	camera->ProjectionMatix(FEILD_OF_VIEW, screenWidth,screenHeight, NEAR_PLANE, FAR_PLANE);
	camera->CameraPosition(4, 3, -3);
	camera->ViewVector(0, 0, 0);
	camera->UpVector(0, 1, 0);

	/*Setup Scene */
	scene->Setup();

}
void Renderer::draw()
{
	while (!glfwWindowShouldClose((GLFWwindow*)window->getWindowHandle()))
	{
		//Add Drawing functions here
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Use our shader
		glUseProgram(scene->ProgramID());
		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		//glm::mat4 tMat = camera->MVPMatrix();
		glUniformMatrix4fv(scene->MatrixID(), 1, GL_FALSE, &(camera->MVPMatrix())[0][0]);
		scene->Draw();
		glfwSwapBuffers((GLFWwindow*)window->getWindowHandle());
		glfwPollEvents();
	}
}