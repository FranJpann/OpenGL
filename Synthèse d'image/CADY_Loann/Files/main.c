#include "init.h"
#include "actions.h"
#include "VM_init.c"
#include "playmobil.h"
#include "texture.h"
#include "ppm.h"

extern GLfloat xcam;
extern GLfloat ycam;
extern GLfloat zcam;
extern GLfloat xrot;
extern GLfloat yrot;

extern GLfloat coordsPM[];

extern GLuint texture[];

GLvoid Modelisation()
{
  VM_init();
  glColor3f(1, 1, 1);
  
  GLfloat position[4] = {2, 0, 0, 1};
  glLightfv(GL_LIGHT0, GL_POSITION, position);

  /*    Sol   */
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture[0]);
  glBegin(GL_QUADS);
    GLfloat taille = 30;

    glTexCoord2f(0, 0);
    glVertex3f(taille, -3, taille);

    glTexCoord2f(10, 0);
    glVertex3f(taille, -3, -taille);

    glTexCoord2f(10, 10);
    glVertex3f(-taille, -3, -taille);

    glTexCoord2f(0, 10);
    glVertex3f(-taille, -3, taille);
  glEnd();
  glBindTexture(GL_TEXTURE_2D, 0);

  /*    Playmobil   */
  creerPlaymobil();
  
  glutSwapBuffers();
}

int main(int argc, char**argv)
{
  return notre_init(argc, argv, &Modelisation);
}