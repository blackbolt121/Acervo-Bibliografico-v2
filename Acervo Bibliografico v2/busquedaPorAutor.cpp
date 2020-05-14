#include "busquedaPorAutor.h"

void busquedaPorAutor::insertar(libro h, string par)
{
	string par = h.getAutor();
	busquedaLibro::insertar(h, par);
}


