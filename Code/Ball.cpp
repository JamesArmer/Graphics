#include "Ball.h"

Ball::Ball() {
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);
}

void Ball::Display() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, football);
	glPushMatrix();//Ball 1
	glTranslatef(ballX1, 0.2f, 2.9f);
	glScalef(0.1f, 0.1f, 0.1f);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	glRotatef(ballRotation1, 0.f, 1.f, 0.f);
	gluSphere(qobj, 1.5f, 25, 25);
	glPopMatrix();

	glPushMatrix();//Ball 2
	glTranslatef(ballX2, ballY2, ballZ2);
	glScalef(0.1f, 0.1f, 0.1f);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	glRotatef(ballRotation2, 1.f, 1.f, 0.f);
	gluSphere(qobj, 1.5f, 25, 25);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Ball::Update(const double& deltaTime) {
	aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

	float aS = 4.f * aT / animationTime;         // calculate stage (out of x)
	
	if (aS < 0.1f) { //reset the balls
		ballX1 = 49.5f;
		ballX2 = 45.5f;
		ballY2 = 0.2f;
		ballZ2 = -6.f;
	}
	else if ((aS > 1.f) && (aS < 2.f)) {
		ballRotation1 = 720 * (aS - 1.f);
		ballRotation2 = 720 * (aS - 1.f);
		ballX1 += -0.04;
		ballX2 += 0.01f;
		ballY2 += 0.012;
		ballZ2 += -0.04;
	}
	else if ((aS > 2.f) && (aS < 3.f)) {
		ballRotation2 = 720 * (aS - 1.f);
		ballX2 += -0.0005f;
		ballY2 += -0.0025f;
		ballZ2 += -0.035f;
	}
	else if ((aS > 3.f) && (aS < 4.f)) {
		ballRotation1 = -720 * (aS - 3.f);
		ballRotation2 = 720 * (aS - 1.f);
		ballX1 += 0.04f;
		ballY2 += -0.005;
		ballZ2 += -0.035f;
	}
}