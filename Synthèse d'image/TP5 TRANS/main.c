// gcc main.c init.c init.h actions.c actions.h axes.o -lm -lGL -lGLU -lglut -o exec.exe

#include "init.h"
#include "actions.h"
#include "VM_init.c"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

struct cube {
  GLfloat sommets[8][3];
  int faces[6][4];
  GLfloat faceColors[6][3];
};

struct cube creer_cube(GLfloat taille){

  GLfloat taillereelle = (taille / 2);
  struct cube cube = { 
    {{-taillereelle, -taillereelle, taillereelle},{taillereelle, -taillereelle, taillereelle},{taillereelle, taillereelle, taillereelle},{-taillereelle, taillereelle, taillereelle},{taillereelle, -taillereelle, -taillereelle},{-taillereelle, -taillereelle, -taillereelle},{-taillereelle, taillereelle, -taillereelle},{taillereelle, taillereelle, -taillereelle}},
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}},
    {{1,0,0}, {0,1,0}, {0,0,1}, {1,1,0}, {1,0,1}, {1,1,1}}
  };
  return cube;
}

void rendu_cube(struct cube c){
  for(int i=0; i<=5; i++){
    glBegin(GL_QUADS);
    for(int j=0; j<=3; j++){
      if(i==1 || i==5) glColor3f(c.faceColors[i][0], c.faceColors[i][1], c.faceColors[i][2]);
      else glColor4f(c.faceColors[i][0], c.faceColors[i][1], c.faceColors[i][2], 0.5);
      glVertex3f(c.sommets[c.faces[i][j]][0] , c.sommets[c.faces[i][j]][1], c.sommets[c.faces[i][j]][2]);
    }
  }glEnd();
}

GLvoid Modelisation()
{
  VM_init();

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glFrontFace(GL_CCW);
  glDisable(GL_BLEND);
  glTranslatef(0.5, 0, 0);
  glColor4f(1, 0, 1, 1);
  glutSolidSphere(0.25, 30, 30);

  glTranslatef(-1, 0, 0);
  glColor4f(1, 0, 0, 0.5);
  glutSolidSphere(0.25, 30, 30);

  glTranslatef(0.5, 0, 0);
  axes();

  glEnable(GL_BLEND);
  glFrontFace(GL_CCW);
  rendu_cube(creer_cube(1));

  glFrontFace(GL_CCW);
  glPushMatrix();
    glTranslatef(2, 0, 1);
    glColor3f(1, 1, 0);
    glutSolidSphere(0.5, 30, 30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-2, 0, 1);
    glColor4f(0, 0, 1, 0.5);
    glutSolidSphere(0.5, 30, 30);
  glPopMatrix();

  GLfloat position[4] = {0, 0, 0, 1};
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  
  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}