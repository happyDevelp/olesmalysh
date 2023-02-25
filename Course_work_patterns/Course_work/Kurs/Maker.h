#pragma once
#include "Figure.h";
struct Maker
{
	virtual Figure* factoryMethod(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, bool isChild) = 0;
};

