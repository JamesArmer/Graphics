#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Ball :
	public DisplayableObject,
	public Animation
{
public:
	Ball();
	~Ball() { };
	void Display();
	void Update(const double& deltaTime);
private:
	GLUquadric* qobj;
	GLuint football = Scene::GetTexture("Textures/stadium_cpp/football.bmp");

	float aT = 0;
	float animationTime = 4;
	float ballRotation1 = 0;
	float ballRotation2 = 0;
	float ballX1 = 49.5f;
	float ballX2 = 45.5f;
	float ballY2 = 0.2f;
	float ballZ2 = -6.f;
};
