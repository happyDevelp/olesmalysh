#pragma once
#include <Windows.h>
#include <Gl/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <windows.h>
#include "Figure.h"

class MyTriangle : public Figure {
public:
	MyTriangle(int X, int Y);
	MyTriangle(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, bool isChild);


	void draw() override;
	void drawBig() override;

};

