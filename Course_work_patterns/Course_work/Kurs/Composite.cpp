#include "Composite.h"
#include <string>

Composite::Composite() :Figure(0, 0) {
	this->key = 3;
	this->first = 0;
	this->last = 0;
}

Composite::Composite(Figure* f) :Figure(0, 0) {
	f->isChild = true;
	comp.push_back(f);
	first = f;
	last = f;
	this->key = 3;
}

Composite::~Composite() {
	delete[] first, last;
}

void Composite::addToComposite(Figure* f) {
	if (!f->act) {
		return;
	}
	if (comp.empty()) {
		first = f;
	}
	f->isChild = true;
	comp.push_back(f);
	last = f;
	count++;
}

void Composite::addToComposite(Composite c) {
	for (Figure* f : c.comp) {
		if (comp.empty()) {
			first = f;
		}
		f->isChild = true;
		comp.push_back(f);
		last = f;
		count++;
	}
}

void Composite::clearComposite() {
	comp.clear();
	count = 0;
}

void Composite::draw() {
	for (Figure* f : comp) {
		f->draw();
	}
};

void Composite::changeColor() {
	for (Figure* f : comp) {
		f->changeColor();
	}
}

void Composite::moveTop() {
	for (Figure* f : comp) {
		f->moveTop();

	}
}

void Composite::moveBottom() {
	for (Figure* f : comp) {
		f->moveBottom();
	}
}

void Composite::moveLeft() {
	for (Figure* f : comp) {
		f->moveLeft();
	}
}

void Composite::moveDetect() {
	for (Figure* f : comp) {
		f->moveDetect();
	}
}

void Composite::idle() {
	for (Figure* f : comp) {
		f->idle();
	}
}

void Composite::setFirstPosition() {
	for (Figure* f : comp) {
		f->setFirstPosition();
	}
}

void Composite::select() {
	for (Figure* f : comp) {
		f->select();
	}

}

void Composite::changeVisibility() {
	for (Figure* f : comp) {
		f->changeVisibility();
	}
}

void Composite::changeActivityMode(bool val) {
	this->act = !this->act;
	for (Figure* f : comp) {
		f->changeActivityMode(val);
	}
}

Figure* Composite::cloneComposite() {
	Composite* c = new Composite();
	for (Figure* f : comp) {
		c->comp.push_back(f->clone());
	}
	return c;
}

string Composite::serialize() {
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
	for (Figure* f : comp) {
		s.append("\n").append(to_string(f->key)).append(";")
			.append(to_string(f->x)).append(";")
			.append(to_string(f->y)).append(";")
			.append(to_string(f->Xs)).append(";")
			.append(to_string(f->Ys)).append(";")
			.append(to_string(f->r)).append(";")
			.append(to_string(f->g)).append(";")
			.append(to_string(f->b)).append(";")
			.append(to_string(f->act)).append(";")
			.append(to_string(f->isdrawable)).append(";")
			.append(to_string(f->isChild)).append(";");
	}
	return s;
}