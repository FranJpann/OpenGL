// gcc main.c init.c init.h actions.c actions.h axes.o -lm -lGL -lGLU -lglut -o exec.exe

#include "init.h"
#include "actions.h"
#include "VM_init.c"
#include "normale.h"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

GLvoid Modelisation()
{
  VM_init();

  glPushMatrix();
    glColor3f(1, 1, 0);
    glutSolidSphere(0.5, 30, 30);

    GLfloat position[4] = {2, 0, 0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, position);

  glPopMatrix();

  //axes();
  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}