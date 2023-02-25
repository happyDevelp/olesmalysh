#pragma once
#include <Windows.h>
#include <Gl/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include "Figure.h"
using namespace std;

class MyRectangle : public Figure {
public:
	MyRectangle(int X, int Y);
	
	MyRectangle(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool isDraw, bool isChild);

	void draw() override;
	void drawBig() override;
	void moveDetect() override;
};