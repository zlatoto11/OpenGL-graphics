#include "MyScene.h"
#include "Light.h"
#include "ActualWall.h"
#include "WallTower.h"
#include "Person.h"
#include "Door.h"
#include "Mountain.h"
#include "Stage.h"
#include "Catapult.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Stage *stage = new Stage();         // new instance of Stage object  

	GLuint* skybox = new GLuint[5];
	skybox[0] = GetTexture("Textures/Skybox/skybox_front.bmp");
	skybox[1] = GetTexture("Textures/Skybox/skybox_back.bmp");
	skybox[2] = GetTexture("Textures/Skybox/skybox_left.bmp");
	skybox[3] = GetTexture("Textures/Skybox/skybox_right.bmp");
	skybox[4] = GetTexture("Textures/Skybox/skybox_down.bmp");
	skybox[5] = GetTexture("Textures/Skybox/skybox_up.bmp");
	stage->setTextures(skybox);

	stage->size(600, 430.0f , 600.0f);                // resize to bound scene
	stage->position(0.0f, -100.0, 450.0f);
	AddObjectToScene(stage);

	Light *l2 = new Light();
	l2->setLightNumber(GL_LIGHT1);
	l2->position(-65.0f, 0.0f, 270.0f);

	static GLfloat ambient2[] = { 0.15f, 0.15f, 0.1f, 0.5f };
	static GLfloat diffuse2[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	static GLfloat specular2[] = { 0.5f, 0.5f, 0.5f, 0.0f };

	l2->setLightColour(ambient2, diffuse2, specular2);

	AddObjectToScene(l2);
	
	GLuint wallTexture = GetTexture("Textures/CastleWall.bmp");
	// Right Side
	ActualWall *wfrontright = new ActualWall(wallTexture);
	wfrontright->position(0.0f, 0.0f, 500.0f);
	AddObjectToScene(wfrontright);
	

	WallTower *wt = new WallTower;

	GLuint* towerTexture = new GLuint[1];
	towerTexture[0] = GetTexture("Textures/CastleWall.bmp");
	wt->setTextures(towerTexture);

	wt->position(75.0f, -25.0f, 500.0f);
	wt->size(1.4f,1.4f,1.4f);
	AddObjectToScene(wt);

	ActualWall *w2right = new ActualWall(wallTexture);
	w2right->position(77.0f, 0.0f, 425.0f);
	w2right->orientation(0.0f, 90.0f, 0.0f);
	AddObjectToScene(w2right);

	ActualWall *w3right = new ActualWall(wallTexture);
	w3right->position(77.0f, 0.0f, 300.0f);
	w3right->orientation(0.0f, 90.0f, 0.0f);
	AddObjectToScene(w3right);

	WallTower *wtrb = new WallTower;
	wtrb->position(75.0f, -25.0f, 230.0f);
	wtrb->size(1.4f, 1.4f, 1.4f);
	wtrb->setTextures(towerTexture);
	AddObjectToScene(wtrb);

	ActualWall *wbackright = new ActualWall(wallTexture);
	wbackright->position(0.0f, 0.0f, 230.0f);
	AddObjectToScene(wbackright);

	//Left Side
	ActualWall *wbackleft = new ActualWall(wallTexture);
	wbackleft->position(-125.0f, -0.0f, 230.0f);
	AddObjectToScene(wbackleft);

	WallTower *wtbl = new WallTower;
	wtbl->position(-200.0f, -25.0f, 230.0f);
	wtbl->size(1.4f, 1.4f, 1.4f);
	wtbl->setTextures(towerTexture);
	AddObjectToScene(wtbl);

	ActualWall *w2bleft = new ActualWall(wallTexture);
	w2bleft->position(77.0f, 0.0f, 425.0f);
	w2bleft->orientation(0.0f, 90.0f, 0.0f);
	AddObjectToScene(w2bleft);

	ActualWall *wfrontleft = new ActualWall(wallTexture);
	wfrontleft->position(-125.0f, 0.0f, 500.0f);
	AddObjectToScene(wfrontleft);

	WallTower *wtlf = new WallTower;
	wtlf->position(-200.0f, -25.0f, 500.0f);
	wtlf->size(1.4f, 1.4f, 1.4f);
	wtlf->setTextures(towerTexture);
	AddObjectToScene(wtlf);

	ActualWall *w2left = new ActualWall(wallTexture);
	w2left->position(-200.0f, 0.0f, 425.0f);
	w2left->orientation(0.0f, -90.0f, 0.0f);
	AddObjectToScene(w2left);

	ActualWall *w3left = new ActualWall(wallTexture);
	w3left->position(-200, 0.0f, 300.0f);
	w3left->orientation(0.0f, -90.0f, 0.0f);
	AddObjectToScene(w3left);
	

	GLuint* chainmail = new GLuint[5];
	chainmail[0] = GetTexture("Textures/chainmail.bmp");
	chainmail[1] = GetTexture("Textures/chainmail2.bmp");
	chainmail[2] = GetTexture("Textures/shieldTexture.bmp");
	Person *p = new Person;
	p->position(-37.5f, -5.0f, 545.0f);
	p->setTextures(chainmail);
	p->orientation(0.0f, -90.0f, 0.0f);
	AddObjectToScene(p);

	Person *p2 = new Person;
	p2->position(-87.5f, -5.0f, 545.0f);
	p2->setTextures(chainmail);
	p2->orientation(0.0f, 90.0f, 0.0f);
	AddObjectToScene(p2);


	GLuint doorT = GetTexture("Textures/castleDoor.bmp");
	Door *d = new Door(doorT);

	d->position(-62.5, -5.0f, 523.0f);
	d->size(0.8f, 1.1f, 0.7f);
	AddObjectToScene(d);

	Door *d2 = new Door(doorT);

	d2->position(-62.5, -5.0f, 477.0f);
	d2->size(0.8f, 1.1f, 0.7f);
	AddObjectToScene(d2);

	GLuint mountainTexture = GetTexture("Textures/MossyTexture.bmp");
	Mountain *m = new Mountain(mountainTexture);
	m->position(-75.0f, -62.0f, 375.0f);
	m->size(1.0f, 0.5f, 1.0f);
	AddObjectToScene(m);

	GLuint catapultTexture = GetTexture("Textures/catapultTexture.bmp");
	GLuint stoneTexture = GetTexture("Textures/stoneTexture.bmp");
	GLuint wheelTexture = GetTexture("Textures/wheelTexture.bmp");

	Catapult* c = new Catapult(catapultTexture,wheelTexture,stoneTexture);
	c->position(-25.0f, -20.0f, 350.0f);
	c->size(0.6f, 0.7f, 0.7f);
	AddObjectToScene(c);

	Catapult* c2 = new Catapult(catapultTexture,wheelTexture, stoneTexture);
	c2->position(-150.0f, -20.0f, 350.0f);
	c2->size(0.6f, 0.7f, 0.7f);
	AddObjectToScene(c2);
}



void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 3000.0f);
}
