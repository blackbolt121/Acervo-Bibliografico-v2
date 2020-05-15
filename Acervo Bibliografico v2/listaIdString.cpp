#include "listaIdString.h"
listaIdString::listaIdString(string id)
{
	this->id = id;
}

list<libro> listaIdString::getLista()
{
	return this->s;
}

void listaIdString::insertarLibro(const libro& lib, const string& par)
{
	if (this->id == par) {
		this->s.push_back(lib);
	}
	else {

	}
}

bool operator==(const listaIdString& a, const listaIdString& b)
{
	if (a.id == b.id)
		return true;
	else
		return false;
}

bool operator<(const listaIdString& a, const listaIdString& b)
{
	if (a.id < b.id)
		return true;
	else
		return false;
}

bool operator>(const listaIdString& a, const listaIdString& b)
{
	if (a.id > b.id)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, const listaIdString& a)
{
	out << a.id;
	return out;
	// TODO: Insertar una instrucción "return" aquí
}
