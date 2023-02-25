#include "MyRectangle.h"

MyRectangle::MyRectangle(int X, int Y) :Figure(X, Y) { // X, Y начальна€ позици€ фигуры
	this->key = 2;
}

MyRectangle::MyRectangle(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool isDraw, bool isChild) : Figure(X, Y, xs, ys, R, G, B, Act, isDraw, 2, isChild) {

}

void MyRectangle::draw() {
	if (!this->isdrawable) {
		return;
	}
	
	glColor3f(this->r, this->g, this->b); //присваиваем цвет фигуры RGB
	
	glBegin(GL_POLYGON); //интерпритируем фигуру как многоугольник, и между глЅегин и гл≈нд указываем вершины фигуры
	glVertex2f(x + 10, y + 10);	//указываем вершины нашей фигуры (снизу тоже, получаетс€ четыре вершины)
	glVertex2f(x + 10, y);
	glVertex2f(x, y);
	glVertex2f(x, y + 10);
	glEnd(); //заканчиваем указывать вершины
}

void MyRectangle::drawBig() { //¬се то же самое, только вершины большие
	if (!this->isdrawable) {
		return;
	}

	glColor3f(this->r, this->g, this->b);

	glBegin(GL_POLYGON);
	glVertex2f(x + 18, y + 18);
	glVertex2f(x + 18, y);
	glVertex2f(x, y);
	glVertex2f(x, y + 18);
	glEnd();
}

void MyRectangle::moveDetect() {
	if (this->act && this->isdrawable && this->x < 5 + 100) {
		this->x++;
		glutPostRedisplay();
	}
}