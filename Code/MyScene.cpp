#include "MyScene.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear buffers
	glMatrixMode(GL_MODELVIEW);                         // set for model and viewing operations
	glLoadIdentity();                                   // reset drawing

	//NOTE: use 1/2 to change the lighting and 3/4 to trigger/stop the free-kick animation

	float mat_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f }; //shading
	float mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	float mat_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float mat_shininess[] = { 40.0 }; // 0-128

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	GLfloat position1[] = { 31.f, 0.f, 2.5f, 0.f };//red light
	glLightfv(GL_LIGHT1, GL_POSITION, position1);

	GLfloat position2[] = { 0.f, 60.f, 0.f, 1.f };//global light for sunset mode
	glLightfv(GL_LIGHT2, GL_POSITION, position2);

	GLfloat ambience1[] = { 0.f, 0.f, 0.f, 1.0f };
	GLfloat diffuse1[] = { 1.f, 0.f, 0.f, 1.f };
	GLfloat specular1[] = { 0.5f, 0.5f, 0.5f, 1.0f };

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambience1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 0.01);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.00005);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.05);

	GLfloat ambience2[] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat diffuse2[] = { 0.2f, 0.2f, 0.2f, 1.f };
	GLfloat specular2[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat direction[] = { -1, 0, 0 };//light going from left to right in the x-direction

	glLightfv(GL_LIGHT2, GL_AMBIENT, ambience2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, specular2);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, direction);
	
	glDisable(GL_LIGHT1);//initial lighting and skybox set to daytime mode
	glDisable(GL_LIGHT2);
	glEnable(GL_LIGHT0);
	Skybox* sb = new Skybox(false);
	CarPark* cp = new CarPark(false);	

	Stadium* std = new Stadium();
	GoalPost* gp = new GoalPost();
	FloodLights* fl = new FloodLights();
	BluePlayers* bp = new BluePlayers();
	RedPlayers* rp = new RedPlayers();
	BlueBall* bb = new BlueBall();
	RedBall* rb = new RedBall();

	AddObjectToScene(sb);
	AddObjectToScene(std);
	AddObjectToScene(gp);
	AddObjectToScene(fl);
	AddObjectToScene(bp);
	AddObjectToScene(rp);
	AddObjectToScene(bb);
	AddObjectToScene(rb);
	AddObjectToScene(cp);
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 1000.0);
}


