#include "Person.h"
#include "VectorMath.h"


Person::Person() :animationTime(0.f), animationRotation(0.0f), keyFrame(0)
{
	angles = new float[4]{ -30.0f,-30.0f,-90.0f,0.0f };	// initial angles for the 4 directions of the 2 joints
}

void Person::Display()
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
	glRotatef(rotation[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotation[2], 0.0f, 0.0f, 1.0f);

	drawPerson();

	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	glPopMatrix();
}

void Person::setTextures(GLuint* _texids)
{
	texids = _texids;                       // Store texture references in pointer array
	toTexture = true;                       // Assume all loaded correctly
	for (int i = 0; i < 3; i++)             // Check if any textures failed to load (NULL)    
		if (texids[i] == NULL) toTexture = false;   // If one texture failed, do not display any
}

void Person::drawPerson() {
	//Bottom of chest 
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}
	GLUquadric *quad;
	quad = gluNewQuadric();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricTexture(quad, true);

	glPushMatrix();
	glScalef(1.0f, 1.0f, 0.5f);
	drawCylinder(10.0f,3.0f,4.5f);
	glPopMatrix();//reset

	glTranslatef(-2.0f, 0.0f, 0.0f);
	drawLeg(0, 0, 0, 0);//left leg
	glTranslatef(4.0f, 0.0f, 0.0f);
	drawLeg(0, 0, 0, 0);//right leg

	//Going to top to draw neck
	glTranslatef(-2.0f, 9.0f, 0.0f);

	glPushMatrix();
	drawCylinder(3.5f, 1.0f, 1.0f);//neck
	glTranslatef(-5.5f, 0.0f, 0.0f);
	glPushMatrix();
	glScalef(0.75f, 0.75f, 0.75f);
	drawLimb(angles[0], angles[1], angles[2], angles[3], 1);//right arm
	glPopMatrix();

	glTranslatef(11.0f, 0.0f, 0.0f);

	glPushMatrix();
	glScalef(0.75f, 0.75f, 0.75f);
	drawLimb(0, 0, 0, 0, 0);//left arm
	drawShield(5, 5, 10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 4.0f, 0.0f);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	gluSphere(quad, 4.0f, 100.0f, 20.0f);//head
	glPopMatrix();

}

void Person::drawLimb(float topJointX, float topJointZ, float bottomJointX, float bottomJointZ, int sword) {
	if (toTexture)
		glEnable(GL_TEXTURE_2D);
	GLUquadric *quad;
	quad = gluNewQuadric();
	glRotatef(topJointX, 1.0f, 0.0f, 0.0f);
	glRotatef(topJointZ, 0.0f, 0.0f, 1.0f);

	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);

	glPushMatrix();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricTexture(quad, true);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);	//rotating textures between joints and skin
	gluSphere(quad, 3.0f, 100.0f, 20.0f);//joint

	glTranslatef(0.0f, -8.75f, 0.0f);//halfway point
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	drawCylinder(7.25f, 1.5f,1.5f); //skin
	glRotatef(bottomJointX, 1.0f, 0.0f, 0.0f);
	glRotatef(bottomJointZ, 0.0f, 0.0f, 1.0f);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);
	gluSphere(quad, 2.0f, 100.0f, 20.0f);//joint

	glPushMatrix();
	glTranslatef(0.0f, -8.75f, 0.0f);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	drawCylinder(7.25f, 1.5f, 1.5f); // skin
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);

	gluSphere(quad, 2.0f, 100.0f, 20.0f);//joint

	if (sword == 1) {
		glRotatef(25.0f, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 5.0f, -10.0f);
		drawSpear();
	}
	glPopMatrix();
	glPopMatrix();

	if (toTexture) glDisable(GL_TEXTURE_2D);    // Disable texturing until reenabled
	glEnable(GL_LIGHTING);                      // Reenable lighting after drawing skybox
}

void Person::drawLeg(float topJointX, float topJointZ, float bottomJointX, float bottomJointZ) {
	GLUquadric *quad;
	quad = gluNewQuadric();

	glRotatef(topJointX, 1.0f, 0.0f, 0.0f);	//animations telling which angle to rotate
	glRotatef(topJointZ, 0.0f, 0.0f, 1.0f);
	if (toTexture)
		glEnable(GL_TEXTURE_2D);

	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);

	glPushMatrix();
	gluQuadricNormals(quad, GLU_SMOOTH);
	gluQuadricDrawStyle(quad, GLU_FILL);
	gluQuadricTexture(quad, true);

	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);
	gluSphere(quad, 2.0f, 100.0f, 20.0f);//top joint
	glTranslatef(0.0f, -8.75f, 0.0f);//knee point to draw cylinder up

	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	drawCylinder(7.25f, 1.5f, 1.5f); // draws thigh
	glRotatef(bottomJointX, 1.0f, 0.0f, 0.0f);
	glRotatef(bottomJointZ, 0.0f, 0.0f, 1.0f);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);

	gluSphere(quad, 2.0f, 100.0f, 20.0f);//left knee
	glPushMatrix();
	glTranslatef(0.0f, -8.75f, 0.0f);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);

	drawCylinder(7.25f, 1.5f, 1.5f); // draws shin
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[0]);

	gluSphere(quad, 2.0f, 100.0f, 20.0f);//ankle
	glPopMatrix();
	glPopMatrix();

	if (toTexture) glDisable(GL_TEXTURE_2D);    // Disable texturing until reenabled
	glEnable(GL_LIGHTING);                      // Reenable lighting after drawing skybox
}


void Person::drawCylinder(float h, float rb, float rt) {
	glPushMatrix();
	glDisable(GL_CULL_FACE);	//stops seethrough backside
	GLUquadric *qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);	//allows texturing
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, true);
	glRotatef(-90.0f, 1, 0, 0);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	gluCylinder(qobj, rb, rt, h, 30, 16);
	glPopMatrix();
}

void Person::drawChestCylinder() {
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	GLUquadric *qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, true);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(qobj, 3.f, 4.5f, 10.f, 30, 16);
	glPopMatrix();
}

void Person::drawSpear() {
	glPushMatrix();
	glRotatef(35.0f, 1.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, -15.0f, 11.0f);
	GLUquadric *qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[1]);
	drawCylinder(40.0f,1.5f,1.5f);
	glTranslatef(0.0f, 40.0f, 0.0f);
	glRotatef(-90.0f, 1, 0, 0);
	gluCylinder(qobj, 2.0f, 0.0f, 4.0f, 30, 16);
	glPopMatrix();
}


void Person::drawShield(GLfloat x, GLfloat y, GLfloat radius) {
	glPushMatrix();
	glDisable(GL_CULL_FACE);
	glTranslatef(2.0f, -20.0f, 3.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	GLfloat twicePi = 2.0f * M_PI;
	if (toTexture) {
		glEnable(GL_TEXTURE_2D);
	}
	if (toTexture) glBindTexture(GL_TEXTURE_2D, texids[2]);
	glBegin(GL_TRIANGLE_FAN);
	
	if (toTexture) glTexCoord2f(0.5f,0.5f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(x, y, 3); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		if (toTexture) glTexCoord2f(0.5f + (0.5f * cos(i *  twicePi / triangleAmount)), 0.5f + (0.5f * sin(i *  twicePi / triangleAmount)));		//coordinate maths
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}

	glEnd();
	glPopMatrix();

}

void Person::Update(const double & deltaTime)
{
	animationTime += static_cast<float>(deltaTime);
	animationRotation += static_cast<float>(deltaTime);
	if (animationTime > 2.0f) {
		animationTime = 0.0f;
		animationRotation = 0.0f;
		keyFrame = 0;

		// {shoulderX, shoulderZ, elbowX, elbowZ}
		angles = new float[4]{ -30.0f,-30.0f,-90.0f,0.0f };
		//angles = new float[4]{ -130.0f, -30.0f,-20.0f,0.0f };

	}
	else if (animationTime < 1.0f) {
		if (keyFrame == 0) {
			keyFrame = 1;
			animationRotation = 0.0f;
		}

		if (angles[0] >= -130.0f)
		{
			angles[0] = -30.f - (animationRotation * 100);
			if (angles[0] < -130.0f) {
				angles[0] = -130.0f;
			}
		}

		if (angles[2] <= -20.0f)
		{
			angles[2] = -90.f + (animationRotation * 70);
			if (angles[2] > -20.0f) {
				angles[2] = -20.0f;
			}
		}

	}

	else if (animationTime < 2.0f) {
		if (keyFrame == 1) {
			keyFrame = 2;
			animationRotation = 0.0f;
		}

		if (angles[0] <= -30.0f)
		{
			angles[0] = -130.0F + (animationRotation * 100);
			if (angles[0] > -30.0f) {
				angles[0] = -30.0f;
			}
		}

		if (angles[2] >= -90.0f)
		{
			angles[2] = -20.f - (animationRotation * 70);
			if (angles[2] < -90.0f) {
				angles[2] = -90.0f;
			}
		}

	}

}
