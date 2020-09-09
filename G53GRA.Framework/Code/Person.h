#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Person :
	public DisplayableObject,
	public Animation
{
public:
	Person();
	void Display();
	void drawPerson();
	void drawLimb(float topJointX, float topJointZ, float bottomJointX, float bottomJointZ, int sword = 0);
	void drawLeg(float topJointX, float topJointZ, float bottomJointX, float bottomJointZ);
	//void drawCylinder(float h, float r);
	void drawCylinder(float h, float rb, float rt);
	void drawChestCylinder();
	void drawSpear();
	void drawShield(GLfloat x, GLfloat y, GLfloat radius);
	void Update(const double &deltaTime);

	void setTextures(GLuint* _texids);

private:
	float animationTime, animationRotation;
	int keyFrame;

	float* angles;

	bool toTexture = false;
	GLuint* texids;
};

