#include "init.h"
#include "actions.h"

int window = 0;
GLuint blend = 0;
GLuint lumiere = 0;

GLvoid Redimensionne(GLsizei width, GLsizei height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc, char** argv, void (*Modelisation)()){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640, 400);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("OpenGL");
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	glutReshapeFunc(&Redimensionne);
	glutKeyboardFunc(&touche);
	glutSpecialFunc(&touche_speciale);
	glClearColor(0.0 , 0.0 , 0.0 , 0.0);
	glutMainLoop();
	return 1;
}