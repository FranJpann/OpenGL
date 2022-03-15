#include "playmobile.h"
#include "init.h"

void creerPlaymobile(){
    glColor3d(1,0,0);
    glPushMatrix();
    {
        glutSolidCube(0.5);
        glTranslatef(0, -1, 0);
        glutSolidCube(0.5);
    }
    glPopMatrix();
}