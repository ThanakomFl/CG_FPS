
#include "Makestars.h"

float red, green, blue;
float dx, dy;
float currentTime, deltaTime, lastTime, elapsedTime;
int fps;

Makestars stars;

void MoveEarth() {

	stars.nej += 1.93 / 10;
	stars.merj += 1.18 / 10;
	stars.vej += 0.68 / 10;
	stars.eaj += 1.68 / 10;
	stars.marj += 1.43 / 10;
	stars.juj += 2.68 / 10;
	stars.saj += 2.43 / 10;
	stars.urj += 2.18 / 10;
	stars.moonj += 2.93 / 10;
	glutPostRedisplay();
}

void Init() { 
	glClearColor(0.211, 0.278, 0.309, 1.0);
	gluOrtho2D(-10, 100, -10, 100);
	red = 1.0;
	green = 1.0;
	blue = 1.0;
	dx = 0.0;
	dy = 0.0;
}

void MyDisplay() {

	glClear(GL_COLOR_BUFFER_BIT);
		stars.randomstar();

		glClear(GL_COLOR_BUFFER_BIT);
		currentTime = glutGet(GLUT_ELAPSED_TIME);

		deltaTime = (currentTime - lastTime) / 1000.0;
		elapsedTime += deltaTime;
		fps++;

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0, 100);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(100, 0);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(10, 1);
		glVertex2f(10, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(20, 1);
		glVertex2f(20, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(30, 1);
		glVertex2f(30, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(40, 1);
		glVertex2f(40, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(50, 1);
		glVertex2f(50, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(60, 1);
		glVertex2f(60, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(70, 1);
		glVertex2f(70, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(80, 1);
		glVertex2f(80, -1);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 10);
		glVertex2f(-1, 10);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 20);
		glVertex2f(-1, 20);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 30);
		glVertex2f(-1, 30);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 40);
		glVertex2f(-1, 40);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 50);
		glVertex2f(-1, 50);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 60);
		glVertex2f(-1, 60);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 70);
		glVertex2f(-1, 70);
		glEnd();

		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2f(1, 80);
		glVertex2f(-1, 80);
		glEnd();

		if (elapsedTime <= 3.0)
		{

			cout << elapsedTime << endl;
			dx = stars.Update_X(elapsedTime, 10.0 / 3.0, 0.0);
			dy = stars.Update_Y(elapsedTime, 20.0 / 3.0, 0.0);


			stars.Makestar(5, stars.n, dx, dy, 0.435, 0.784, 0.815);
		}
		else if (elapsedTime > 3.0 && elapsedTime <= 8.0)
		{
			dx = stars.Update_X(elapsedTime, 10.0 / 5.0, 20.0 / 5.0);
			dy = stars.Update_Y(elapsedTime, 30.0 / 5.0, 10.0 / 5.0);

			stars.Makestar(5, stars.n, dx, dy, 0.435, 0.784, 0.815);
		}
		else if (elapsedTime > 8 && elapsedTime <= 9.0)
		{
			dx = stars.Update_X(elapsedTime, float(30), -220.0);
			dy = stars.Update_Y(elapsedTime, float(-40), 370.0);

			stars.Makestar(5, stars.n, dx, dy, 0.435, 0.784, 0.815);

		}else
		{
			stars.Makestar(5, stars.n, dx, dy, 0.435, 0.784, 0.815);
		}

		glFlush();
		glutSwapBuffers();
		lastTime = currentTime;


	glFlush();
}

void MyMouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON: printf("Left Button\n");
		if (state == GLUT_DOWN)
			printf("Down \n");
		break;
	case GLUT_RIGHT_BUTTON: printf("Right Button\n");
		if (state == GLUT_UP)
			printf("Up\n");
		break;
	default: break;

	}

}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a': printf("a\n");
		elapsedTime = 0;
		glutIdleFunc(MoveEarth);
		break;
	case 'A': printf("a\n");
		glutIdleFunc(MoveEarth);
		break;
	case 'b': printf("b\n");
		red = 0.0; green = 0.0; blue = 1.0;
		glutPostRedisplay();
		break;
		
	default: exit(0);
	}
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(10, 0);
	//----------------------------------------------
	glutCreateWindow("Solar project");
	// --------------------- Call back function ------------
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouse);
	glutKeyboardFunc(MyKeyboard);

	Init();

	glutMainLoop();
	
	return 0;
}