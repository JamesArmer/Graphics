#define _USE_MATH_DEFINES

#include "RedPlayers.h"

RedPlayers::RedPlayers() {

}

void RedPlayers::Display() {
    glDisable(GL_CULL_FACE);
    //Red side
    glPushMatrix();//Player1
    glTranslatef(50.f, 0.f, -3.f);
    glPushMatrix();
    glTranslatef(-5.f, 0.f, personZ);
    glRotatef(135.f, 0.f, 1.f, 0.f);
    animatedPlayer(joint1, legX1, false);
    glPopMatrix();
    glPushMatrix();//Player2
    glTranslatef(-3.f, 0.f, -9.f);
    person(false);
    glPopMatrix();//~2
    glPushMatrix();//Player3
    glTranslatef(-2.f, 0.f, -9.f);
    person(false);
    glPopMatrix();//~3
    glPushMatrix();//Player4
    glTranslatef(gkX, gkY, -14.f);//whole player translations
    glRotatef(rotateGK, 0.f, 0.f, 1.f);
    animatedGoalkeeper(armJoint, armY);
    glPopMatrix();//~4
    glPopMatrix();//~1

    glEnable(GL_CULL_FACE);
}

void RedPlayers::HandleKey(unsigned char key, int state, int x, int y) {
    if ((state == 1) && (key == '3')) {
        animationEnabled = true;//play the animation
        aT = 0; //reset the animation timer
    }
    if ((state == 1) && (key == '4')) {
        animationEnabled = false;//pause the animation
    }
}

void RedPlayers::Update(const double& deltaTime) {
    if (animationEnabled) { //only play once the 3 key is presses
        aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

        float aS = 4.f * aT / animationTime;         // calculate stage (out of x)

        if (aS < 0.1f) {//reset people
            legX1 = 0.5f;
            legX2 = 1.5f;
            personZ = -2.f;
            armY = -3.f;
            gkX = 1.5f;
            gkY = 0.f;
            rotateGK = 0;
        }
        else if (aS < 0.5f) {
            joint1 = 90 * aS;//leg going back
            legX1 += -0.04f;
            personZ += -0.01f;//free kick player moving forward
        }
        else if (aS < 1.f) {//leg going forward
            joint1 = -45 * (aS - 0.5);
            legX1 += 0.04f;
        }
        else if ((aS > 3.f) && (aS < 3.5f)) {
            armJoint = -360 * (aS - 3); //goalkeeper
            armY += -0.06;
            rotateGK = 180 * (aS - 3);
            gkX += -0.02;
            gkY += 0.006f;
        }
    }
}

void RedPlayers::animatedGoalkeeper(float joint, float armY) {
    glPushMatrix();
    glScalef(0.08f, 0.08f, 0.08f);
    glTranslatef(0.f, 18.f, 0.f);
    glPushMatrix();//1 - head
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glScalef(1.f, 1.1f, 1.f);
    glutSolidSphere(2.f, 50.f, 50.f);
    glPopMatrix();//~1
    glPushMatrix();//2 - body
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.f, 0.f);//red
    glTranslatef(0.f, -6.f, 0.f);
    Box(6.f, 8.f, 2.f);
    glPopAttrib();
    glPushMatrix();//3 - left arm
    glRotatef(joint, 1.f, 0.f, 0.f);//arm rotation
    glTranslatef(-4.f, armY, 0.f);
    cylinder(8.f, 0.7f);
    glPopMatrix();//~3
    glPushMatrix();//4 - right arm
    glRotatef(joint, 1.f, 0.f, 0.f);//arm rotation
    glTranslatef(4.f, armY, 0.f);
    cylinder(8.f, 0.7f);
    glPopMatrix();//~4
    glPopAttrib();
    glPushMatrix();//5 - left leg
    glTranslatef(-1.5f, -7.f, 0.f);
    cylinder(3.5f, 1.f);//thigh
    glTranslatef(0.f, -0.3f, 0.f);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glutSolidSphere(0.7f, 50.f, 50.f);//knee
    glTranslatef(0.f, -3.5f, 0.f);
    cylinder(3.f, 0.8f);//shin
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f);//black
    glTranslatef(0.f, -0.7f, 0.5f);
    Box(1.5f, 1.f, 3.f);//foot
    glPopAttrib();
    glPopMatrix();//~5
    glPushMatrix();//6 - right leg
    glPopAttrib();
    glTranslatef(1.5f, -7.f, 0.f);
    cylinder(3.5f, 1.f);//thigh
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glTranslatef(0.f, -0.3f, 0.f);
    glutSolidSphere(0.7f, 50.f, 50.f);//knee
    glTranslatef(0.f, -3.5f, 0.f);
    cylinder(3.f, 0.8f);//shin
    glTranslatef(0.f, -0.7f, 0.5f);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f);//black
    Box(1.5f, 1.f, 3.f);//foot
    glPopAttrib();
    glPopAttrib();
    glPopMatrix();//~6
    glPopMatrix();//~2
    glPopMatrix();//~all
}

void RedPlayers::animatedPlayer(float joint, float legX, bool isBlue) {
    glPushMatrix();
    glScalef(0.08f, 0.08f, 0.08f);
    glTranslatef(0.f, 18.f, 0.f);
    glPushMatrix();//1 - head
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glScalef(1.f, 1.1f, 1.f);
    glutSolidSphere(2.f, 50.f, 50.f);
    glPopMatrix();//~1
    glPushMatrix();//2 - body
    glPushAttrib(GL_CURRENT_BIT);
    if (isBlue) {
        glColor3f(0.f, 0.f, 1.f);//blue
    }
    else {
        glColor3f(1.f, 0.f, 0.f);//red
    }
    glTranslatef(0.f, -6.f, 0.f);
    Box(6.f, 8.f, 2.f);
    glPopAttrib();
    glPushMatrix();//3 - left arm
    glTranslatef(-4.f, -5.f, 0.f);
    cylinder(8.f, 0.7f);
    glPopMatrix();//~3
    glPushMatrix();//4 - right arm
    glTranslatef(4.f, -5.f, 0.f);
    cylinder(8.f, 0.7f);
    glPopMatrix();//~4
    glPopAttrib();
    glPushMatrix();//5 - left leg
    glTranslatef(-1.5f, -7.f, legX);
    glRotatef(joint, 1.f, 0.f, 0.f);//thigh rotation
    cylinder(3.5f, 1.f);//thigh
    glTranslatef(0.f, -0.3f, 0.f);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glutSolidSphere(0.7f, 50.f, 50.f);//knee
    glTranslatef(0.f, -3.5f, 0.f);
    cylinder(3.f, 0.8f);//shin
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f);//black
    glTranslatef(0.f, -0.7f, 0.5f);
    Box(1.5f, 1.f, 3.f);//foot
    glPopAttrib();
    glPopMatrix();//~5
    glPushMatrix();//6 - right leg
    glPopAttrib();
    glTranslatef(1.5f, -7.f, 0.f);
    cylinder(3.5f, 1.f);//thigh
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glTranslatef(0.f, -0.3f, 0.f);
    glutSolidSphere(0.7f, 50.f, 50.f);//knee
    glTranslatef(0.f, -3.5f, 0.f);
    cylinder(3.f, 0.8f);//shin
    glTranslatef(0.f, -0.7f, 0.5f);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f);//black
    Box(1.5f, 1.f, 3.f);//foot
    glPopAttrib();
    glPopAttrib();
    glPopMatrix();//~6
    glPopMatrix();//~2
    glPopMatrix();//~all
}

void RedPlayers::person(bool isBlue) {
    glPushMatrix();
    glScalef(0.08f, 0.08f, 0.08f);
    glTranslatef(0.f, 18.f, 0.f);
    glPushMatrix();//1 - head
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glScalef(1.f, 1.1f, 1.f);
    glutSolidSphere(2.f, 50.f, 50.f);
    glPopMatrix();//~1
    glPushMatrix();//2 - body
    glPushAttrib(GL_CURRENT_BIT);
    if (isBlue) {
        glColor3f(0.f, 0.f, 1.f);//blue
    }
    else {
        glColor3f(1.f, 0.f, 0.f);//red
    }
    glTranslatef(0.f, -6.f, 0.f);
    Box(6.f, 8.f, 2.f);
    glPopAttrib();
    glPushMatrix();//3 - left arm
    glTranslatef(-4.f, -5.f, 0.f);
    cylinder(8.f, 0.7f);
    glPopMatrix();//~3
    glPushMatrix();//4 - right arm
    glTranslatef(4.f, -5.f, 0.f);
    cylinder(8.f, 0.7f);
    glPopMatrix();//~4
    glPopAttrib();
    glPushMatrix();//5 - left leg
    glTranslatef(-1.5f, -7.f, 0.f);
    cylinder(3.5f, 1.f);//thigh
    glTranslatef(0.f, -0.3f, 0.f);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glutSolidSphere(0.7f, 50.f, 50.f);//knee
    glTranslatef(0.f, -3.5f, 0.f);
    cylinder(3.f, 0.8f);//shin
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f);//black
    glTranslatef(0.f, -0.7f, 0.5f);
    Box(1.5f, 1.f, 3.f);//foot
    glPopAttrib();
    glPopMatrix();//~5
    glPushMatrix();//6 - right leg
    glPopAttrib();
    glTranslatef(1.5f, -7.f, 0.f);
    cylinder(3.5f, 1.f);//thigh
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(1.f, 0.9f, 0.9f);//skin colour
    glTranslatef(0.f, -0.3f, 0.f);
    glutSolidSphere(0.7f, 50.f, 50.f);//knee
    glTranslatef(0.f, -3.5f, 0.f);
    cylinder(3.f, 0.8f);//shin
    glTranslatef(0.f, -0.7f, 0.5f);
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f);//black
    Box(1.5f, 1.f, 3.f);//foot
    glPopAttrib();
    glPopAttrib();
    glPopMatrix();//~6
    glPopMatrix();//~2
    glPopMatrix();//~all
}

void RedPlayers::cylinder(float h, float r) {
    float res = 0.1 * M_PI;           // resolution (in radians: equivalent to 18 degrees)
    float x = r, z = 0.f;           // initialise x and z on right of cylinder centre
    float t = 0.f;                  // initialise angle as 0

    do
    {
        glBegin(GL_QUADS);          // new QUAD
            // Create first points
        glVertex3f(x, h, z);    // top
        glVertex3f(x, 0.f, z);  // bottom
        // Iterate around circle
        t += res;               // add increment to angle
        x = r * cos(t);           // move x and z around circle
        z = r * sin(t);
        // Close quad
        glVertex3f(x, 0.f, z);  // bottom
        glVertex3f(x, h, z);    // top
        glEnd();                    // end shape
    } while (t <= 2 * M_PI);        // for a full circle (360 degrees)

    glBegin(GL_POLYGON);
    while (t <= 2 * M_PI) {
        glVertex3f(x, h, z);    // top
        t += res;               // add increment to angle
        x = r * cos(t);           // move x and z around circle
        z = r * sin(t);
    }        // for a full circle (360 degrees)
    glEnd();
}

void RedPlayers::Box(float sx, float sy, float sz) {
    glPushMatrix();
    glScalef(sx, sy, sz);
    glutSolidCube(1.f);
    glPopMatrix();
}
