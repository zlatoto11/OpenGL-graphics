#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#include <cmath>

class Light :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Light();
	~Light();

	// Could use to represent light source with sphere (optional)
	void Display();

	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int mx, int my);

	inline void ToggleLightType() { _positionalLight = fmod(_positionalLight + 1.f, 2.f); }

	void setLightNumber(GLenum lightN);
	GLenum lightNumber;

	void setLightColour(GLfloat ambient[], GLfloat diffuse[], GLfloat specular[]);

private:

	// reflectance model parameters for LIGHT
	GLfloat *_ambient, *_diffuse, *_specular;

	// flag for indicating positional or directional light source
	// 0.0f for directional, 1.0f for positional
	GLfloat _positionalLight;

	

};

