#include "MyRectangle.h"

MyRectangle::MyRectangle(int X, int Y) :Figure(X, Y) { // X, Y ��������� ������� ������
	this->key = 2;
}

MyRectangle::MyRectangle(int X, int Y, int xs, int ys, float R, float G, float B, bool Act, bool isDraw, bool isChild) : Figure(X, Y, xs, ys, R, G, B, Act, isDraw, 2, isChild) {

}

void MyRectangle::draw() {
	if (!this->isdrawable) {
		return;
	}
	
	glColor3f(this->r, this->g, this->b); //����������� ���� ������ RGB
	
	glBegin(GL_POLYGON); //�������������� ������ ��� �������������, � ����� ������� � ����� ��������� ������� ������
	glVertex2f(x + 10, y + 10);	//��������� ������� ����� ������ (����� ����, ���������� ������ �������)
	glVertex2f(x + 10, y);
	glVertex2f(x, y);
	glVertex2f(x, y + 10);
	glEnd(); //����������� ��������� �������
}

void MyRectangle::drawBig() { //��� �� �� �����, ������ ������� �������
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