/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
      glVertex3f (40 , 40, 0.0);
      glVertex3f (-40, 40, 0.0);
      glVertex3f (-40,-40, 0.0);
      glVertex3f (40 ,-40, 0.0);
      glVertex3f (40 , 40, 0.0);
	glEnd();

	glFlush();

		glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_LINES);
      glVertex3f (40 , 30, 0.0);
      glVertex3f (-40, 30, 0.0);
	glEnd();

	glFlush();

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
      glVertex3f (40 , 23, 0.0);
      glVertex3f (-40, 23, 0.0);
	glEnd();

	glFlush();

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
      glVertex3f (40 , 7, 0.0);
      glVertex3f (-40, 7, 0.0);
	glEnd();

	glFlush();

		glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
      glVertex3f (40 , -10, 0.0);
      glVertex3f (-40, -10, 0.0);
	glEnd();

	glFlush();

			glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
      glVertex3f (40 , -25, 0.0);
      glVertex3f (-40, -25, 0.0);
	glEnd();

	glFlush();

//horizontal

glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_LINES);
       glVertex3f (-33 , 40, 0.0);
      glVertex3f (-33, -40, 0.0);
	glEnd();

	glFlush();

glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
       glVertex3f (-25 , 40, 0.0);
      glVertex3f (-25, -40, 0.0);
	glEnd();

	glFlush();

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
       glVertex3f (-8 , 40, 0.0);
      glVertex3f (-8, -40, 0.0);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
       glVertex3f (10 , 40, 0.0);
      glVertex3f (10, -40, 0.0);
	glEnd();

	glFlush();

glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
       glVertex3f (25 , 40, 0.0);
      glVertex3f (25, -40, 0.0);
	glEnd();

	glFlush();

	glColor3f(0.0f, 1.0f,0.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f (-35 , 50, 0.0);
	glVertex3f (-15 , 50, 0.0);
	glVertex3f (-25 , 40, 0.0);
	glEnd();
	glFlush();

		glColor3f(0.0f, 1.0f,0.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f (-50 , 40, 0.0);
	glVertex3f (-40 , 30, 0.0);
	glVertex3f (-50 , 20, 0.0);
	glEnd();
	glFlush();



}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-70.0, 70.0, -70.0, 70.0, -1.0, 1.0);
}



int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (350, 350);
	glutInitWindowPosition (200, 200);
	glutCreateWindow ("drawing");
	init();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}

