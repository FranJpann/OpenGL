 #include "actions.h"

extern GLfloat xrot;   
extern GLfloat yrot; 

extern GLfloat rotDoigt;
extern GLfloat rotPouce;
extern GLfloat rotPouce2;

void touche_pressee(unsigned char key, int x, int y) 
{
    usleep(100);

    switch (key) { 

    case ESCAPE: 
	  exit(1);                   	
	  break; 

    case ESPACE:
      xrot = 0;
      yrot = 0;
      break;

    case TOUCHE_MIN_B:
      if(rotDoigt < 90) rotDoigt += 1;
      if(rotPouce < 20) rotPouce += 1;
      if(rotPouce2 < 90 && rotPouce == 20) rotPouce2 += 1.5;
      break;

    case TOUCHE_MIN_L :
      if(rotDoigt > 0) rotDoigt -= 1;
      if(rotPouce > 0 && rotPouce2 == 0) rotPouce -= 1;
      if(rotPouce2 > 0) rotPouce2 -= 1.5;
      break;
    }
}

