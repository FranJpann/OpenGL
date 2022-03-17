#include "init.h"
#include "actions.h"
#include "VM_init.c"
#include "ppm.h"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

GLvoid Modelisation()
{
  VM_init();

  writePpm("Damier.ppm", "Damier.ppm");

  TEXTURE_STRUCT * text = readPpm("Damier.ppm");

  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, text->width, text->height, 0, GL_RGB, GL_UNSIGNED_BYTE, text->data);

  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);	
  glBindTexture(GL_TEXTURE_2D, texture);

  glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(-2, -2, 0);

    glTexCoord2f(1, 0);
    glVertex3f(2, -2, 0);

    glTexCoord2f(1, 1);
    glVertex3f(2, 2, 0);

    glTexCoord2f(0, 1);
    glVertex3f(-2, 2, 0);
  glEnd();
  
  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}