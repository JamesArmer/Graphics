#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class BlueBall :
	public DisplayableObject,
	public Animation
{
public:
	BlueBall();
	~BlueBall() { };
	void Display();
private:
	void Update(const double& deltaTime);

	GLUquadric* qobj;
	GLuint football = Scene::GetTexture("Textures/stadium_cpp/football.bmp");

	float aT = 0;
	float animationTime = 4;
	float ballRotation1 = 0;
	float ballX1 = 49.5f;
};
