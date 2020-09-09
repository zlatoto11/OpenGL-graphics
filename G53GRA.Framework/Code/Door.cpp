#include "Door.h"



Door::Door()
{
}


void Door::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glDisable(GL_COLOR_MATERIAL);
	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float shininess = 128.0f;

	glMaterialfv(GL_FRONT, GL_SPECULAR, static_cast<GLfloat*>(specular));
	glMaterialf(GL_FRONT, GL_SHININESS, static_cast<GLfloat>(shininess));
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, static_cast<GLfloat*>(diffuse));
	glTranslatef(pos[0], pos[1], pos[2]);	//Allows for translating from MyScene
	glScalef(scale[0], scale[1], scale[2]); //Allows for scaling from MyScene

	glScalef(50.0f, 50.0f, 10.0f);
	drawDoor();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}

Door::Door(GLuint _doorTexture) {
	doorTexture = _doorTexture;
	if (doorTexture != NULL) {
		toTexture = true;
	}
}

void Door::drawDoor() {

	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}

	if (toTexture) glBindTexture(GL_TEXTURE_2D, doorTexture);

	glBegin(GL_QUADS);

	// Green side - LEFT
	glNormal3f(-1.0f, 0.0f, 0.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	//Multi-colored side - FRONT
	glNormal3f(0.0f, 0.0f, 1.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	// Red side - BOTTOM
	glNormal3f(0.0f, -1.0f, 0.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	// White side - BACK
	glNormal3f(0.0f, 0.0f, -1.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	// Blue side - TOP
	glNormal3f(0.0f, 1.0f, 0.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	// Purple side - RIGHT
	glNormal3f(1.0f, 0.0f, 0.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glEnd();

	if (toTexture) {
		glDisable(GL_TEXTURE_2D);
	}
}