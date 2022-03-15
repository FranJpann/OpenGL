// gcc main.c init.c init.h actions.c actions.h -lm -lGL -lGLU -lglut -o exec.exe

#include "init.h"
#include "actions.h"
#include "VM_init.c"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

GLvoid Modelisation()
{
  VM_init();

  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}