#include "RedBall.h"

RedBall::RedBall() {
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);
}

void RedBall::Display() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, football);
	glPushMatrix();//Red team ball
	glTranslatef(ballX2, ballY2, ballZ2);
	glScalef(0.1f, 0.1f, 0.1f);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glRotatef(90.f, 1.f, 0.f, 0.f);
	glRotatef(ballRotation2, 1.f, 1.f, 0.f);
	gluSphere(qobj, 1.5f, 25, 25);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void RedBall::HandleKey(unsigned char key, int state, int x, int y) {
	if ((state == 1) && (key == '3')) {//play the animation
		animationEnabled = true;
		aT = 0;//reset the animation timer
	}
	if ((state == 1) && (key == '4')) {//pause the animation
		animationEnabled = false;
	}
}

void RedBall::Update(const double& deltaTime) {
	if (animationEnabled) {
		aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

		float aS = 4.f * aT / animationTime;         // calculate stage (out of x)

		if (aS < 0.1f) { //reset the ball
			ballX2 = 45.5f;
			ballY2 = 0.2f;
			ballZ2 = -6.f;
		}
		else if ((aS > 1.f) && (aS < 2.f)) {//moving up above the wall
			ballRotation2 = 720 * (aS - 1.f);
			ballX2 += 0.01f;
			ballY2 += 0.012;
			ballZ2 += -0.04;
		}
		else if ((aS > 2.f) && (aS < 3.f)) {//dipping over the wall
			ballRotation2 = 720 * (aS - 1.f);
			ballX2 += -0.0005f;
			ballY2 += -0.0025f;
			ballZ2 += -0.035f;
		}
		else if ((aS > 3.f) && (aS < 4.f)) {//moving into the goal
			ballRotation2 = 720 * (aS - 1.f);
			ballY2 += -0.005;
			ballZ2 += -0.035f;
		}
	}
}