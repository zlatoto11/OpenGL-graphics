#pragma once
#include "DisplayableObject.h"
class Mountain :
	public DisplayableObject
{
public:
	Mountain();
	Mountain(GLuint _mountainTexture);
	void Display();
	void drawMyMountain();
private:
	bool toTexture;
	GLuint mountainTexture;
};

