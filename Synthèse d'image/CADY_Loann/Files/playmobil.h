#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>

struct material {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess;
};

struct cube {
  GLfloat sommets[8][3];
  int faces[6][4];
  GLfloat faceTexture[4][2];
  struct material matiere;
};

struct cube creer_corps(GLfloat taille);
void rendu_cube_texture(struct cube c, GLuint text);
void creerPlaymobil();