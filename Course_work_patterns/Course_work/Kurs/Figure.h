#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <windows.h>
using namespace std;
class Figure
{
public:int x, y, Xs, Ys;	
	  float r = 0.2, g = 0.6, b = 0.3;
	  int key = 0;
	  bool act = true, isdrawable = true, isChild = false;
	  Figure(int X, int Y);

	  Figure(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, int Key, bool isChild);

	  virtual void draw();

	  virtual void drawBig();

	  virtual void changeColor();

	  virtual void moveTop();

	  virtual void moveLeft();

	  virtual void moveBottom();

	  virtual void moveDetect();

	  virtual void setFirstPosition();

	  virtual void changeVisibility();

	  virtual Figure* clone() const;

	  virtual void idle();

	  virtual void select();

	  virtual string serialize();

	  virtual void deserialize(string s);

	  virtual void addToComposite(Figure* f);

	  virtual void changeActivityMode(bool val);

	  virtual Figure* cloneComposite();


};

