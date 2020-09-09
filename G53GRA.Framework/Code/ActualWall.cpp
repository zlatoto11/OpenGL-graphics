#include "ActualWall.h"

ActualWall::ActualWall()
{
}

ActualWall::ActualWall(GLuint _wallTexture) {
	wallTexture = _wallTexture;
	if (wallTexture != NULL) {
		toTexture = true;
	}
}

void ActualWall::Display()
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
	glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotation[2], 0.0f, 0.0f, 1.0f);
	glScalef(scale[0], scale[1], scale[2]);

	drawMyWall();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}

void ActualWall::drawMyWall() {
	//Main Wall
	glPushMatrix();
	glScalef(125.0f, 50.0f, 50.0f);
	drawMyCube();
	glPopMatrix();

	//Smaller Wall on top
	glPushMatrix();
	glTranslatef(0.0f, 30.0f, 23.0f);
	glScalef(125.0f, 12.0f, 8.0f);
	drawMyCube();
	glPopMatrix();

	//Draw Front Small Blocks
	glPushMatrix();
	glTranslatef(-54.0f, 36.0f, 23.0f);

	glPushMatrix();
	glScalef(6.0f, 8.0f, 8.0f);
	drawMyCube();
	glPopMatrix();

	for (int i = 0; i < 9; i++) {
		glTranslatef(12.0f,0.0f,0.0f);

		glPushMatrix();

		glScalef(6.0f, 8.0f, 8.0f);
		drawMyCube();

		glPopMatrix();
	}

	glPopMatrix();

	//Smaller Wall on top -- BACK
	glPushMatrix();
	glTranslatef(0.0f, 30.0f, -23.0f);
	glScalef(125.0f, 12.0f, 8.0f);
	drawMyCube();
	glPopMatrix();

	//Draw Back Small Blocks
	glPushMatrix();
	glTranslatef(-54.0f, 36.0f, -23.0f);

	glPushMatrix();
	glScalef(6.0f, 8.0f, 8.0f);
	drawMyCube();
	glPopMatrix();

	for (int i = 0; i < 9; i++) {
		glTranslatef(12.0f, 0.0f, 0.0f);

		glPushMatrix();

		glScalef(6.0f, 8.0f, 8.0f);
		drawMyCube();

		glPopMatrix();
	}

	glPopMatrix();
}
void ActualWall::drawMyCube() {
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}

	if (toTexture) glBindTexture(GL_TEXTURE_2D, wallTexture);
	glBegin(GL_QUADS);

	// Green side - LEFT
	glNormal3f(-1.0f, 0.0f, 0.0f);	//normal values showing which direction is facing where
	if (toTexture) glTexCoord2f(1.f, 0.f);	//mapping texture to coordinates on object
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