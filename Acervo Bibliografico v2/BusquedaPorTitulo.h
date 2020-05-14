#pragma once
#include "listaIdString.h"
#include "Arbol.h"
using namespace std;
class BusquedaPorTitulo
{
public:
	void insertar(libro h);
	list<libro> getLibros(string titulo);

private:
	Arbol<listaIdString> entrada;
};

