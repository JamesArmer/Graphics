#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

class RedPlayers :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	RedPlayers();
	~RedPlayers() { };
	void Display();
private:
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int x, int y);
	void cylinder(float h, float r);
	void Box(float sx, float sy, float sz);
	void person(bool isBlue);
	void animatedPlayer(float joint, float legX, bool isBlue);
	void animatedGoalkeeper(float joint, float armY);

	bool animationEnabled = false;

	float aT = 0;
	float animationTime = 4;
	float joint1 = 0;
	float joint2 = 0;
	float legX1 = 0.f;
	float legX2 = 0.f;
	float personZ = -2.f;
	float armJoint = 0;
	float armY = -5.f;
	float rotateGK = 0.f;
	float gkX = 1.5f;
	float gkY = 0.f;
};
