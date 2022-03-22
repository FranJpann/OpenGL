#include "init.h"
#include "actions.h"
#include "VM_init.c"

extern GLfloat xcam;
extern GLfloat ycam;
extern GLfloat zcam;
extern GLfloat xrot;
extern GLfloat yrot;

extern GLuint texture[];

GLvoid Modelisation()
{
  VM_init();

  glBegin(GL_QUADS);
    GLfloat taille = 30;
    glVertex3f(taille, -3, taille);
    glVertex3f(-taille, -3, taille);
    glVertex3f(-taille, -3, -taille);
    glVertex3f(taille, -3, -taille);
  glEnd();
  
  axes();
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}