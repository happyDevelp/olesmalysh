#pragma once
#include <string>
#include <fstream>
#include "Figure.h"
#include <list>

class Serializer
{
public:
	void add(Figure*);
	void clearFile();
	list<Figure*> restoreFromFile();
	Serializer(string);
	list<Figure*> deserialize(list<string>);
private:
	string path;
	fstream file;
};
