#include <GL/glut.h>
#include "solarsystem.hpp"

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50

#define width 700
#define height 700

typedef unsigned char uchar;

SolarSystem solarsystem;

void onDisplay(void) {
	solarsystem.onDisplay();
}

void onUpdate(void) {
	solarsystem.onUpdate();
}

void onKeyboard(uchar key, int x,int y) {
	solarsystem.onKeyboard(key,x,y);
}

int main(int argc, char*argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
	glutCreateWindow("SolarSystem");
	glutDisplayFunc(onDisplay);
	glutIdleFunc(onUpdate);
	glutKeyboardFunc(onKeyboard);
	glutMainLoop();
	return 0;	
}
