#include "FileLoader.h"

FileLoader::FileLoader(string filename)
{
	LoadFileInternal(filename, FILE_SIZE_UNKNOWN);
	/*streampos size;
	mFileHandle.open(filename, ios::in | ios::binary | ios::ate);
	if (mFileHandle.is_open())
	{
		size = mFileHandle.tellg();
		mFileBuffer = new char[size];
		mFileHandle.seekg(0, mFileHandle.beg);
		mFileHandle.read(mFileBuffer, size);
		mFileHandle.close();
	}*/
}
FileLoader::~FileLoader()
{
	if (mFileHandle.is_open())
	{
		mFileHandle.close();
		delete mFileBuffer;
	}
		
}
void FileLoader::LoadFileInternal(string filename , const int bufferSize)
{
	streampos size;
	mFileHandle.open(filename, ios::in | ios::binary | ios::ate);
	if (mFileHandle.is_open())
	{
		size = mFileHandle.tellg();
		const int bSize = (size > bufferSize && bufferSize != FILE_SIZE_UNKNOWN) ? bufferSize : size;
		mFileBuffer = new char[bSize];
		mFileHandle.seekg(0, mFileHandle.beg);
		mFileHandle.read(mFileBuffer, bSize);
		mFileHandle.close();
	}
}
char* FileLoader::LoadFile(string filename, int height, int width, int depth)
{
	LoadFileInternal(filename, height*width*depth);
	return mFileBuffer;
}
char* FileLoader::LoadFile(string filename)
{
	if (mFileHandle.is_open())
	{
		if (mFileBuffer != nullptr)
			return mFileBuffer;
		else
			return nullptr;
	}
	else
	{
		LoadFileInternal(filename,FILE_SIZE_UNKNOWN);
		return mFileBuffer;
	}		
}
//void VolumeRenderer::Render()
//{
//	
//}
//void VolumeRenderer::RenderToTexture()
//{
//	// The framebuffer, which regroups 0, 1, or more textures, and 0 or 1 depth buffer.
//	GLuint FramebufferName = 0;
//	glGenFramebuffers(1, &FramebufferName);
//	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
//
//	// The texture we're going to render to
//	GLuint renderedTexture;
//	glGenTextures(1, &renderedTexture);
//
//	// "Bind" the newly created texture : all future texture functions will modify this texture
//	glBindTexture(GL_TEXTURE_2D, renderedTexture);
//
//	// Give an empty image to OpenGL ( the last "0" )
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 768, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
//
//	// Poor filtering. Needed !
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//
//	// The depth buffer
//	GLuint depthrenderbuffer;
//	glGenRenderbuffers(1, &depthrenderbuffer);
//	glBindRenderbuffer(GL_RENDERBUFFER, depthrenderbuffer);
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, 1024, 768);
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthrenderbuffer);
//
//	// Set "renderedTexture" as our colour attachement #0
//	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, renderedTexture, 0);
//
//	// Set the list of draw buffers.
//	GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0 };
//	glDrawBuffers(1, DrawBuffers); // "1" is the size of DrawBuffers
//	// Always check that our framebuffer is ok
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//		exit(EXIT_FAILURE);//return false;
//}
//void VolumeRenderer::DrawingFunction()
//{
//
//	GLuint VertexArrayID;
//	glGenVertexArrays(1, &VertexArrayID);
//	glBindVertexArray(VertexArrayID);
//
//	//// An array of 3 vectors which represents 3 vertices
//	//static const GLfloat g_vertex_buffer_data[] = {
//	//	-1.0f, -1.0f, 0.0f,
//	//	1.0f, -1.0f, 0.0f,
//	//	0.0f, 1.0f, 0.0f,
//	//};
//
//	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
//	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
//	static const GLfloat g_vertex_buffer_data[] = {
//		-1.0f, -1.0f, -1.0f, // triangle 1 : begin
//		-1.0f, -1.0f, 1.0f,
//		-1.0f, 1.0f, 1.0f, // triangle 1 : end
//		1.0f, 1.0f, -1.0f, // triangle 2 : begin
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, 1.0f, -1.0f, // triangle 2 : end
//		1.0f, -1.0f, 1.0f,
//		-1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f, 1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, 1.0f, 1.0f,
//		-1.0f, 1.0f, -1.0f,
//		1.0f, -1.0f, 1.0f,
//		-1.0f, -1.0f, 1.0f,
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, 1.0f, 1.0f,
//		-1.0f, -1.0f, 1.0f,
//		1.0f, -1.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f, 1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f, 1.0f, 1.0f,
//		1.0f, -1.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		1.0f, 1.0f, -1.0f,
//		-1.0f, 1.0f, -1.0f,
//		1.0f, 1.0f, 1.0f,
//		-1.0f, 1.0f, -1.0f,
//		-1.0f, 1.0f, 1.0f,
//		1.0f, 1.0f, 1.0f,
//		-1.0f, 1.0f, 1.0f,
//		1.0f, -1.0f, 1.0f
//	};
//
//	// This will identify our vertex buffer
//	GLuint vertexbuffer;
//
//	// Generate 1 buffer, put the resulting identifier in vertexbuffer
//	glGenBuffers(1, &vertexbuffer);
//
//	// The following commands will talk about our 'vertexbuffer' buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//
//	// Give our vertices to OpenGL.
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//
//	// 1rst attribute buffer : vertices
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//	glVertexAttribPointer(
//		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//		3,                  // size
//		GL_FLOAT,           // type
//		GL_FALSE,           // normalized?
//		0,                  // stride
//		(void*)0            // array buffer offset
//		);
//
//	// Draw the triangle !
//	glDrawArrays(GL_TRIANGLES, 0, 12*3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//
//	glDisableVertexAttribArray(0);
//}
//void VolumeRenderer::loadFile(string filename , int height, int width, int depth)
//{
//	mHeight = height; mWidth = width; mDepth = depth; 
//	streampos size;
//	//char* buffer;
//	ifstream fileHandle(filename, ios::in | ios::binary | ios::ate);
//	if (fileHandle.is_open())
//	{
//		size = fileHandle.tellg();
//		mBuffer = new char[size];
//		fileHandle.seekg(0, fileHandle.beg);
//		fileHandle.read(mBuffer, size);
//		fileHandle.close();
//
//		mScalars = new float[size];
//		for (int i = 0; i < size; i++)
//		{
//			mScalars[i] = (float)mBuffer[i] / CHAR_MAX;
//			/*cout << mScalars[i];*/
//		}
//	}
//}