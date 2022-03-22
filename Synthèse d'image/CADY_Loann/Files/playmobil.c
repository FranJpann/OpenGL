#include "playmobil.h"
#include "init.h"

extern GLuint texture[];

struct cube creer_corps(GLfloat taille){
  GLfloat taillereelle = (taille / 2);

  struct material or = {
    {0.24725,0.1995,0.0745,0.0 },
    {0.75164,0.60648,0.22648,0.0},
    {0.628281,0.555802,0.366065,0.0},
    51.2
  };
  struct cube cube = { 
    {{-taillereelle, -taillereelle, taillereelle},{taillereelle, -taillereelle, taillereelle},{taillereelle, taillereelle, taillereelle},{-taillereelle, taillereelle, taillereelle},{taillereelle, -taillereelle, -taillereelle},{-taillereelle, -taillereelle, -taillereelle},{-taillereelle, taillereelle, -taillereelle},{taillereelle, taillereelle, -taillereelle}},
    {{0, 1, 2, 3}, {4, 5, 6, 7}, {1, 4, 7, 2}, {0, 3, 6, 5}, {2, 7, 6, 3}, {1, 0, 5, 4}},
    {{0,0}, {1,0}, {1,1}, {0,1}},
    or
  };
  return cube;
}

void rendu_cube_texture(struct cube c, GLuint text){
  for(int i=0; i<=5; i++){
    glBindTexture(GL_TEXTURE_2D, text);
    glBegin(GL_QUADS);
    for(int j=0; j<=3; j++){
      glTexCoord2f(c.faceTexture[j][0], c.faceTexture[j][1]);
      glVertex3f(c.sommets[c.faces[i][j]][0] , c.sommets[c.faces[i][j]][1], c.sommets[c.faces[i][j]][2]);
    }
    glEnd();
  }
}

void creerPlaymobil(){
    glEnable(GL_CULL_FACE);
    rendu_cube_texture(creer_corps(1), texture[1]);
    glDisable(GL_CULL_FACE);
}