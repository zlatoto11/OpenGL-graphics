#pragma once
#include "DisplayableObject.h"
class Door :
	public DisplayableObject
{
public:
	Door();
	void Display();
	void drawDoor();
	Door(GLuint _wallTexture);

private:
	bool toTexture;
	GLuint doorTexture;
};

