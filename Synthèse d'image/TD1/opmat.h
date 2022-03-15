#include <stdio.h>     
#include <stdlib.h>     
#include <math.h>
#include <GL/gl.h>

GLfloat * mxm(GLfloat * m1, GLfloat * m2);

GLfloat * mxv(GLfloat * m, GLfloat * v);

void pretty_printer(GLfloat *m);

GLfloat * identite();

GLfloat * translation(GLfloat x, GLfloat y, GLfloat z);

GLfloat * homothetie(GLfloat x, GLfloat y, GLfloat z);

void paume();

void doigt(int xc, int yc, int zc, GLfloat rotDoigt, GLfloat size);
