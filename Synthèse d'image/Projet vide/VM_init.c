GLfloat z = -5;
GLfloat xrot = 0.0;
GLfloat yrot = 0.0;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, z);
	glRotatef(xrot, 0.0, 1.0, 0.0);
	glRotatef(yrot, 1.0, 0.0, 0.0);
}