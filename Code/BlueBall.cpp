#include "BlueBall.h"

BlueBall::BlueBall() {
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);
}

void BlueBall::Display() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, football);
	glPushMatrix();//Blue team ball
	glTranslatef(ballX1, 0.2f, 2.9f);
	glScalef(0.1f, 0.1f, 0.1f);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	glRotatef(ballRotation1, 0.f, 1.f, 0.f);
	gluSphere(qobj, 1.5f, 25, 25);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

void BlueBall::Update(const double& deltaTime) {
	aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

	float aS = 4.f * aT / animationTime;         // calculate stage (out of x)
	
	if (aS < 0.1f) { //reset the ball
		ballX1 = 49.5f;
	}
	else if ((aS > 1.f) && (aS < 2.f)) {
		ballRotation1 = 720 * (aS - 1.f);
		ballX1 += -0.045;
	}
	else if ((aS > 3.f) && (aS < 4.f)) {
		ballRotation1 = -720 * (aS - 3.f);//change to negative for rolling in the opposite direction
		ballX1 += 0.045f;
	}
}