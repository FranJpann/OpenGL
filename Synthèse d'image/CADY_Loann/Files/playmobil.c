#include "playmobil.h"
#include "init.h"

extern GLuint texture[];
GLfloat mainRotate = 0;

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
      //glColor3f(c.couleur[i][0], c.couleur[i][1], c.couleur[i][2]);
      glVertex3f(c.sommets[c.faces[i][j]][0] , c.sommets[c.faces[i][j]][1], c.sommets[c.faces[i][j]][2]);
    }
    glEnd();
  }
}

void creerPlaymobil(){
      //Corps
      glPushMatrix();
      {
        glColor3f(0, 0, 1);
        glScalef(0.27, 0.36, 0.135);
        rendu_cube(creer_cube());
      }glPopMatrix();

      //Short entrejambe
      glPushMatrix();
      {
        glColor3f(0, 0.3, 0.7);
        glScalef(0.2, 0.2, 0.06);
        glTranslatef(0, -1, 0);
        rendu_cube(creer_cube());
      }glPopMatrix();

      //Jambes
      glPushMatrix();
      {
        glColor3f(0.75, 0.55, 0.55);
        glScalef(0.07, 0.35, 0.07);
        glTranslatef(1, -1, 0);
        rendu_cube(creer_cube());

        glPushMatrix();
        {
          glColor3f(0, 0.3, 0.7);
          glTranslatef(0, 0.25, 0);
          glScalef(1.4, 0.5, 1.4);
          rendu_cube(creer_cube());
        }glPopMatrix();

        //premier pied
        glPushMatrix();
        {
          glColor3f(0, 0, 0);
          glTranslatef(0, -0.60, 0.2);
          glScalef(1.2, 0.15, 1.5);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glColor3f(0.75, 0.55, 0.55);
        glTranslatef(-2, 0, 0);
        rendu_cube(creer_cube());

        glPushMatrix();
        {
          glColor3f(0, 0.3, 0.7);
          glTranslatef(0, 0.25, 0);
          glScalef(1.4, 0.5, 1.4);
          rendu_cube(creer_cube());
        }glPopMatrix();

        //Deuxieme pied
        glPushMatrix();
        {
          glColor3f(0, 0, 0);
          glTranslatef(0, -0.60, 0.2);
          glScalef(1.2, 0.15, 1.5);
          rendu_cube(creer_cube());
        }glPopMatrix();

      }glPopMatrix();

      //1er bras et 1ere main
      glPushMatrix();
      {
        glScalef(0.65, 0.65, 0.65);
        glTranslatef(0.20, 0.27, 0);
        glRotatef(20, 0, 0, 1);
        glTranslatef(0, -0.25, 0);

        glPushMatrix();
        {
          glColor3f(0.75, 0.55, 0.55);
          glScalef(0.12, 0.45, 0.12);
          rendu_cube(creer_cube());

          glColor3f(0, 0, 1);
          glTranslatef(0, 0.30, 0);
          glScalef(1.1, 0.5, 1.1);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glTranslatef(0, -0.25, 0);

        glPushMatrix();
        {
          glColor3f(0.75, 0.55, 0.55);
          glScalef(0.06, 0.045, 0.06);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glTranslatef(0, -0.025, 0);
        glRotatef(mainRotate, 0, 1, 0);

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

      //2eme bras et 2eme main
      glPushMatrix();
      {
        glScalef(0.65, 0.65, 0.65);
        glTranslatef(-0.20, 0.27, 0);
        glRotatef(-20, 0, 0, 1);
        glTranslatef(0, -0.25, 0);

        glPushMatrix();
        {
          glScalef(0.12, 0.45, 0.12);
          rendu_cube(creer_cube());
          glColor3f(0, 0, 1);
          glTranslatef(0, 0.30, 0);
          glScalef(1.1, 0.5, 1.1);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glTranslatef(0, -0.25, 0);

        glPushMatrix();
        {
          glColor3f(0.75, 0.55, 0.55);
          glScalef(0.06, 0.045, 0.06);
          rendu_cube(creer_cube());
        }glPopMatrix();

        glTranslatef(0, -0.025, 0);
        glRotatef(mainRotate, 0, 1, 0);

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

      //tête
      
      glPushMatrix();
      {
        glTranslatef(0, 0.2, 0);
        glScalef(0.07, 0.07, 0.07);
        rendu_cube(creer_cube());
        glTranslatef(0, 2, 0);
        glutSolidSphere(2, 20, 20);
      }glPopMatrix();

}
