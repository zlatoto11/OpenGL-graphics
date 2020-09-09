#include "Light.h"


Light::Light()
	:_positionalLight(1.0f)
{
	lightNumber = GL_LIGHT0;
}

Light::~Light()
{
}

void Light::Display()
{

	if (_positionalLight)
	{
		// Disable lighting on this geometry (since it is the source
		// of the light) so it will only be coloured by glColor call
		glDisable(GL_LIGHTING);

		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		// Match colour of sphere to diffuse colour of light
		glColor3f(1.0f,0.0f,0.0f);	//Color of light
		glTranslatef(pos[0], pos[1], pos[2]);	//translatign from Myscene
		glutSolidSphere(5, 5, 5);//Represent object in space.
		glPopAttrib();
		glPopMatrix();
		// Re-enable lighting after light source has been drawn
		glEnable(GL_LIGHTING);
	}
}

void Light::setLightColour(GLfloat amb[], GLfloat diff[], GLfloat spec[]) {
	_ambient = amb;
	_diffuse = diff;
	_specular = spec;
}

void Light::Update(const double& deltaTime)
{
	//_runtime += deltaTime	//for animation which did not end up getting used
	glEnable(GL_LIGHTING); 

	// Set properties GL_LIGHT0 (overwrites default global framework lighting)
	glLightfv(lightNumber , GL_AMBIENT, _ambient);
	glLightfv(lightNumber, GL_DIFFUSE, _diffuse);
	glLightfv(lightNumber, GL_SPECULAR, _specular);

	GLfloat lPosition[4] = { pos[0], pos[1], pos[2], _positionalLight };
	glLightfv(lightNumber, GL_POSITION, lPosition);

	// enable lightNumber with these defined properties
	glEnable(lightNumber);
}

void Light::setLightNumber(GLenum lightN) {
	lightNumber = lightN;	//allow for setting light numbers manually from myscene instead of having to do in here
}


void Light::HandleKey(unsigned char key, int state, int mx, int my)
{
	if (state && key == 'p') ToggleLightType();
}