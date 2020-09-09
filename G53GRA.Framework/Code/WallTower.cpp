#include "WallTower.h"


WallTower::WallTower()
{
}

void WallTower::Display()
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
	glScalef(scale[0], scale[1], scale[2]);


	drawWallTower();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}

void WallTower::setTextures(GLuint* _texids)
{
	texids = _texids;                       // Store texture references in pointer array
	toTexture = true;                       // Assume all loaded correctly
	for (int i = 0; i < 1; i++)             // Check if any textures failed to load (NULL)    
		if (texids[i] == NULL) toTexture = false;   // If one texture failed, do not display any
}

void WallTower::drawWallTower() {
	if (toTexture) 
		glEnable(GL_TEXTURE_2D);

	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);

	glDisable(GL_CULL_FACE);
	//Draws tower cylinder
	glPushMatrix();

	GLUquadric *qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, true);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(qobj, 30.0f, 20.0f, 65.0f, 30, 16);


	glPopMatrix();
	glEnable(GL_CULL_FACE);

	//Draws top circular part of tower
	glPushMatrix();
	glTranslatef(0.0f, 65.0f, 0.0f);
	glScalef(45.0f, 15.0f, 45.0f);
	drawCircleCube();
	glPopMatrix();

	//Draw squares on top of circle
	glPushMatrix(); //TOP FRONT
	glTranslatef(0.0f,75.0f, 18.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//TOP BACK
	glTranslatef(0.0f, 75.0f, -18.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//TOP Left
	glTranslatef(18.0f, 75.0f, 0.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//TOP Right
	glTranslatef(-18.0f, 75.0f, 0.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//North West
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 75.0f, -18.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//South East
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 75.0f, 18.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//North East
	glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 75.0f, -18.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	glPushMatrix();//South West
	glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 75.0f, 18.0f);
	glScalef(6.0f, 8.0f, 8.0f);
	drawCircleCube();
	glPopMatrix();

	if (toTexture) glDisable(GL_TEXTURE_2D);    // Disable texturing until reenabled
	glEnable(GL_LIGHTING);                      // Reenable lighting after drawing skybox
}

void WallTower::drawCircleCube() {
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);
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
	if (toTexture) glDisable(GL_TEXTURE_2D);    // Disable texturing until reenabled
	glEnable(GL_LIGHTING);                      // Reenable lighting after drawing skybox
}
