#include "init.h"
#include "ppm.h"

GLuint texture[1];

void loadTexture(){
  TEXTURE_STRUCT * text = readPpm("Textures/sol.ppm");

  glGenTextures(1, &texture[0]);
  glBindTexture(GL_TEXTURE_2D, texture[0]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, text->width, text->height, 0, GL_RGB, GL_UNSIGNED_BYTE, text->data);

  glEnable(GL_TEXTURE_2D);
  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  glBindTexture(GL_TEXTURE_2D, 0);
}