#define _USE_MATH_DEFINES

#include "GoalPost.h"
#include <cmath>


GoalPost::GoalPost() {

}

void GoalPost::Display() {
    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glTranslatef(50.f, 0.f, 0.f); //move to right of skybox
    glPushMatrix();
    glScalef(0.2f, 0.2f, 0.2f);

    //far side
    glPushMatrix(); //1 - left post
    glTranslatef(-18.f, 0.f, -89.f);
    cylinder(12.f, 0.5f);
    glPushMatrix(); //2 - crossbar
    glTranslatef(0.f, 12.f, 0.f);
    glRotatef(-90.f, 0.f, 0.f, 1.f);
    cylinder(36.f, 0.5f);
    glPopMatrix();//~2
    glPushMatrix();//3 - right post
    glTranslatef(36.f, 0.f, 0.f);
    cylinder(12.f, 0.5f);
    glPopMatrix();//~3
    glPopMatrix();//~1
    
    //near side
    glPushMatrix(); //1 - left post
    glTranslatef(-18.f, 0.f, 89.f);
    cylinder(12.f, 0.5f);
    glPushMatrix(); //2 - crossbar
    glTranslatef(0.f, 12.f, 0.f);
    glRotatef(-90.f, 0.f, 0.f, 1.f);
    cylinder(36.f, 0.5f);
    glPopMatrix();//~2
    glPushMatrix();//3 - right post
    glTranslatef(36.f, 0.f, 0.f);
    cylinder(12.f, 0.5f);
    glPopMatrix();//~3
    glPopMatrix();//~1    
    
    glPopMatrix();//~all
    glPopMatrix();
    glEnable(GL_CULL_FACE);
}

void GoalPost::cylinder(float h, float r)
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
