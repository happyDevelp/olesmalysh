#include "MyTriangle.h"

MyTriangle::MyTriangle(int X, int Y) :Figure(X, Y) { // X, Y ��������� ������� ������
	this->key = 1;
}
MyTriangle::MyTriangle(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool IsDraw, bool isChild) : Figure(X, Y,xs,ys, R, G, B, Act, IsDraw, 1, isChild) {

}

void MyTriangle::draw() {
	if (!this->isdrawable) {
		return;
	}
	glColor3f(this->r, this->g, this->b);//����������� ���� ������ RGB
	
	glBegin(GL_POLYGON); //�������������� ������ ��� �������������, � ����� ������� � ����� ��������� ������� ������
	glVertex2f(x, y); //��������� ������� ����� ������ 
	glVertex2f(x + 10, y + 10);
	glVertex2f(x + 20, y); 
	
	glEnd(); //����������� ��������� �������
}

void MyTriangle::drawBig() { //��� �� �� �����, ������ ������� �������
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
