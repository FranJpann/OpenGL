#include "init.h"
#include "actions.h"
#include "VM_init.c"
#include "playmobil.h"
#include "axes.h"
#include "ppm.h"

extern GLfloat xcam;
extern GLfloat ycam;
extern GLfloat zcam;
extern GLfloat xrot;
extern GLfloat yrot;

GLvoid Modelisation()
{
  VM_init();

  TEXTURE_STRUCT * texture = readPpm("Files/Damier.ppm");

  GLuint textures;
  glGenTextures(1, &textures);
  glBindTexture(GL_TEXTURE_2D, textures);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width, texture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glEnable(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, textures);

  glBegin(GL_QUADS);
    GLfloat taille = 20;
    glColor3f(1, 1, 1);
    glVertex3f(taille, -2, taille);
    glVertex3f(-taille, -2, taille);
    glVertex3f(-taille, -2, -taille);
    glVertex3f(taille, -2, -taille);
  glEnd();

  axes();

  //creerPlaymobil();

  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}