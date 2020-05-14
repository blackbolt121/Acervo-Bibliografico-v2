#pragma once
#include "listaIdString.h"
#include "Arbol.h"
using namespace std;
class busquedaLibro
{
public:
	virtual void insertar(libro h, string par);
	list<libro> getLibros(string par);

private:
	Arbol<listaIdString> entrada;
};

