#include "SceneController.h"
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <iterator>
#include <list>
#include <windows.h>
#include "MyRectangle.h"
#include "MyTriangle.h"
#include "Figure.h"
#include "Serializer.h"
#include "RectangleMaker.h"
#include "TriangleMaker.h"

TriangleMaker trCreator;
RectangleMaker rectCreator;

void activityChanger(list <Figure*> l1, int index) {
	int i = 0;
	SceneController* sc = SceneController::getInstance();
	for (Figure* f : l1) {
		if (i == index) {
			f->changeActivityMode(true);
		}
		else if (!sc->getMultipleSelection()) {
			f->changeActivityMode(false);
		}
		i++;
	}
	sc->setList(l1);
}

//void idle() {
//	list <Figure*> l1 = SceneController::getInstance()->getList();
//	for (Figure* f : l1) {
//		f->idle();
//	}
//}

void draw() {
	SceneController* sc = SceneController::getInstance(); //Singleton
	// we want to draw rectandle
	if (!sc->getShift()) {
		glClear(GL_COLOR_BUFFER_BIT);
	}
	list <Figure*> l1 = sc->getList();
	if (l1.size() && l1.front()->key != 3 && l1.back()->key != 3)
	{
		Figure* first = l1.front();
		Figure* last = l1.back();

		for (Figure* f : l1) {
			if (f == first && first != last) {
				if ((f->x >= last->x && f->x <= last->x + 5 && f->y >= last->y && f->y <= last->y + 5) || (f->x + 10 >= last->x && f->x + 10 <= last->x + 5 && f->y >= last->y && f->y <= last->y + 5) || (f->x + 5 >= last->x && f->x + 5 <= last->x + 5 && f->y + 5 >= last->y && f->y + 5 <= last->y + 5) || (f->x <= last->x && f->x + 10 >= last->x + 5 && f->y >= last->y && f->y <= last->y + 5)) {
					f->drawBig();
				}
				else {
					f->draw();
				}
			}
			else
			{
				f->draw();

			}
		}
	}
	else {
		for (Figure* f : l1) {
			f->draw();
		}
	}
	glutSwapBuffers();
}

void key(int key, int x, int y) {
	SceneController* sc = SceneController::getInstance();
	list <Figure*> l1 = sc->getList();
	bool ishear = 0;
	bool shift = sc->getShift();
	Serializer* s = sc->getSerializer();
	switch (key)
	{
	case GLUT_KEY_LEFT: //���� ������ ������� �����
		for (Figure* f : l1) {
			f->moveLeft();
		}
		break;

	case GLUT_KEY_RIGHT: //���� ������ ������� �����
		for (Figure* f : l1) {
			f->moveDetect();
		}
		break;
	
	case GLUT_KEY_UP: //���� ������ ������� �����
		for (Figure* f : l1) {
			f->moveTop();
		}
		break;
	
	case GLUT_KEY_DOWN: //���� ������ ������� ����
		for (Figure* f : l1) {
			f->moveBottom();
		}
		break;
	//case GLUT_KEY_PAGE_UP://automove on
	//	glutIdleFunc(idle);
	//	glutPostRedisplay();
	//	break;
	//case GLUT_KEY_PAGE_DOWN://automove of
	//	glutIdleFunc(NULL);
	//	glutPostRedisplay();
	//	break;
	case GLUT_KEY_HOME: //�������� ����
		for (Figure* f : l1) {
			f->changeColor();
		}
		glutPostRedisplay();
		break;
	
	case GLUT_KEY_END: // ���|���� ���� 
		sc->setShift(!shift);
		break;
	
	case GLUT_KEY_INSERT: //�������� ���������
		for (Figure* f : l1) {
			f->changeVisibility();
		}
		glutPostRedisplay();
		break;
	
	case GLUT_KEY_F1: //������� ��� ������
		for (Figure* f : l1) {
			f->select();
		}
		break;
	
	case GLUT_KEY_F2: //�������� ��� ������
		sc->clearList();
		glutPostRedisplay();
		break;
	
	case GLUT_KEY_SHIFT_L://������� � �������� ��������� �������� ������
		for (Figure* f : l1) {
			f->setFirstPosition();
		}
		glutPostRedisplay();
		break;
	
	case GLUT_KEY_ALT_L: //�������� ������� �����
		activityChanger(l1, -1);
		glutPostRedisplay();
		break;
	
	//case GLUT_KEY_CTRL_L: //�������� ����� ������
	//	sc->setMultipleSelection(!sc->getMultipleSelection());
	//	break;
	
	case GLUT_KEY_ALT_R: //�������������� ����������
		glutPostRedisplay();
		break;
	
	//case GLUT_KEY_SHIFT_R://setup first group
	//	Figure* t1 = trCreator.factoryMethod(10, 10);
	//	Figure* t2 = trCreator.factoryMethod(30, 20);
	//	Figure* t3 = trCreator.factoryMethod(50, 30);
	//	Figure* t4 = trCreator.factoryMethod(70, 40);
	//	Figure* r1 = rectCreator.factoryMethod(20, 20);
	//	Figure* r2 = rectCreator.factoryMethod(40, 20);
	//	Figure* r3 = rectCreator.factoryMethod(60, 30);
	//	Figure* r4 = rectCreator.factoryMethod(80, 80);
	//	Figure* r5 = rectCreator.factoryMethod(100, 90);
	//	Composite* c = new Composite(t1);
	//	c->addToComposite(t3);
	//	c->addToComposite(r1);
	//	sc->addToList(t2);
	//	sc->addToList(r2);
	//	sc->addToList(c);
	//	sc->addToList(r3);
	//	glutPostRedisplay();
	//	break;
	}
}

void normalKeyHandler(unsigned char key, int x, int y)
{
	SceneController* sc = SceneController::getInstance();
	list <Figure*> l1 = sc->getList();
	Serializer* s = sc->getSerializer();
	if (key == '1') {
		activityChanger(l1, 1);
	}
	else if (key == '2') {
		activityChanger(l1, 2);
	}
	else if (key == '3') {
		activityChanger(l1, 3);
	}
	else if (key == '4') {
		activityChanger(l1, 4);
	}
	else if (key == '5') {
		activityChanger(l1, 5);
	}
	else if (key == '6') {
		activityChanger(l1, 6);
	}
	else if (key == '7') {
		activityChanger(l1, 7);
	}
	else if (key == '8') {
		activityChanger(l1, 8);
	}
	else if (key == '9') {
		activityChanger(l1, 9);
	}
	else if (key == '0') {
		activityChanger(l1, 0);
	}
	else if (key == 'v') { //������� ���������������� ��������
		Figure* t = trCreator.factoryMethod(50, 25);
		Figure* r = rectCreator.factoryMethod(55, 15);
		Composite* c = new Composite(t);
		c->addToComposite(r);
		sc->addToList(c);
		glutPostRedisplay();
	}
	else if (key == 'r') { //�������� �������������
		Figure* r = rectCreator.factoryMethod(10, 25);
		sc->addToList(r);
		glutPostRedisplay();
	}
	else if (key == 't') { //�������� �����������
		Figure* t = trCreator.factoryMethod(25, 26);
		sc->addToList(t);
		glutPostRedisplay();
	}
	else if (key == 'c') { // ���������� �������� ������
		for (Figure* f : l1) {
			if (f->act && f->key != 3) {
				sc->addToList(f->clone());
			}
			else if (f->act) {
				sc->addToList(f->cloneComposite());
			}
		}
		glutPostRedisplay();
	}
	else if (key == 'g') { // ������������� ��������� ������ � ���������� � �������� �� � �����
		Composite* c = new Composite();
		for (Figure* f : l1) {
			if (f->key != 3) {
				c->addToComposite(f->clone());
			}
			else {
				c->addToComposite(f->cloneComposite());
			}
		}
		sc->addToList(c);
		glutPostRedisplay();
	}
	else if (key == 's') { //��������� ����� � ����
		for (Figure* f : l1) {
			s->add(f);
		}
	}
	else if (key == 'u') { //��������� ����� �� �����
		sc->setList(s->restoreFromFile());
		glutPostRedisplay();
	}
	else if (key == 'd') { //������� ��� ���������� �� �����
		s->clearFile();
	}
	else if (key == '-') { //������� ��������� ������
		list<Figure*> l2 = list<Figure*>();
		for (Figure* f : l1) {
			if (!f->act) {
				l2.push_back(f);
			}
			else {
				delete(f);
			}
		}
		sc->setList(l2);
		glutPostRedisplay();
	}

}

SceneController* SceneController::getInstance() {
	if (_inst == 0) {
		_inst = new SceneController();
	}
	return _inst;
}

void SceneController::init(void)
{ /* here I prepare the window for displaying on it */
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 100, 0.0, 50);

}

void SceneController::initMain(int argc, char** argv) {

	setlocale(LC_ALL,  "ru");
	cout << "***����������� ��������� ��� ����������� �����***" << endl <<
		/*" page up - automove on" << endl <<
		" page down - automove off" << endl <<*/
		" home - �������� ����" << endl <<
		" end - ���/���� ����" << endl <<
		" insert - �������� ���������" << endl <<
		" f1 - ������� ��� ������" << endl <<
		" f2 - �������� ���" << endl <<
		" left shift - ������� ��������� ������ � �������� ���������" << endl <<
		" left alt - �������� ������� �����" << endl <<
		/*" right shift - ��������� ��������� ������" << endl <<*/
		" right alt - �������������� ����������\n" << endl <<
		/*" left ctrl - change selection mode" << endl <<*/
		" ***�������� �����***" << endl <<
		" 0-9 ������� ������ �� ����� \t" << endl <<
		" v - �������� ���������������� ��������" << endl <<
		" r - �������� �������������" << endl <<
		" t - �������� �����������" << endl <<
		" c - ���������� �������� ������" << endl <<
		" g - ������������� ��������� ������ � ���������� � �������� �� � �����" << endl <<
		" s - ��������� ����� � ����" << endl <<
		" u - ������������ ����������� �����" << endl <<
		" d - ������� ��� ���������� �� �����" << endl <<
		" - - ������� ��������� ������ " << endl;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 600); //sets the initial window size
	glutCreateWindow("Course work");// creates the window with name line
	init();
	glutDisplayFunc(draw);
	glutKeyboardFunc(normalKeyHandler);
	glutSpecialFunc(key);

	glutMainLoop(); // enters the GLUT event processing loop
}
SceneController* SceneController::_inst = 0;

