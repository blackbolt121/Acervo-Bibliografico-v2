#pragma once
#include <fstream>
#include <string>
#include "busquedaPorAutor.h"
#include "busquedaPorEspecialidad.h"
#include "BusquedaPorTitulo.h"
using namespace std;
namespace menu {
	
	void iniciar(busquedaLibro &a, busquedaPorAutor &b, busquedaPorEspecialidad &c, BusquedaPorTitulo &d);
	void imprimirPosiblesBusquedas(int op, busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d);
	void buscar(const string& e, int i, busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d);
	void run(busquedaLibro& a, busquedaPorAutor& b, busquedaPorEspecialidad& c, BusquedaPorTitulo& d, bool init = true);
}

