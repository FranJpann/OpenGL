#include "init.h"
#include "actions.h"

int window = 0;

GLfloat position[4] = {0, 0, 0, 1};
GLfloat diff_et_spec[4] = { 0.5, 0.5, 0.5, 1};
GLfloat ambiente[4] = {0.4, 0.4, 0.4, 1};

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
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("OpenGL");
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	glutReshapeFunc(&Redimensionne);
	glutKeyboardFunc(&touche);
	glutSpecialFunc(&touche_speciale);
	glClearColor(0.0 , 0.0 , 0.0 , 0.0);

	glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_DIFFUSE, diff_et_spec);
    //glLightfv(GL_LIGHT0, GL_SPECULAR, diff_et_spec);
	//glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);

	glutMainLoop();
	return 1;
}