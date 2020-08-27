#pragma once

#include "../Framework/Engine/Scene.h"
#include "SkyBox.h"
#include "Stadium.h"
#include "GoalPost.h"
#include "FloodLights.h"
#include "CarPark.h"
#include "BluePlayers.h"
#include "RedPlayers.h"
#include "BlueBall.h"
#include "RedBall.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};

private:
	void Initialise();
	void Projection();
};