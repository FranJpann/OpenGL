// gcc main.c opmat.c opmat.h actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include "opmat.h"

GLfloat xrot = 30;   
GLfloat yrot = 30;   
GLfloat z = -5.0f; 

GLfloat rotDoigt = 0;
GLfloat rotPouce = 0;
GLfloat rotPouce2 = 0;

GLvoid Modelisation()
{
  VM_init();
  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  
  paume();

  //Les doigts 

  glPushMatrix();
    {
      glTranslatef(1, 0, -0.75 + 0.15);
      doigt(1, 0, 0, rotDoigt, 0.6);
    }
    {
      glTranslatef(0, 0, 0.4);
      doigt(0, 1, 0, rotDoigt, 0.7);
    }
    {
      glTranslatef(0, 0, 0.4);
      doigt(1, 1, 0, rotDoigt, 0.5);
    }
    {
      glTranslatef(0, 0, 0.4);
      doigt(0, 0, 1, rotDoigt, 0.4);
    }glPopMatrix();

    //Le pouce
  glColor3d(0,1,1);
  glPushMatrix();
  {
    glTranslatef(-0.5, 0.15, -0.75 - 0.1);

      glRotatef(rotPouce, 0, 0, 1);

    glTranslatef(0.25, 0, 0);
    glPushMatrix();
    {
      glScalef(1, 0.3, 0.3);
      glutSolidCube(1);
    }glPopMatrix();
    glTranslatef(0.5, 0, 0);

      glRotatef(rotPouce2, 0, -1, 0);

    glTranslatef(0.25, 0, 0);
    glPushMatrix();
    {
      glScalef(0.5, 0.2, 0.2);
      glutSolidCube(1);
    }glPopMatrix();
    glTranslatef(0.25, 0, 0);

      glRotatef(rotPouce2, 0, -1, 0);

    glTranslatef(0.25, 0, 0);
    glPushMatrix();
    {
      glScalef(0.5, 0.2, 0.2);
      glutSolidCube(1);
    }glPopMatrix();
  }
  glPopMatrix();

  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
