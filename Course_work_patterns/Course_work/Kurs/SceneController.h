#pragma once
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <windows.h>
#include "MyRectangle.h"
#include "MyTriangle.h"
#include "Figure.h"
#include "Composite.h"
#include "Serializer.h"

void idle();

void draw();

void key(int key, int x, int y);

void normalKeyHandler(unsigned char key, int x, int y);

class SceneController
{
private:
	list <Figure*> figuresList;
	bool shift = false; 
	bool moving = 0; 
	bool ishear = 0;
	bool multipleSelection = 0;

	static SceneController* _inst;
	


	Serializer* s = new Serializer("D:\\Oles\\Programming\\C++\\Course_work\\Kurshach.txt");




public:
	list<Figure*> getList() {
		return this->figuresList;
	}

	void setList(list<Figure*> l) {
		this->figuresList = l;
	}

	void addToList(Figure* f) {
		this->figuresList.push_back(f);
	}

	void clearList() {
		this->figuresList.clear();
	}

	Serializer* getSerializer() {
		return this->s;
	}

	bool getShift() {
		return this->shift;
	}

	void setShift(bool val) {
		this->shift = val;
	}


	bool getMultipleSelection() {
		return this->multipleSelection;
	}

	void setMultipleSelection(bool val) {
		this->multipleSelection = val;
	}


	bool getMoving() {
		return this->moving;
	}

	void setMoving(bool val) {
		this->moving = val;
	}

	bool getIsHere() {
		return this->ishear;
	}

	void setIsHere(bool val) {
		this->ishear = val;
	}

	static SceneController* getInstance();

	void init(void);

	void initMain(int argc, char** argv);
};


