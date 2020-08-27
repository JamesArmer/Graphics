#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class RedBall :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	RedBall();
	~RedBall() { };
	void Display();
private:
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);

	bool animationEnabled = false;

	GLUquadric* qobj;
	GLuint football = Scene::GetTexture("Textures/stadium_cpp/football.bmp");

	float aT = 0;
	float animationTime = 4;
	float ballRotation2 = 0;
	float ballX2 = 45.5f;
	float ballY2 = 0.2f;
	float ballZ2 = -6.f;
};
