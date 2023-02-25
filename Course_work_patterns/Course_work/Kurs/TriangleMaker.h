#pragma once
#include "Maker.h"
#include "MyTriangle.h"
struct TriangleMaker : Maker
{
	Figure* factoryMethod(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, bool isChild) override {
		return new MyTriangle(X, Y, xs, ys, R, G, B, Act, IsDraw, isChild);
	}
	Figure* factoryMethod(int X, int Y) {
		return new MyTriangle(X, Y);
	}
};