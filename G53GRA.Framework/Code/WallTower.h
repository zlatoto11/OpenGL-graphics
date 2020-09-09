#pragma once
#include "DisplayableObject.h"
class WallTower :
	public DisplayableObject
{
public:
	WallTower();
	void Display();
	void drawWallTower();
	void drawCircleCube();
	void setTextures(GLuint* _texids);
private:
	bool toTexture = false;
	GLuint* texids;
};

