#pragma once
#include <iostream>
#include <list>
#include "libro.h"
using namespace std;
class listaIdString {
public:
	listaIdString(string id);
private:
	string id;
	list<libro> s;
	void insertarLibro(const libro& s, const string& par);
};