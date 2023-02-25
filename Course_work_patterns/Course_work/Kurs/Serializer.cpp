#include "Serializer.h"
#include <fstream>
#include <iostream>
#include "MyRectangle.h"
#include "MyTriangle.h"
#include "Composite.h"
#include "TriangleMaker.h"
#include "RectangleMaker.h"
using namespace std;

string getNextToken(string s, int& start) {
	int end = start;
	for (int i = start; i < s.length(); i++) {
		if (s[i] == ';') {

			string res = s.substr(start, i - start);
			start = i;
			return res;

		}

	}
}

void Serializer::add(Figure* value)
{
	this->file.open(this->path, fstream::app);
	file << value->serialize() << endl;
	this->file.close();
}

list<Figure*> Serializer::restoreFromFile()
{
	file.open(this->path);
	list<string> s = list<string>();
	string currentS;
	while (getline(file, currentS))
	{
		s.push_back(currentS);
	}
	list<Figure*> result = deserialize(s);
	file.close();
	return result;
}

Serializer::Serializer(string path)
{
	this->path = path;
}

void Serializer::clearFile() {
	file.open(this->path, fstream::out | fstream::trunc);
	file.close();
}

list<Figure*> Serializer::deserialize(list<string> s) {
	TriangleMaker trCreator;
	RectangleMaker rectCreator;
	list<Figure*> l1 = list<Figure*>();
	for (string str : s) {
		int i = 0;

		int k = stoi(getNextToken(str, i));
		int x = stoi(getNextToken(str, ++i));
		int y = stoi(getNextToken(str, ++i));
		int xs = stoi(getNextToken(str, ++i));
		int ys = stoi(getNextToken(str, ++i));
		float r = stof(getNextToken(str, ++i));
		float g = stof(getNextToken(str, ++i));
		float b = stof(getNextToken(str, ++i));
		bool act = stoi(getNextToken(str, ++i));
		bool isdraw = stoi(getNextToken(str, ++i));
		bool isChild = stoi(getNextToken(str, ++i));



		switch (k)
		{
		case 1:
			if (!isChild) {
				l1.push_back(trCreator.factoryMethod(x, y, xs, ys, r, g, b, act, isdraw, isChild));
			}
			else {
				l1.back()->addToComposite(trCreator.factoryMethod(x, y, xs, ys, r, g, b, act, isdraw, isChild));
			}
			break;
		case 2:
			if (!isChild) {
				l1.push_back(rectCreator.factoryMethod(x, y, xs, ys, r, g, b, act, isdraw, isChild));
			}
			else {
				l1.back()->addToComposite(rectCreator.factoryMethod(x, y, xs, ys, r, g, b, act, isdraw, isChild));
			}
			break;
		case 3:
			l1.push_back(new Composite());
			break;
		}
	}
	return l1;
}

