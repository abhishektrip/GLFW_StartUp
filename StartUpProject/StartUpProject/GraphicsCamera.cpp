#include "GraphicsCamera.h"


GraphicsCamera::GraphicsCamera()
:mViewX(0.0), mViewY(0.0), mViewZ(0.0),
mCamX(0.0), mCamY(0.0), mCamZ(0.0),
mUpX(0.0), mUpY(1.0), mUpZ(0.0)
{
}


GraphicsCamera::~GraphicsCamera()
{
}

void GraphicsCamera::ProjectionMatix(double FOV, int screenWidth, int screenHeight, double nearPlane, double farPlane)
{
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	mProjection = glm::perspective(FOV, (double)screenWidth / screenHeight, nearPlane, farPlane);
	
	// Model matrix : an identity matrix (model will be at the origin)
	mModel = glm::mat4(1.0f);
	
}
void GraphicsCamera::CameraPosition(double x, double y, double z)
{
	mCamX = x; mCamY = y; mCamZ = z; 
	UpdateViewMatrix();
}
void GraphicsCamera::ViewVector(double x, double y, double z)
{
	mViewX = x; mViewY = y; mViewZ = z;
	UpdateViewMatrix();
}
void GraphicsCamera::UpVector(double x, double y, double z)
{
	mUpX = x; mUpY = y; mUpZ = z; 
	UpdateViewMatrix();

}
void GraphicsCamera::UpdateViewMatrix()
{
	// Camera matrix
	mView = glm::lookAt(
		glm::vec3(mCamX, mCamY, mCamZ), // Camera is at (4,3,-3), in World Space
		glm::vec3(mViewX, mViewY, mViewZ), // and looks at the origin
		glm::vec3(mUpX, mUpY, mUpZ)  // Head is up (set to 0,-1,0 to look upside-down)
		);
}
void GraphicsCamera::ModelMatrix(/*glm::mat4 modelMatrix*/)
{
	// Model matrix : an identity matrix (model will be at the origin)
	mModel = glm::mat4(1.0f);
}
glm::mat4 GraphicsCamera::MVPMatrix()
{
	// Our ModelViewProjection : multiplication of our 3 matrices
	mMVP = mProjection * mView * mModel;
	return mMVP; // Remember, matrix multiplication is the other way around
}