#pragma once
#include "DisplayableObject.h"
class ActualWall :
	public DisplayableObject
{
public:
	ActualWall();
	void Display();
	void drawMyWall();
	void drawMyCube();
	ActualWall(GLuint _wallTexture);
private: 
	bool toTexture;
	GLuint wallTexture;
};


