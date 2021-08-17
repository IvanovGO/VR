#include <epoxy/gl.h>
#include <epoxy/glx.h>
#include <glut.h>
#include <math.h>
#include <iostream>

float dx=0,dy=1,dz=0.0;
float red=1.0f, blue=1.0f, green=1.0f;

int main_win;


void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_LEFT :
			dz -= 0.01f;
			break;
		case GLUT_KEY_RIGHT :
			dz += 0.01f;
			break;
		case GLUT_KEY_UP :
			dx -= 0.01f;
			break;
		case GLUT_KEY_DOWN :
			dx += 0.01f;
			break;
		case 'x' :
			dy += 0.01f;
			break;
		case 'z' :
			dy -= 0.01f;
			break;
				case GLUT_KEY_F1 :
				red = 1.0;
				green = 0.0;
				blue = 0.0; break;
		case GLUT_KEY_F2 :
				red = 0.0;
				green = 1.0;
				blue = 0.0; break;
		case GLUT_KEY_F3 :
				red = 0.0;
				green = 0.0;
				blue = 1.0; break;
	}
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y){

if (key=='q') {glutDestroyWindow(main_win);}


glutPostRedisplay();
}



void display(){


glClearColor (0.0, 0.0, 0.0, 0.0);
glClear (GL_COLOR_BUFFER_BIT);
glColor3f(red,green,blue);
glOrtho(0.0, 0.0, 0.0, 1.0, -1.0, 1.0);
glPointSize(1);
	// обнулить трансформацию
	glLoadIdentity();

gluLookAt(   dx, dy,   dz,
		  0, 0,0,
		  1, 1, 1 );

glBegin(GL_TRIANGLES);

glVertex3f(0.5,0.1,0.2);
glVertex3f(0.15,0.21,0.22);
glVertex3f(0.0,0.0,0.2);

glEnd();


glFlush();
}



int main(int argc,char **argv){


glutInit(&argc,argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640,480);
glutInitWindowPosition (1280/2-640/2, 1024/2-480/2);
main_win=glutCreateWindow ("hello");
//init ();
/*
glutGameModeString("1280x1024:32");
glutEnterGameMode();
*/
glutDisplayFunc(display);
glutKeyboardFunc(Keyboard); 
glutSpecialFunc(processSpecialKeys);

glutMainLoop();
return 0; /* ISO C requires main to return int. */ 

}
