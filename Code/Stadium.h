#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class Stadium:
	public DisplayableObject,
	public Animation
{
public:
	Stadium();
	~Stadium() { };	
	void Display();	
private:
	void Update(const double& deltaTime);
	void Box(float sx, float sy, float sz, GLuint texture);
	void stadSide(float scalez);
	void stadCorner();
	void antiAliasing();

	GLuint stadRoof = Scene::GetTexture("Textures/stadium_cpp/metal050.bmp");
	GLuint stadWall = Scene::GetTexture("Textures/stadium_cpp/metal.bmp");
	GLuint field = Scene::GetTexture("Textures/stadium_cpp/football-field.bmp");
	GLuint crowd = Scene::GetTexture("Textures/stadium_cpp/crowd.bmp");
	GLuint concrete = Scene::GetTexture("Textures/stadium_cpp/concrete.bmp");
	GLuint liverpool = Scene::GetTexture("Textures/stadium_cpp/liverpool-fc-flag.bmp");
	GLuint chelsea = Scene::GetTexture("Textures/stadium_cpp/chelsea-fc-flag.bmp");

	GLuint currentFlag = liverpool;

	float aT = 0;
	float animationTime = 10;
};

