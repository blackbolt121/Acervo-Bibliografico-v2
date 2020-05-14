#include "listaIdString.h"
listaIdString::listaIdString(string id)
{
	this->id = id;
}

void listaIdString::insertarLibro(const libro& lib, const string& par)
{
	if (this->id == par) {
		this->s.push_back(lib);
	}
	else {

	}
}
