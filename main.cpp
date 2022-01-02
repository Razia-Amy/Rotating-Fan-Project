#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);// to clear previous pixel

	glPushMatrix();//Set current matrix on the stack

	glColor3f(0.0, 0.0, 1.0);


	glRectf(-25.0, -4.0, 25.0, 4.0);
	glRectf(-4.0, -25.0, 4.0, 25.0);
	glColor3f(.0, 1.0, 0.0);
	glutSolidTorus(1.00, 6.4, 10, 100); // inner radius, outer radius, sides, segments
	glPopMatrix();//force execution of GL commands in finite time
	glFlush();//forces the drawing to begin execution
}


void spinDisplay_right1(void)
{
   spin = -.60;
			glutPostRedisplay(); //built in function for updating our values
			glRotatef(spin, 0.0, 0.0, 1.0); //angle, x, y, z(if it plus it will rotate in clockwise)
}


void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0); // clear previous color
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); // (x = left, x = right, y = bottom, y = top, near value, far value) graph paper size
}

int a=0;
void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 's':
                {
                    if(a==0)
                {
		            glutIdleFunc(spinDisplay_right1);
		             a=1;
                }

         else
         {
              glutIdleFunc(NULL);//to stop shape rotation
              a=0;
         }
         }
			case 'k':
			{


			glRotatef(-10, 0.0, 0.0, 1.0);
			       break;
			}
            case 'i':
                glRotatef(3, 0.0, 0.0, 1.0);
                break;

	  default:
			break;
	}
}


int main(int argc, char *argv[])
{

    glutInit( & argc, argv ); // initialize glut

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (300, 300);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("display fan");
	init();

	glutDisplayFunc(display);//to use any shape with mouse or keyboard we use this function
	glutKeyboardFunc(my_keyboard);

	glutMainLoop();

	return 0;   /* ANSI C requires main to return int. */
}

