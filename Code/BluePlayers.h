#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

class BluePlayers :
	public DisplayableObject,
	public Animation
{
public:
	BluePlayers();
	~BluePlayers() { };
	void Display();
private:
	void Update(const double& deltaTime);
	void cylinder(float h, float r);
	void Box(float sx, float sy, float sz);
	void person(bool isBlue);
	void animatedPlayer(float joint, float legX, bool isBlue);

	float aT = 0;
	float animationTime = 4;
	float joint1 = 0;
	float joint2 = 0;
	float legX1 = 0.f;
	float legX2 = 0.f;
};
