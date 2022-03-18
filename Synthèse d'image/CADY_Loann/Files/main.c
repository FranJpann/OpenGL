#include "init.h"
#include "actions.h"
#include "VM_init.c"
#include "playmobil.h"
#include "axes.h"
#include "texture.h"
#include "ppm.h"

extern GLfloat xcam;
extern GLfloat ycam;
extern GLfloat zcam;
extern GLfloat xrot;
extern GLfloat yrot;

extern GLuint texture[];

GLvoid Modelisation()
{
  VM_init();
  loadTexture();

  /*    Sol   */

  glBindTexture(GL_TEXTURE_2D, texture[0]);
  glBegin(GL_QUADS);
    GLfloat taille = 30;

    glTexCoord2f(0, 0);
    glVertex3f(taille, -2, taille);

    glTexCoord2f(10, 0);
    glVertex3f(-taille, -2, taille);

    glTexCoord2f(10, 10);
    glVertex3f(-taille, -2, -taille);

    glTexCoord2f(0, 10);
    glVertex3f(taille, -2, -taille);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, 0);

  /*    Playmobil   */

  creerPlaymobil();

  axes();
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}