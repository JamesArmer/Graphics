#define _USE_MATH_DEFINES

#include "CarPark.h"

CarPark::CarPark(bool nightMode) {
    if (nightMode) {
        isNight = true;
    }
    qobj = gluNewQuadric();
}

void CarPark::Display() {
    glDisable(GL_CULL_FACE);
    if (isNight) {//disbale red lighting for the car park models
        glDisable(GL_LIGHT1);
    }

    glPushMatrix();//lamp posts
    glTranslatef(-20.f, 0.f, 70.f);
    for (int i = 0; i < 7;i++) {
        glTranslatef(0.f, 0.f, -20.f);
        lampPost();
    }
    glPopMatrix();

    glPushMatrix();//left cars
    glTranslatef(-30.f, 0.f, 40.f);
    car(true); 
    glTranslatef(0.f, 0.f, -40.f);
    car(false);
    glTranslatef(0.f, 0.f, -30.f);
    car(true);
    glTranslatef(0.f, 0.f, -30.f);
    car(false);
    glPopMatrix();

    glPushMatrix();//right cars
    glTranslatef(-10.f, 0.f, 20.f);
    glRotatef(180.f, 0.f, 1.f, 0.f);
    car(false);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.f, 0.f, -20.f);
    glRotatef(180.f, 0.f, 1.f, 0.f);
    car(true);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.f, 0.f, -40.f);
    glRotatef(180.f, 0.f, 1.f, 0.f);
    car(false);
    glPopMatrix();

    glPushMatrix();//road
    glPushMatrix();
    glTranslatef(77.f, 0.f, 70.f);
    Box(83.3f, 0.01f, 12.f, road);
    glTranslatef(-83.3f, 0.f, 0.f);
    Box(83.3f, 0.01f, 12.f, road);
    glTranslatef(-83.3f, 0.f, 0.f);
    Box(83.3f, 0.01f, 12.f, road);
    glPopMatrix();
    glTranslatef(-50.f, 0.f, 22.5f);
    glRotatef(90.f, 0.f, 1.f, 0.f);
    Box(83.3f, 0.01, 12.f, road);
    glTranslatef(83.3f, 0.f, 0.f);
    Box(83.3f, 0.01, 12.f, road);
    glPopMatrix();

    glPushMatrix(); //animated car
    glTranslatef(carX, 0.f, 67.f);
    car(false);
    glPopMatrix();

    if (isNight) {
        glEnable(GL_LIGHT1);
    }
}

void CarPark::HandleKey(unsigned char key, int state, int x, int y) {
    if ((state == 1) && (key == '1')) {//used to disbale red lighting
        isNight = true;
    }
    if ((state == 1) && (key == '2')) {
        isNight = false;
    }
}

void CarPark::Update(const double& deltaTime) {
    aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

    float aS = 16.f * aT / animationTime;         // calculate stage (out of x)

    if (aS < 15.f) {
        carX = carX + 0.1f; //slowly move the car along the road
    }
    else {
        carX = -110.f; //reset the position
    }
}

void CarPark::car(bool isBlue) {
    glDisable(GL_CULL_FACE);
    glPushMatrix();// back wheels
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.f, 0.f, 0.f); //black
    glTranslatef(-1.7f, 0.7f, 1.1f);
    gluCylinder(qobj, 0.5f, 0.5f, 0.5f, 20, 20);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, -0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glColor3f(0.f, 0.f, 0.f); //black
    glTranslatef(0.f, 0.f, 0.5f);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, 0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glTranslatef(0.f, 0.f, -3.2f);
    glColor3f(0.f, 0.f, 0.f); //black
    gluCylinder(qobj, 0.5f, 0.5f, 0.5f, 20, 20);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, -0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glColor3f(0.f, 0.f, 0.f); //black
    glTranslatef(0.f, 0.f, 0.5f);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, 0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glPopMatrix();//~back
    glPushMatrix();// front wheels
    glColor3f(0.f, 0.f, 0.f); //black
    glTranslatef(1.3f, 0.7f, 1.1f);
    gluCylinder(qobj, 0.5f, 0.5f, 0.5f, 20, 20);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, -0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glColor3f(0.f, 0.f, 0.f); //black
    glTranslatef(0.f, 0.f, 0.5f);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, 0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glTranslatef(0.f, 0.f, -3.2f);
    glColor3f(0.f, 0.f, 0.f); //black
    gluCylinder(qobj, 0.5f, 0.5f, 0.5f, 20, 20);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, -0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glColor3f(0.f, 0.f, 0.f); //black
    glTranslatef(0.f, 0.f, 0.5f);
    gluDisk(qobj, 0, 0.5f, 20, 1);
    glColor3f(0.75f, 0.75f, 0.75f); //grey
    glTranslatef(0.f, 0.f, 0.01f);
    gluDisk(qobj, 0, 0.3f, 20, 1);
    glPopMatrix();//~front
    glPopAttrib();
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);
    if (isBlue) {
        glColor3f(0.f, 0.f, 1.f);
    }
    else {
        glColor3f(1.f, 0.f, 0.f);
    }
    glTranslatef(0.f, 1.f, 0.f);
    glPushMatrix();
    glScalef(7.f, 1.f, 3.f);
    glutSolidCube(1.f);//body
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.f, 1.5f, -1.3f);
    glBegin(GL_QUADS); //roof
    glVertex3f(0.f, 1.3f, 0.f);
    glVertex3f(3.5f, 1.3f, 0.f); 
    glVertex3f(3.5f, 1.3f, 2.5f); 
    glVertex3f(0.f, 1.3f, 2.5f);
    glEnd();
    glBegin(GL_QUADS); //front
    glVertex3f(0.f, 1.3f, 2.5f);
    glVertex3f(-1.f, 0.f, 2.5f);
    glVertex3f(-1.f, 0.f, 0.f);
    glVertex3f(0.f, 1.3f, 0.f);
    glEnd();
    glBegin(GL_QUADS); //rear
    glVertex3f(3.5f, 1.3f, 2.5f);
    glVertex3f(4.5f, 0.f, 2.5f);
    glVertex3f(4.5f, 0.f, 0.f);
    glVertex3f(3.5f, 1.3f, 0.f);
    glEnd();
    glBegin(GL_QUADS); //near side
    glVertex3f(3.5f, 1.3f, 2.5f);
    glVertex3f(0.f, 1.3f, 2.5f);
    glVertex3f(-1.f, 0.f, 2.5f);
    glVertex3f(4.5f, 0.f, 2.5f);
    glEnd();
    glBegin(GL_QUADS); //far side
    glVertex3f(3.5f, 1.3f, 0.f);
    glVertex3f(0.f, 1.3f, 0.f);
    glVertex3f(-1.f, 0.f, 0.f);
    glVertex3f(4.5f, 0.f, 0.f);
    glEnd();
    glPopAttrib();
    glPushAttrib(GL_CURRENT_BIT);
    glColor3f(0.74902f, 0.847059f, 0.847059f); //light blue
    glPushMatrix();//windscreen
    glTranslatef(4.f, 0.6f, 1.25f);
    glRotatef(-52.f, 0.f, 0.f, 1.f);
    glScalef(1.f, 0.1f, 2.2f);
    glutSolidCube(1.f);
    glPopMatrix();//~windscreen
    glPushMatrix();//rear screen
    glTranslatef(-0.5f, 0.6f, 1.25f);
    glRotatef(52.f, 0.f, 0.f, 1.f);
    glScalef(1.f, 0.1f, 1.8f);
    glutSolidCube(1.f);
    glPopMatrix();//~rear screen
    glPushMatrix();//side windows
    glTranslatef(2.f, 0.1f, -0.01f);
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.f, 0.f);
    glVertex3f(0.f, 1.f, 0.f);
    glVertex3f(1.f, 1.f, 0.f);
    glVertex3f(1.7f, 0.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(0.f, 0.f, 2.52f);
    glVertex3f(0.f, 1.f, 2.52f);
    glVertex3f(1.f, 1.f, 2.52f);
    glVertex3f(1.7f, 0.f, 2.52f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.f, 0.f);
    glVertex3f(-0.3f, 1.f, 0.f);
    glVertex3f(-1.3f, 1.f, 0.f);
    glVertex3f(-2.f, 0.f, 0.f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-0.3f, 0.f, 2.52f);
    glVertex3f(-0.3f, 1.f, 2.52f);
    glVertex3f(-1.3f, 1.f, 2.52f);
    glVertex3f(-2.f, 0.f, 2.52f);
    glEnd();
    glPopMatrix();//~side windows
    glPopAttrib();
    glPopMatrix();//~all
    glEnable(GL_CULL_FACE);
}

void CarPark::lampPost() {
    glPushMatrix();
    glColor3f(0.75f, 0.75f, 0.75f);//grey
    glScalef(0.25f, 0.25f, 0.25f);
    glPushMatrix(); //1 - base
    cylinder(30.f, 0.5f);
    glPushMatrix(); //2 - top branch
    glTranslatef(7.5f, 30.f, 0.f);
    glRotatef(90.f, 0.f, 0.f, 1.f);
    cylinder(15.f, 0.5f);
    glPushMatrix(); //3 - left lamp
    glPushMatrix();
    glScalef(1.5f, 4.f, 1.5f);
    glutSolidCube(1.f);
    glPopMatrix();
    glPushMatrix(); //3a - bulb
    glColor3f(1.f, 1.f, 1.f);//white
    glTranslatef(-0.5f, 0.f, 0.f);
    glScalef(1.f, 1.2f, 0.6f);
    glutSolidSphere(1.f, 50.f, 50.f);
    glPopMatrix();//~3a
    glPushMatrix(); //4 - right lamp
    glColor3f(0.75f, 0.75f, 0.75f);//grey
    glTranslatef(0.f, 15.f, 0.f);
    glPushMatrix();
    glScalef(1.5f, 4.f, 1.5f);
    glutSolidCube(1.f);
    glPopMatrix();
    glPushMatrix(); //4a - bulb
    glColor3f(1.f, 1.f, 1.f);//white
    glTranslatef(-0.5f, 0.f, 0.f);
    glScalef(1.f, 1.2f, 0.6f);
    glutSolidSphere(1.f, 50.f, 50.f);
    glPopMatrix();//~4a
    glPopMatrix();//~4
    glPopMatrix();//~3
    glPopMatrix();//~2
    glPopMatrix();//~1
    glPopMatrix();//~all
}

void CarPark::cylinder(float h, float r) {
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
    while (t <= 2 * M_PI){
        glVertex3f(x, h, z);    // top
        t += res;               // add increment to angle
        x = r * cos(t);           // move x and z around circle
        z = r * sin(t);                    
    }        // for a full circle (360 degrees)
    glEnd();
}

void CarPark::Box(float sx, float sy, float sz, GLuint texture) {
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
