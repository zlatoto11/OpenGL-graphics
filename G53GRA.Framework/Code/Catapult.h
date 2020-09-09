#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Catapult :
	public DisplayableObject,
	public Animation
{
public:
	Catapult();
	void drawMyCatapult();
	void Update(const double & deltaTime);
	void Display();
	void drawMyCatapult(float Angle);
	void drawCatapultArm(float armAngleX);
	void drawCube();
	Catapult(GLuint _catapultTexture,GLuint _stoneTexture, GLuint _wheelTexture);
private:
	bool toTexture;
	GLuint catapultTexture;
	GLuint stoneTexture;
	GLuint wheelTexture;

	float animationTime, animationRotation;
	int keyFrame;

	float angle;
};

