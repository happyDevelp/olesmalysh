//#include "Composite.h"
//#include <string>
//
//Vector::Vector() :Figure(0, 0) {
//	this->key = 3;
//	this->first = 0;
//	this->last = 0;
//}
//
//Vector::Vector(Figure* f) :Figure(0, 0) {
//	f->isChild = true;
//	vect.push_back(f);
//	first = f;
//	last = f;
//	this->key = 3;
//}
//
//Vector::~Vector() {
//	delete[] first, last;
//}
//
//void Vector::addToVector(Figure* f) {
//	if (!f->act) {
//		return;
//	}
//	if (vect.empty()) {
//		first = f;
//	}
//	f->isChild = true;
//	vect.push_back(f);
//	last = f;
//	count++;
//}
//
//void Vector::addVToVector(Vector v) {
//	for (Figure* f : v.vect) {
//		if (vect.empty()) {
//			first = f;
//		}
//		f->isChild = true;
//		vect.push_back(f);
//		last = f;
//		count++;
//	}
//}
//
//void Vector::clearVector() {
//	vect.clear();
//	count = 0;
//}
//
//void Vector::draw() {
//	for (Figure* f : vect) {
//		f->draw();
//	}
//};
//
//void Vector::changeColor() {
//	for (Figure* f : vect) {
//		f->changeColor();
//	}
//}
//
//void Vector::moveTop() {
//	for (Figure* f : vect) {
//		f->moveTop();
//
//	}
//}
//
//void Vector::moveBottom() {
//	for (Figure* f : vect) {
//		f->moveBottom();
//	}
//}
//
//void Vector::moveLeft() {
//	for (Figure* f : vect) {
//		f->moveLeft();
//	}
//}
//
//void Vector::moveDetect() {
//	for (Figure* f : vect) {
//		f->moveDetect();
//	}
//}
//
//void Vector::idle() {
//	for (Figure* f : vect) {
//		f->idle();
//	}
//}
//
//void Vector::setFirstPosition() {
//	for (Figure* f : vect) {
//		f->setFirstPosition();
//	}
//}
//
//void Vector::select() {
//	for (Figure* f : vect) {
//		f->select();
//	}
//
//}
//
//void Vector::changeVisibility() {
//	for (Figure* f : vect) {
//		f->changeVisibility();
//	}
//}
//
//void Vector::changeActivityMode(bool val) {
//	this->act = !this->act;
//	for (Figure* f : vect) {
//		f->changeActivityMode(val);
//	}
//}
//
//Figure* Vector::cloneVector() {
//	Vector* v = new Vector();
//	for (Figure* f : vect) {
//		v->vect.push_back(f->clone());
//	}
//	return v;
//}
//
//string Vector::serialize() {
//	string s = to_string(key).append(";")
//		.append(to_string(x)).append(";")
//		.append(to_string(y)).append(";")
//		.append(to_string(Xs)).append(";")
//		.append(to_string(Ys)).append(";")
//		.append(to_string(r)).append(";")
//		.append(to_string(g)).append(";")
//		.append(to_string(b)).append(";")
//		.append(to_string(act)).append(";")
//		.append(to_string(isdrawable)).append(";")
//		.append(to_string(isChild)).append(";");
//	for (Figure* f : vect) {
//		s.append("\n").append(to_string(f->key)).append(";")
//			.append(to_string(f->x)).append(";")
//			.append(to_string(f->y)).append(";")
//			.append(to_string(f->Xs)).append(";")
//			.append(to_string(f->Ys)).append(";")
//			.append(to_string(f->r)).append(";")
//			.append(to_string(f->g)).append(";")
//			.append(to_string(f->b)).append(";")
//			.append(to_string(f->act)).append(";")
//			.append(to_string(f->isdrawable)).append(";")
//			.append(to_string(f->isChild)).append(";");
//	}
//	return s;
//}