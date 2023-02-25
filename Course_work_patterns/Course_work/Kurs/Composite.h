#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <iterator>
#include <list>
#include <windows.h>
#include "MyRectangle.h"
#include "MyTriangle.h"


class Composite: public Figure 
{
public: 
	int count = 0;
	  list <Figure*> comp; //тут храним все фигуры композита
	  Figure* first;
	  Figure* last;
	  
	  Composite(Figure* f); 
	  Composite();
	  ~Composite();


	  void addToComposite(Figure* f) override;
	  
	  void addToComposite(Composite c);
	  
	  void clearComposite();
	  
	  void draw();
	 
	  void changeColor() override;
	  
	  void moveTop() override;
	  
	  void moveBottom()override;
	  
	  void moveLeft() override;
	  
	  void moveDetect() override;
	  
	  void idle();
	  
	  void setFirstPosition() override;
	  
	  Figure* cloneComposite() override;
	  
	  void select();
	  
	  void changeVisibility();

	  void changeActivityMode(bool val) override;
	  
	  string serialize() override;

};

