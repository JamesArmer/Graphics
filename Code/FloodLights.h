#pragma once

#include "DisplayableObject.h"

class FloodLights:
	public DisplayableObject
{
public:
	FloodLights();
	~FloodLights() { };
	void Display();
private:
	void pyramidLight();
	void cylinder(float h, float r);
};

