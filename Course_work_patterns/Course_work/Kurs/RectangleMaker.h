#pragma once
#include "Maker.h"
#include "MyRectangle.h"
struct RectangleMaker : Maker
{
	Figure* factoryMethod (int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, bool isChild) override {
		return new MyRectangle(X, Y, xs, ys, R, G, B, Act, IsDraw, isChild);
	}
	Figure* factoryMethod(int X, int Y) {
		return new MyRectangle(X, Y);
	}
};


