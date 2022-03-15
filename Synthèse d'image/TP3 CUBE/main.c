// gcc main.c init.c init.h actions.c actions.h normale.c normale.h axes.o -lm -lGL -lGLU -lglut -o exec.exe

#include "init.h"
#include "actions.h"
#include "VM_init.c"
#include "normale.h"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

struct cube1 {
  GLfloat sommets[8][3];
  int faces[6][4];
  GLfloat faceColors[6][3];
};

struct cube1 creer_cube1(GLfloat taille){

  GLfloat taillereelle = (taille / 2);
  struct cube1 cube = { 
    {{-taillereelle, -taillereelle, taillereelle},{taillereelle, -taillereelle, taillereelle},{taillereelle, taillereelle, taillereelle},{-taillereelle, taillereelle, taillereelle},{taillereelle, -taillereelle, -taillereelle},{-taillereelle, -taillereelle, -taillereelle},{-taillereelle, taillereelle, -taillereelle},{taillereelle, taillereelle, -taillereelle}},
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}},
    {{1,0,0}, {0,1,0}, {0,0,1}, {1,1,0}, {1,0,1}, {1,1,1}}
  };
  return cube;
}

void rendu_cube1(struct cube1 c){
  for(int i=0; i<=5; i++){
    glBegin(GL_QUADS);
    for(int j=0; j<=3; j++){
      glColor3f(c.faceColors[i][0], c.faceColors[i][1], c.faceColors[i][2]);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glEnable(GL_DEPTH_TEST);
      glVertex3f(c.sommets[c.faces[i][j]][0] , c.sommets[c.faces[i][j]][1], c.sommets[c.faces[i][j]][2]);
    }
  }glEnd();
}

struct cube2 {
  struct cube1 cube;
  struct normale v[6];
};

struct cube2 creer_cube2(GLfloat taille){
  struct cube1 c = creer_cube1(taille);
  
  struct normale v1, v2, v3, v4, v5, v6;
  calcul_normale(c.sommets[0][0], c.sommets[0][1], c.sommets[0][2], c.sommets[1][0], c.sommets[1][1], c.sommets[1][2], c.sommets[2][0], c.sommets[2][1], c.sommets[2][2], &v1);
  calcul_normale(c.sommets[4][0], c.sommets[4][1], c.sommets[4][2], c.sommets[5][0], c.sommets[5][1], c.sommets[5][2], c.sommets[6][0], c.sommets[6][1], c.sommets[6][2], &v1);
  calcul_normale(c.sommets[1][0], c.sommets[1][1], c.sommets[1][2], c.sommets[4][0], c.sommets[4][1], c.sommets[4][2], c.sommets[7][0], c.sommets[7][1], c.sommets[7][2], &v1);
  calcul_normale(c.sommets[0][0], c.sommets[0][1], c.sommets[0][2], c.sommets[3][0], c.sommets[3][1], c.sommets[3][2], c.sommets[6][0], c.sommets[6][1], c.sommets[6][2], &v1);
  calcul_normale(c.sommets[2][0], c.sommets[2][1], c.sommets[2][2], c.sommets[7][0], c.sommets[7][1], c.sommets[7][2], c.sommets[6][0], c.sommets[6][1], c.sommets[6][2], &v1);
  calcul_normale(c.sommets[1][0], c.sommets[0][1], c.sommets[0][2], c.sommets[1][0], c.sommets[1][1], c.sommets[0][2], c.sommets[5][0], c.sommets[5][1], c.sommets[5][2], &v1);

  struct cube2 c2 = { c, { v1, v2, v3, v4, v5, v6 } };
  return c2;
}

void rendu_cube2(struct cube2 c){
  rendu_cube1(c.cube);

    glBegin(GL_LINES);
      glVertex3f(0, 0, 0);
      glVertex3f(c.v[1].x, c.v[1].y, c.v[1].z);
    glEnd();
}

GLvoid Modelisation()
{
  VM_init();

  glFrontFace(GL_CW);
  rendu_cube2(creer_cube2(2));

  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}