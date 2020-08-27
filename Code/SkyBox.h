#ifndef ___SkyBox__
#define ___SkyBox__

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include <cmath>
#include <string>

using namespace std;

class Skybox :
	public DisplayableObject,
	public Input
{
public:
	Skybox(bool nightMode);                                 // constructor
	~Skybox() { };                            // destructor
	void Display();                         // overloaded virtual Display function
private:
	void drawSkybox();
	void HandleKey(unsigned char key, int state, int x, int y);
	bool isNight = false;
	GLuint skybox_back = Scene::GetTexture("Textures/skybox_cpp/skybox_back.bmp");
	GLuint skybox_down = Scene::GetTexture("Textures/skybox_cpp/skybox_down.bmp");
	GLuint skybox_front = Scene::GetTexture("Textures/skybox_cpp/skybox_front.bmp");
	GLuint skybox_left = Scene::GetTexture("Textures/skybox_cpp/skybox_left.bmp");
	GLuint skybox_right = Scene::GetTexture("Textures/skybox_cpp/skybox_right.bmp");
	GLuint skybox_up = Scene::GetTexture("Textures/skybox_cpp/skybox_up.bmp");
};
#endif