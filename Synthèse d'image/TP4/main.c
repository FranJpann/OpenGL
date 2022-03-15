// gcc main.c init.c init.h actions.c actions.h -lm -lGL -lGLU -lglut -o exec.exe

#include "init.h"
#include "actions.h"
#include "VM_init.c"

extern GLfloat z;
extern GLfloat xrot;
extern GLfloat yrot;

int temps;
int temps_suivant;
int temps_depuis_le_precedent_calcul = 0;

GLfloat angle = 0;
GLfloat vitesse_reelle = 0;
int frames = 0, fps = 0;

void show_fps(){
  printf("%ld\n", fps);
}

GLfloat angle_reel(GLfloat vitesse){

  frames += 1;

  temps_suivant = glutGet(GLUT_ELAPSED_TIME);
  temps_depuis_le_precedent_calcul += temps_suivant - temps;

  if(temps_depuis_le_precedent_calcul >= 50){
    temps_depuis_le_precedent_calcul = 0;
    fps = frames * 10;
    frames = 0;
    vitesse_reelle = vitesse / ((GLfloat) fps);
  }

  temps = temps_suivant;
  angle += vitesse_reelle;
  return angle;
}

GLvoid Modelisation()
{
  VM_init();

    show_fps();

    glPushMatrix();
    {
      glTranslatef(0, 1, 0);
      glRotatef(angle_reel(45), 0, 1, 0);
      glTranslatef(0, -1, 0);
      glBegin(GL_TRIANGLES);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(0, 0, 1);
      glEnd();
    }
    glPopMatrix();

    xrot = -angle_reel(45);

  axes();

  glutSwapBuffers();
}

int main(int argc, char**argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}