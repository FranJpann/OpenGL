#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>

GLfloat coordsPM[3];

struct material {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess;
};

struct cube {
  GLfloat sommets[8][3];
  int faces[6][4];
  GLfloat couleur[6][3];
};

struct cube creer_cube();
void rendu_cube(struct cube c);
void creerPlaymobil();