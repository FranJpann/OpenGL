#include "actions.h"

extern GLfloat xcam;
extern GLfloat ycam;
extern GLfloat zcam;
extern GLfloat xrot;
extern GLfloat yrot;

extern GLfloat mainRotate;

void touche(unsigned char key, int x, int y) 
{
  switch(key){
    case ESCAPE :
      exit(1);
    case TOUCHE_MIN_R :
      mainRotate += 20;
  }
}

void touche_speciale(int key, int x, int y) 
{
  switch(key){

    case GLUT_KEY_UP :
      yrot += 30.0;
      break;
    
    case GLUT_KEY_DOWN :
      yrot -= 30.0;
      break;

    case GLUT_KEY_LEFT :
      xrot += 20.0;
      break;

    case GLUT_KEY_RIGHT :
      xrot -= 20.0;
      break;
  }
}

