#include "Stadium.h"

Stadium::Stadium() {

}

void Stadium::Display() {
	glPushMatrix();
	glTranslatef(50.f, 0.f, 0.f); //move to right of skybox

	glPushMatrix(); //left side
	glTranslatef(-28.f, 0.f, 16.f);
	stadSide(0.79f);
	for (int i = 0; i < 4; i++) {
		glTranslatef(0.f, 0.f, -7.9f);
		stadSide(0.79f);
	}
	glPopMatrix();

	glPushMatrix(); //right side
	glTranslatef(28.f, 0.f, 16.f);
	glRotatef(180.f, 0.f, 1.f, 0.f);
	stadSide(0.79f);
	for (int i = 0; i < 4; i++) {
		glTranslatef(0.f, 0.f, 7.9f);
		stadSide(0.79f);
	}
	glPopMatrix();

	glPushMatrix(); //top side
	glTranslatef(13.f, 0.f, -30.f);
	glRotatef(-90.f, 0.f, 1.f, 0.f);
	stadSide(0.8875f);
	for (int i = 0; i < 3; i++) {
		glTranslatef(0.f, 0.f, 8.875f);
		stadSide(0.8875f);
	}
	glPopMatrix();

	glPushMatrix(); //bottom side
	glTranslatef(13.5f, 0.f, 30.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	stadSide(0.8875f);
	for (int i = 0; i < 3; i++) {
		glTranslatef(0.f, 0.f, -8.875f);
		stadSide(0.8875f);
	}
	glPopMatrix();

	glPushMatrix(); //top left corner
	glTranslatef(-24.f, 0.f, -26.f);
	glRotatef(-45.f, 0.f, 1.f, 0.f);
	stadCorner();
	glPopMatrix();

	glPushMatrix(); //top right corner
	glTranslatef(24.f, 0.f, -26.f);
	glRotatef(-135.f, 0.f, 1.f, 0.f);
	stadCorner();
	glPopMatrix();

	glPushMatrix(); //bottom left corner
	glTranslatef(-24.f, 0.f, 26.f);
	glRotatef(45.f, 0.f, 1.f, 0.f);
	stadCorner();
	glPopMatrix();

	glPushMatrix(); //bottom right corner
	glTranslatef(24.f, 0.f, 26.f);
	glRotatef(135.f, 0.f, 1.f, 0.f);
	stadCorner();
	glPopMatrix();

	glPushMatrix(); //pitch
	Box(30.f, 0.01f, 40.f, field);
	glPopMatrix();

	glPushMatrix();//player tunnel
	glTranslatef(-22.f, 1.5f, 0.f);
	Box(8.f, 3.f, 4.f, concrete);
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(0.f, 0.f, 0.f);
	glTranslatef(4.01f, -2.f, 1.5f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 3.2f, 1.f);
	glDisable(GL_CULL_FACE);
	glBegin(GL_QUADS);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(1.f, 0.f, 0.f);
	glVertex3f(1.f, 1.f, 0.f);
	glVertex3f(0.f, 1.f, 0.f);
	glEnd();
	glPopAttrib();
	glPopMatrix();

	glPushMatrix();//tunnel lights
	glTranslatef(-19.f, 0.f, 2.5f);
	glPushAttrib(GL_CURRENT_BIT);
	glColor4f(1.f, 0.f, 0.f, 0.5f);
	glutSolidSphere(0.25f, 25, 25);
	glTranslatef(-2.f, 0.f, 0.f);
	glutSolidSphere(0.25, 25, 25);
	glTranslatef(0.f, 0.f, -5.f);
	glutSolidSphere(0.25, 25, 25);
	glTranslatef(2.f, 0.f, 0.f);
	glutSolidSphere(0.25, 25, 25);
	glPopAttrib();
	glPopMatrix();

	glPushMatrix();//animated board
	glTranslatef(-33.5f, 5.f, 0.f);
	glRotatef(90.f, 0.f, 0.f, 1.f);
	Box(6.f, 0.1f, 10.f, currentFlag);
	glPopMatrix();

	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Stadium::Update(const double& deltaTime) {
	aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

	float aS = 10.f * aT / animationTime;         // calculate stage (out of x)

	if (aS < 5.f) { //show liverpool flag for the first 5 seconds
		currentFlag = liverpool;
	}
	else { //then change ton the chelsea flag
		currentFlag = chelsea;
	}
}

void Stadium::stadSide(float scalez) {
	//1 - base
	glPushMatrix();
	glScalef(10.f, 10.f, 10.f);
	Box(1.f, 0.1f, scalez, stadWall);
	//2 - wall
	glPushMatrix();
	glTranslatef(-0.5f, 0.5f, 0.f);
	glRotatef(-90.f, 0.f, 0.f, 1.f);
	Box(1.f, 0.1f, scalez, stadWall);
	glRotatef(90.f, 0.f, 0.f, 1.f);
	glTranslatef(0.5f, 0.6f, 0.f);
	//3 - roof
	glPushMatrix();
	glRotatef(15.f, 0.f, 0.f, 1.f);
	Box(1.2f, 0.07f, scalez, stadRoof);
	//~3
	glPopMatrix();
	//4 - seating
	glPushMatrix();
	glTranslatef(0.f, -0.6f, 0.f);
	glRotatef(-45.f, 0.f, 0.f, 1.f);
	Box(1.35f, 0.05f, scalez, crowd);
	//~4
	glPopMatrix();
	//~2
	glPopMatrix();
	//~1
	glPopMatrix();
}

void Stadium::stadCorner() {
	stadSide(0.8f);
	glScalef(3.f, 3.f, 3.f);
	glDisable(GL_CULL_FACE);

	//first side
	//1 - base
	glPushMatrix();
	glTranslatef(-1.3f, -0.2f, 2.3f);
	glRotatef(114.f, 0.f, 1.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, stadWall);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(-0.3f, 0.4f, 3.f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//2 - wall
	glPushMatrix();
	glTranslatef(-0.3f, 1.8f, 0.f);
	glRotatef(-90.f, 0.f, 0.f, 1.f);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	Box(3.2f, 0.2f, 2.7f, stadWall);
	glRotatef(90.f, 0.f, 0.f, 1.f);
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	//3 - roof
	glPushMatrix();
	glTranslatef(0.2f, 0.3f, 1.3f);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glRotatef(-18.f, 1.f, 0.f, 0.f);
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, stadRoof);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(-0.3f, 0.4f, 3.f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glPushMatrix();
	glTranslatef(0.f, -0.25f, 0.f);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(-0.3f, 0.4f, 3.f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//4 - seating
	glPushMatrix();
	glRotatef(63.f, 1.f, 0.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, crowd);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(-0.3f, 0.1f, 4.0f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//pop all
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//second side
	//1 - base
	glPushMatrix();
	glTranslatef(1.f, 0.f, -3.5f);
	glRotatef(-36.f, 0.f, 1.f, 0.f);
	glPushMatrix();
	glTranslatef(-1.3f, -0.2f, 2.f);
	glRotatef(106.f, 0.f, 1.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, stadWall);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(-0.3f, 0.4f, 3.f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//2 - wall
	glPushMatrix();
	glTranslatef(-0.15f, 1.8f, -0.05f);
	glRotatef(-3.f, 0.f, 1.f, 0.f);
	glRotatef(-90.f, 0.f, 0.f, 1.f);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	Box(3.2f, 0.2f, 2.6f, stadWall);
	glRotatef(90.f, 0.f, 0.f, 1.f);
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	//3 - roof
	glPushMatrix();
	glTranslatef(0.2f, 0.f, 1.3f);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glRotatef(-18.f, 1.f, 0.f, 0.f);
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, stadRoof);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.3f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(0.f, 0.4f, 3.f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glPushMatrix();
	glTranslatef(0.f, -0.25f, 0.f);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.3f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(0.f, 0.4f, 3.f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//4 - seating
	glPushMatrix();
	glRotatef(63.f, 1.f, 0.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, crowd);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 0);
	glVertex3f(-1.3f, 0.4f, 0.f);
	glTexCoord2f(1, 0.5);
	glVertex3f(0.f, 0.1f, 4.0f);
	glTexCoord2f(0, 1);
	glVertex3f(1.2f, 0.4f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//pop all
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glEnable(GL_CULL_FACE);
}

void Stadium::Box(float sx, float sy, float sz, GLuint texture) {
	glPushMatrix();
	glScalef(sx, sy, sz);
	glDisable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	float r = 0.5;
	// Near face
	glTexCoord2f(0, 0);
	glVertex3f(-r, -r, r);
	glTexCoord2f(0, 1);
	glVertex3f(-r, r, r);
	glTexCoord2f(1, 1);
	glVertex3f(r, r, r);
	glTexCoord2f(1, 0);
	glVertex3f(r, -r, r);
	// Right face
	glTexCoord2f(0, 0);
	glVertex3f(r, -r, r);
	glTexCoord2f(0, 1);
	glVertex3f(r, r, r);
	glTexCoord2f(1, 1);
	glVertex3f(r, r, -r);
	glTexCoord2f(1, 0);
	glVertex3f(r, -r, -r);
	// Back face
	glTexCoord2f(0, 0);
	glVertex3f(-r, -r, -r);
	glTexCoord2f(0, 1);
	glVertex3f(-r, r, -r);
	glTexCoord2f(1, 1);
	glVertex3f(r, r, -r);
	glTexCoord2f(1, 0);
	glVertex3f(r, -r, -r);
	// Left face
	glTexCoord2f(0, 0);
	glVertex3f(-r, -r, r);
	glTexCoord2f(0, 1);
	glVertex3f(-r, r, r);
	glTexCoord2f(1, 1);
	glVertex3f(-r, r, -r);
	glTexCoord2f(1, 0);
	glVertex3f(-r, -r, -r);
	// Top face
	glTexCoord2f(0, 0);
	glVertex3f(-r, -r, r);
	glTexCoord2f(0, 1);
	glVertex3f(-r, -r, -r);
	glTexCoord2f(1, 1);
	glVertex3f(r, -r, -r);
	glTexCoord2f(1, 0);
	glVertex3f(r, -r, r);
	// Bottom face
	glTexCoord2f(0, 0);
	glVertex3f(-r, r, r);
	glTexCoord2f(0, 1);
	glVertex3f(-r, r, -r);
	glTexCoord2f(1, 1);
	glVertex3f(r, r, -r);
	glTexCoord2f(1, 0);
	glVertex3f(r, r, r);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}