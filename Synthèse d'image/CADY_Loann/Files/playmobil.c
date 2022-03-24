#include "playmobil.h"
#include "init.h"

extern GLuint texture[];
GLfloat a = 0;

/*struct material plastic = {
  {0, 0, 0, 0.0},
  {0.01, 0.01, 0.01, 0.0},
  {0.5, 0.5, 0.5, 0.0},
  0.25
};*/

struct cube creer_cube(){
  struct cube cube = { 
    {{-0.5, -0.5, 0.5},{0.5, -0.5, 0.5},{0.5, 0.5, 0.5},{-0.5, 0.5, 0.5},{0.5, -0.5, -0.5},{-0.5, -0.5, -0.5},{-0.5, 0.5, -0.5},{0.5, 0.5, -0.5}},
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}},
    {{1, 0, 0}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1}, {0, 1, 1}, {0, 0, 1}}
  };
  return cube;
}

void rendu_cube(struct cube c){
  for(int i=0; i<=5; i++){
    glBegin(GL_QUADS);
    for(int j=0; j<=3; j++){
      glColor3f(c.couleur[i][0], c.couleur[i][1], c.couleur[i][2]);
      glVertex3f(c.sommets[c.faces[i][j]][0] , c.sommets[c.faces[i][j]][1], c.sommets[c.faces[i][j]][2]);
    }
    glEnd();
  }
}

void creerPlaymobil(){
    glEnable(GL_CULL_FACE);
      //Corps
      glPushMatrix();
      {
        glScalef(0.5, 0.5, 0.25);
        rendu_cube(creer_cube());
      }glPopMatrix();

      //Jambes
      glPushMatrix();
      {
        glScalef(0.15, 0.5, 0.15);

        glTranslatef(1, -1, 0);
        rendu_cube(creer_cube());

        glTranslatef(-2, 0, 0);
        rendu_cube(creer_cube());
      }glPopMatrix();

      //1er bras et 1ere main
      glPushMatrix();
      {
        glTranslatef(0.20, 0.25, 0);
        glRotatef(30, 0, 0, 1);
        glTranslatef(0, -0.25, 0);

        glPushMatrix();
        {
          glScalef(0.12, 0.45, 0.12);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glTranslatef(0, -0.25, 0);

        glPushMatrix();
        {
          glScalef(0.06, 0.045, 0.06);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glTranslatef(0, -0.025, 0);
        glRotatef(a, 0, 1, 0);

        glPushMatrix();
        {
          glScalef(0.126, 0.030, 0.06);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glPushMatrix();
        {
          glTranslatef(0.0475, -0.05, 0);
          glRotatef(90, 0, 0, 1);
          glScalef(0.08, 0.030, 0.06);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glPushMatrix();
        {
          glTranslatef(-0.0475, -0.05, 0);
          glRotatef(90, 0, 0, 1);
          glScalef(0.08, 0.030, 0.06);
          rendu_cube(creer_cube());
        }glPopMatrix();

      }glPopMatrix();
  
    glDisable(GL_CULL_FACE);
}