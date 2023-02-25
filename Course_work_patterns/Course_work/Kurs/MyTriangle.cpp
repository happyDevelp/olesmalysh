#include "MyTriangle.h"

MyTriangle::MyTriangle(int X, int Y) :Figure(X, Y) { // X, Y начальна€ позици€ фигуры
	this->key = 1;
}
MyTriangle::MyTriangle(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, bool isChild) : Figure(X, Y,xs,ys, R, G, B, Act, IsDraw, 1, isChild) {

}

void MyTriangle::draw() {
	if (!this->isdrawable) {
		return;
	}
	glColor3f(this->r, this->g, this->b);//присваиваем цвет фигуры RGB
	
	glBegin(GL_POLYGON); //интерпритируем фигуру как многоугольник, и между глЅегин и гл≈нд указываем вершины фигуры
	glVertex2f(x, y); //указываем вершины нашей фигуры 
	glVertex2f(x + 10, y + 10);
	glVertex2f(x + 20, y); 
	
	glEnd(); //заканчиваем указывать вершины
}

void MyTriangle::drawBig() { //¬се то же самое, только вершины большие
	if (!this->isdrawable) {
		return;
	}
	glColor3f(this->r, this->g, this->b);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + 28, y + 18);
	glVertex2f(x + 36, y);
	glEnd();
}
