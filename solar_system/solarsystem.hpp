#ifndef sloar_system_h
#define sloar_system_h

#include <GL/glut.h>
#include "stars.hpp"
#include <iostream>

using namespace std;
#define STARS_NUM 10

class SolarSystem {
public:
	SolarSystem();
	~SolarSystem();

	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key, int x ,int y);

private:
	Star *stars[STARS_NUM];

	GLdouble viewX, viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};
#endif
