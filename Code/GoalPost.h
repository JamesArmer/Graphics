#pragma once

#include "DisplayableObject.h"

class GoalPost :
	public DisplayableObject
{
public:
	GoalPost();
	~GoalPost() { };
	void Display();
private:
	void cylinder(float h, float r);
};
