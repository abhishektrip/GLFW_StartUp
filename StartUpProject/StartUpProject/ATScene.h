#pragma once
#include <vector>
#include <GL\glew.h>


class ATScene
{
public:
	void Setup();
	void Draw();
	void Cleanup();
	GLuint ProgramID(){return mProgramID; }
	GLuint MatrixID(){return mMatrixID; }
	ATScene();
	~ATScene();
private:
	GLuint mVertexArrayID;
	GLuint mVertexBuffer;
	const std::vector<GLfloat> mVertexBufferData;
	GLuint mMatrixID; 
	GLuint mProgramID;

};

