#include "Figure.h"
#include "MyTriangle.h"
#include "MyRectangle.h"
#include "Composite.h"
#include <string>
#include "TriangleMaker.h"
#include "RectangleMaker.h"
using namespace std;

Figure::Figure(int X, int Y) {
	x = X;
	y = Y;
	Xs = X;
	Ys = Y;
}

Figure::Figure(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, int Key, bool isChild) {
	x = X;
	y = Y;
	Xs = xs;
	Ys = ys;
	r = R;
	g = G;
	b = B;
	act = Act;
	isdrawable = IsDraw;
	key = Key;
	this->isChild = isChild;
}

void Figure::select() {
	this->act = true;
}

void Figure::draw() {
	return;
}

void Figure::drawBig() {
	return;
}

void Figure::moveTop() {
	if (this->act && this->isdrawable && this->y + 5 < 50) {
		this->y++;
		glutPostRedisplay();
	}
}

void Figure::moveLeft() {
	if (this->act && this->isdrawable && this->x > 0) {
		this->x--;
		glutPostRedisplay();
	}
}

void Figure::moveBottom() {
	if (this->act && this->isdrawable && this->y > 0) {
		this->y--;
		glutPostRedisplay();
	}
}

void Figure::moveDetect() {
	if (this->act && this->isdrawable && this->x + 10 < 100) {
		this->x++;
		glutPostRedisplay();
	}
}

void Figure::changeColor() {
	if (this->act && this->isdrawable) {
		if (this->r == 0.2 && this->g == 0.6 && this->b == 0.3) {
			this->b = 1;
		}
		else if (this->b == 1){
			this->r = 1;
			this->b = 0;
		}
		else if (this->r == 1)
		{
			this->r = 0;
			this->b = 0;
		}
	}
}

void Figure::setFirstPosition() {
	if (this->act) {
		this->x = this->Xs;
		this->y = this->Ys;
	}
}

void Figure::changeVisibility() {
	if (this->act) {
		if (this->isdrawable) {
			this->isdrawable = false;
		}
		else {
			this->isdrawable = true;
		}
	}
}

Figure* Figure::clone() const {
	TriangleMaker trCreator;
	RectangleMaker rectCreator;
	switch (this->key)
	{
	case 1:
		return trCreator.factoryMethod(this->x, this->y, this->Xs, this->Ys, this->r, this->g, this->b, this->act, this->isdrawable, this->isChild);
		break;
	case 2:
		return rectCreator.factoryMethod(this->x, this->y, this->Xs, this->Ys, this->r, this->g, this->b, this->act, this->isdrawable, this->isChild);
		break;
	default:
		return new Figure(this->x, this->y, this->Xs, this->Ys, this->r, this->g, this->b, this->act, this->isdrawable, this->key, this->isChild);
		break;
	}
}

void Figure::idle() {
	if (this->act) {
		Sleep(20);
		if (10 + x < 100 && y + 5 < 50) {
			y++;
			x++;
		}
		glutPostRedisplay();
	}
}

string Figure::serialize() {
	string s = to_string(key).append(";")
		.append(to_string(x)).append(";")
		.append(to_string(y)).append(";")
		.append(to_string(Xs)).append(";")
		.append(to_string(Ys)).append(";")
		.append(to_string(r)).append(";")
		.append(to_string(g)).append(";")
		.append(to_string(b)).append(";")
		.append(to_string(act)).append(";")
		.append(to_string(isdrawable)).append(";")
		.append(to_string(isChild)).append(";");
	return s;
}

void Figure::deserialize(string s){

}

Figure* Figure::cloneComposite() {
	return new Figure(0, 0);
}


void Figure::changeActivityMode(bool val) {
	this->act = val;
}

void Figure::addToComposite(Figure* f) {

}

