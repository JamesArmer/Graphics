#define _USE_MATH_DEFINES

#include "FloodLights.h"

FloodLights::FloodLights() {

}

void FloodLights::Display() {
    glPushMatrix();
    glTranslatef(50.f, 0.f, 0.f); //move to right of skybox
    glPushMatrix();//top left
    glTranslatef(-23.f, 12.f, -18.f);
    glRotatef(45.f, 0.f, 1.f, 0.f);
    glScalef(0.4f, 0.4f, 0.4f);
    pyramidLight();
    glPopMatrix();

    glPushMatrix();//top right
    glTranslatef(17.f, 12.f, -26.f);
    glRotatef(-45.f, 0.f, 1.f, 0.f);
    glScalef(0.4f, 0.4f, 0.4f);
    pyramidLight();
    glPopMatrix();

    glPushMatrix();//back left
    glTranslatef(-17.f, 12.f, 26.f);
    glRotatef(-225.f, 0.f, 1.f, 0.f);
    glScalef(0.4f, 0.4f, 0.4f);
    pyramidLight();
    glPopMatrix();

    glPushMatrix();//back right
    glTranslatef(23.f, 12.f, 18.f);
    glRotatef(-135.f, 0.f, 1.f, 0.f);
    glScalef(0.4f, 0.4f, 0.4f);
    pyramidLight();
    glPopMatrix();

    glPopMatrix();
}

void FloodLights::pyramidLight() {
    glPushMatrix();//1 - left strut
    glRotatef(25.f, 1.f, 0.f, 0.f);
    glRotatef(-27.f, 0.f, 0.f, 1.f);
    cylinder(25.f, 0.5f);
    glPopMatrix();//~1
    glPushMatrix();//2 - right strut
    glTranslatef(23.f, 0.f, 0.f);
    glRotatef(25.f, 1.f, 0.f, 0.f);
    glRotatef(27.f, 0.f, 0.f, 1.f);
    cylinder(25.f, 0.5f);
    glPopMatrix();//~2
    glPushMatrix();//3 - middle strut
    glTranslatef(5.f, 9.f, 4.f);
    glRotatef(-90.f, 0.f, 0.f, 1.f);
    cylinder(13.f, 0.5f);
    glPopMatrix();//~3
    glPushMatrix();//4 - lights
    glPushAttrib(GL_CURRENT_BIT);
    glColor4f(1.f, 1.f, 1.f, 0.7f);
    glTranslatef(9.f, 11.f, 5.f);
    glutSolidSphere(1.3f, 25, 25);
    glTranslatef(5.f, 0.f, 0.f);
    glutSolidSphere(1.3f, 25, 25);
    glTranslatef(-2.5, 3.5f, 2.f);
    glutSolidSphere(1.3f, 25, 25);
    glPopAttrib();
    glPopMatrix();//~4
}

void FloodLights::cylinder(float h, float r)
{
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
}

