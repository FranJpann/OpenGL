GLfloat z = -5;
GLfloat xrot = 0.0;
GLfloat yrot = 0.0;

GLvoid VM_init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, z);
	glRotatef(xrot, 0.0, 1.0, 0.0);
	glRotatef(yrot, 1.0, 0.0, 0.0);

	
  	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  	glRotatef(xrot, 1, 0, 0);
  	glRotatef(yrot, 0, 1, 0);
  	glRotatef(z, 1, 0, 1);
  	/*    */
  	//glTranslateF(0, 0, z);
  	/*    */
 	/*glRotatef(x_scene, 1, 0, 0);
  	glRotatef(y_scene, 0, 1, 0);
  	glRotatef(z_scene, 1, 0, 1);*/
}