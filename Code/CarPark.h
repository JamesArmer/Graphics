#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class CarPark :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	CarPark(bool nightMode);
	~CarPark() { };
	void Display();
	
private:
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);
	void lampPost();
	void cylinder(float h, float r);
	void Box(float sx, float sy, float sz, GLuint texture);
	void car(bool isBlue);

	GLUquadric* qobj;
	GLuint road = Scene::GetTexture("Textures/stadium_cpp/road.bmp");

	bool isNight = false;

	float aT = 0;
	float animationTime = 16;
	float carX = -110.f;
};

