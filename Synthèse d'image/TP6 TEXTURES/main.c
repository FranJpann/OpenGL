// gcc main.c init.c init.h actions.c actions.h axes.o -lm -lGL -lGLU -lglut -o exec.exe

#include "init.h"
#include "actions.h"
#include "VM_init.c"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

GLvoid Modelisation()
{
  VM_init();
  
  glBegin(GL_QUADS);
    glVertex3f(-2, -2, 0);
    glVertex3f(2, -2, 0);
    glVertex3f(2, 2, 0);
    glVertex3f(-2, 2, 0);
  glEnd();

  
  
  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}