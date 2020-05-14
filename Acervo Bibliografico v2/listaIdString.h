#pragma once
#include <iostream>
#include <list>
#include "libro.h"
using namespace std;
class listaIdString {
public:
	listaIdString(string id);
	listaIdString() {};
	list<libro> getLista();
	void insertarLibro(const libro& s, const string& par);
private:
	string id;
	list<libro> s;
	friend bool operator == (const listaIdString& a, const listaIdString& b);
	friend bool operator < (const listaIdString& a, const listaIdString& b);
	friend bool operator > (const listaIdString& a, const listaIdString& b);
};