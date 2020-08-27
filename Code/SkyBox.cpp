#include "SkyBox.h"

Skybox::Skybox(bool nightMode)
{
	if (nightMode) {//select the mode which is called in MyScene
		isNight = true;
	}
}

void Skybox::Display()
{
	glTranslatef(0.f, -2.f, 500.f); //move into frame
	glPushMatrix();
	glScalef(120.f, 120.f, 120.f);
	drawSkybox();
	glPopMatrix();
}

//Draw a skybox
void Skybox::drawSkybox()
{
	if (isNight) { //change skybox textures depending on the lighting mode
		skybox_back = Scene::GetTexture("Textures/skybox_night_cpp/Ely7_px.bmp");
		skybox_front = Scene::GetTexture("Textures/skybox_night_cpp/Ely7_nx.bmp");
		skybox_left = Scene::GetTexture("Textures/skybox_night_cpp/Ely7_nz.bmp");
		skybox_right = Scene::GetTexture("Textures/skybox_night_cpp/Ely7_pz.bmp");
		skybox_up = Scene::GetTexture("Textures/skybox_night_cpp/Ely7_py.bmp");
	}
	else {
		skybox_back = Scene::GetTexture("Textures/skybox_cpp/skybox_back.bmp");
		skybox_down = Scene::GetTexture("Textures/skybox_cpp/skybox_down.bmp");
		skybox_front = Scene::GetTexture("Textures/skybox_cpp/skybox_front.bmp");
		skybox_left = Scene::GetTexture("Textures/skybox_cpp/skybox_left.bmp");
		skybox_right = Scene::GetTexture("Textures/skybox_cpp/skybox_right.bmp");
		skybox_up = Scene::GetTexture("Textures/skybox_cpp/skybox_up.bmp");
	}
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.f, 1.f, 1.f, 1.f);
	// NEAR SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_front);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, 1.f);
	glEnd();
	// FAR SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_back);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
	glEnd();
	// BOTTOM SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_down);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 0.f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 0.f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
	glEnd();
	// TOP SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_up);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
	glEnd();
	// LEFT SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_right);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(-1.f, 0.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
	glEnd();
	// RIGHT SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_left);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}

void Skybox::HandleKey(unsigned char key, int state, int x, int y) {
	if ((state == 1) && (key == '1')) {
		isNight = true;
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		printf("Night mode\n");
	}
	if ((state == 1) && (key == '2')) {
		isNight = false;
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glEnable(GL_LIGHT0);
		printf("Day mode\n");
	}
}