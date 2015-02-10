#pragma once
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class GraphicsCamera
{
public:
	GraphicsCamera();
	~GraphicsCamera();
	void ProjectionMatix(double FOV, int screenWidth, int screenHeight, double nearPlane, double farPlane);
	void ModelMatrix(/*glm::mat4 modelMatrix*/);
	void CameraPosition(double x, double y, double z);
	void ViewVector(double x, double y, double z);
	void UpVector(double x, double y, double z);
	glm::mat4 MVPMatrix();
private:
	double mCamX, mCamY, mCamZ;
	double mViewX, mViewY, mViewZ;
	double mUpX, mUpY, mUpZ;
	glm::mat4 mProjection, mView, mModel,mMVP;
	void UpdateViewMatrix();
};

