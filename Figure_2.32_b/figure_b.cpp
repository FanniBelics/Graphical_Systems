#include <GL/glew.h>
#include <GL/freeglut.h>

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f(0.518, 0.8, 0.82);

	//Shape
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(20.0, 80.0, 0.0);
	glVertex3f(20.0, 100.0, 0.0);
	glVertex3f(40.0, 80.0, 0.0);
	glVertex3f(60.0, 100.0, 0.0);
	glVertex3f(40.0, 20.0, 0.0);
	glVertex3f(60.0, 40.0, 0.0);
	glVertex3f(60.0, 20.0, 0.0);
	glVertex3f(70.0, 40.0, 0.0);
	glVertex3f(70.0, 20.0, 0.0);
	glVertex3f(90.0, 20.0, 0.0);
	glVertex3f(70.0, 100.0, 0.0);
	glVertex3f(90.0, 80.0, 0.0);
	glVertex3f(110.0, 100.0, 0.0);
	glVertex3f(110.0, 80.0, 0.0);

	glEnd();

	//Outline
	glColor3f(0.345, 0.557, 0.553);
	glBegin(GL_LINE_LOOP);
	glVertex3f(20.0, 100.0, 0.0);
	glVertex3f(60.0, 100.0, 0.0);
	glVertex3f(60.0, 40.0, 0.0);
	glVertex3f(70.0, 40.0, 0.0);
	glVertex3f(70.0, 100.0, 0.0);
	glVertex3f(110.0, 100.0, 0.0);
	glVertex3f(110.0, 80.0, 0.0);
	glVertex3f(90.0, 80.0, 0.0);
	glVertex3f(90.0, 20.0, 0.0);
	glVertex3f(40.0, 20.0, 0.0);
	glVertex3f(40.0, 80.0, 0.0);
	glVertex3f(20.0, 80.0, 0.0);

	glEnd();


	//Inner triangles
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(20.0, 100.0, 0.0);
	glVertex3f(40.0, 80.0, 0.0);
	glVertex3f(60.0, 100.0, 0.0);
	glVertex3f(40.0, 20.0, 0.0);
	glVertex3f(60.0, 40.0, 0.0);

	glEnd();

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 130.0, 0.0, 130.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("figure 2.32/b");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}