#include "Mountain.h"



Mountain::Mountain()
{
	
}

Mountain::Mountain(GLuint _mountainTexture) {
	mountainTexture = _mountainTexture;
	if (mountainTexture != NULL) {
		toTexture = true;
	}
}

void Mountain::Display()
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
	glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(rotation[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);	//editign from MyScene etc...
	glRotatef(rotation[2], 0.0f, 0.0f, 1.0f);
	glScalef(scale[0], scale[1], scale[2]);

	drawMyMountain();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}

void Mountain::drawMyMountain() {
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}

	if (toTexture) glBindTexture(GL_TEXTURE_2D, mountainTexture);
	glBegin(GL_QUADS);

	// Green side - LEFT
	glNormal3f(-1.0f, 0.0f, 0.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(-300.0f, -75.0f, 300.0f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(-200.0f, 75.0f, 200.0f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(-200.0f, 75.0f, -200.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-300.0f, -75.0f, -300.0f);

	//Multi-colored side - FRONT
	glNormal3f(0.0f, 0.0f, 1.0f);
	if (toTexture) glTexCoord2f(2.f, 0.f);
	glVertex3f(300.0f, -75.0f, 300.0f);
	if (toTexture) glTexCoord2f(2.f, 2.f);
	glVertex3f(200.0f, 75.0f, 200.0f);
	if (toTexture) glTexCoord2f(0.f, 2.f);
	glVertex3f(-200.0f, 75.0f, 200.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-300.0f, -75.0f, 300.0f);

	// Red side - BOTTOM
	glNormal3f(0.0f, -1.0f, 0.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-300.0f, -75.0f, 300.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(-300.0f, -75.0f, -300.0f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(300.0f, -75.0f, -300.0f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(300.0f, -75.0f, 300.0f);

	// White side - BACK
	glNormal3f(0.0f, 0.0f, -1.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(-300.0f, -75.0f, -300.0f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(-200.0f, 75.0f, -200.0f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(200.0f, 75.0f, -200.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(300.0f, -75.0f, -300.0f);

	// Blue side - TOP
	glNormal3f(0.0f, 1.0f, 0.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(200.0f, 75.0f, 200.0f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(200.0f, 75.0f, -200.0f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(-200.0f, 75.0f, -200.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(-200.0f, 75.0f, 200.0f);

	// Purple side - RIGHT
	glNormal3f(1.0f, 0.0f, 0.0f);
	if (toTexture) glTexCoord2f(1.f, 0.f);
	glVertex3f(300.0f, -75.0f, -300.0f);
	if (toTexture) glTexCoord2f(1.f, 1.f);
	glVertex3f(200.0f, 75.0f, -200.0f);
	if (toTexture) glTexCoord2f(0.f, 1.f);
	glVertex3f(200.0f, 75.0f, 200.0f);
	if (toTexture) glTexCoord2f(0.f, 0.f);
	glVertex3f(300.0f, -75.0f, 300.0f);

	glEnd();

	if (toTexture) {
		glDisable(GL_TEXTURE_2D);
	}
}