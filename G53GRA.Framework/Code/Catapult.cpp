#include "Catapult.h"
#include "VectorMath.h"

Catapult::Catapult()
{
	angle = 0.0f;
}

Catapult::Catapult(GLuint _catapultTexture, GLuint _wheelTexture, GLuint _stoneTexture)
	:animationTime(0.f),animationRotation(0.f),keyFrame(0)
{
	catapultTexture = _catapultTexture;
	wheelTexture = _wheelTexture;
	stoneTexture = _stoneTexture;
	if (catapultTexture) {
		toTexture = true;
	}

}
void Catapult::Display()
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

	glTranslatef(pos[0], pos[1], pos[2]);	//Allow to be translated from MyScene.cpp
	glRotatef(rotation[0], 1.0f, 0.0f, 0.0f); //Allows to be rotated from Myscene.cpp
	glRotatef(rotation[1], 0.0f, 1.0f, 0.0f); //Allows to be rotated from Myscene.cpp
	glRotatef(rotation[2], 0.0f, 0.0f, 1.0f); //Allows to be rotated from Myscene.cpp
	glScalef(scale[0], scale[1], scale[2]); //Allows to be scaled from Myscene.cpp

	drawMyCatapult();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}

void Catapult::drawMyCatapult() {
	
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}
	if (toTexture) glBindTexture(GL_TEXTURE_2D, wheelTexture);
	//Draw Catapult Wheels
	glPushMatrix();
	glPushMatrix();

	GLUquadric *quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricTexture(quad, true);

	for (int i = 0; i < 4; i++) {
			gluSphere(quad, 8.0f, 100.0f, 20.0f);//top joint
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, 100.0f);
		}
	glPopMatrix();

	//Draw Catapult Base
	glTranslatef(0.0f, 0.0f, -50.0f);
	
	glPushMatrix();
	glScalef(8.0f, 4.0f, 92.5f);
	drawCube();
	glPopMatrix();
	
	glTranslatef(100.0f, 0.0f, 0.0f);

	glPushMatrix();
	glScalef(8.0f, 4.0f, 92.5f);
	drawCube();
	glPopMatrix();

	glTranslatef(-50.0f, 0.0f, -25.0f);

	glPushMatrix();
	glScalef(100.0f, 2.0f, 20.0f);
	drawCube();
	glPopMatrix();
	glPopMatrix();
	
	//Left side legs 
	glPushMatrix();
	glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -30.0f);
	glScalef(8.0f, 4.0f, 60.0f);
	drawCube();
	glPopMatrix();

	glTranslatef(0.0f,0.0f,-100.0f);

	glPushMatrix();
	glRotatef(145.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -35.0f);
	glScalef(8.0f, 4.0f, 75.0f);
	drawCube();
	glPopMatrix();

	//Right side side legs 

	glTranslatef(100.0f, 0.0f, 100.0);
	glPushMatrix();
	glPushMatrix();
	glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -30.0f);
	glScalef(8.0f, 4.0f, 60.0f);
	drawCube();
	glPopMatrix();

	glTranslatef(0.0f, 0.0f, -100.0f);

	glPushMatrix();
	glRotatef(145.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -35.0f);
	glScalef(8.0f, 4.0f, 75.0f);
	drawCube();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	//Center Piece stabilisations
	glTranslatef(-50.0f, 40.0f, -40.0f);

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glScalef(8.0f, 4.0f, 100.0f);
	drawCube();
	
	glPopMatrix();

	drawCatapultArm(0.0f);

	//Cannonball
	glTranslatef(0.0f, 15.0f, 0.0f);
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}

	if (toTexture) glBindTexture(GL_TEXTURE_2D, stoneTexture);
	gluSphere(quad, 10.0f, 100.0f, 20.0f);//top joint
}

void Catapult::drawCatapultArm(float armAngleX) {
	//Catapult Arm
	glRotatef(armAngleX, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glRotatef(-35.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0, -5.0f);
	glScalef(12.0f, 4.0f, 100.0f);
	drawCube();
	glPopMatrix();
	glPopMatrix();
	//Catapult Throwing Thing
	glTranslatef(-50.0f, 0.0f, -100.0f);
	glPushMatrix();
	glRotatef(-35.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 8.0f);
	glScalef(25.0f, 7.0f, 24.0f);
	drawCube();
	glPopMatrix();
}
void Catapult::drawCube() {

	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}

	if (toTexture) glBindTexture(GL_TEXTURE_2D, catapultTexture);
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

void Catapult::Update(const double & deltaTime) {
	animationTime += static_cast<float>(deltaTime);
	animationRotation += static_cast<float>(deltaTime);
	if (animationTime > 2.0f) {
		animationTime = 0.0f;
		animationRotation = 0.0f;
		keyFrame = 0;
	}

	else if (animationTime < 0.5f) {
		if (keyFrame == 0) {
			keyFrame = 1;
			animationRotation = 0.0f;
		}

		if (angle >= -130.0f)
		{
			angle = -30.f - (animationRotation * 100);
			if (angle < -130.0f) {
				angle = -130.0f;
			}
		}

	}
}



	